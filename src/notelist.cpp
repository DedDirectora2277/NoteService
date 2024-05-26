#include "notelist.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QStandardPaths>
#include <QUuid>
#include <QDir>

NoteList::NoteList(QObject *parent)
    : QAbstractListModel(parent), m_filterColor(Qt::transparent)
{
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataLocation);
    if (!dir.exists()) {
        if (!dir.mkpath(appDataLocation)) {
            qWarning() << "Error: unable to create directory" << appDataLocation;
            return;
        }
    }

    QString dbPath = appDataLocation + "/notes.db";
    qDebug() << "Database path:" << dbPath;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qWarning() << "Error: unable to open database" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS notes (id TEXT PRIMARY KEY, title TEXT, text TEXT, color TEXT, creation_date TEXT, modification_date TEXT)");
        loadNotes();
    }
}

void NoteList::loadNotes() {
    QSqlQuery query("SELECT id, title, text, color, creation_date, modification_date FROM notes");
    while (query.next()) {
        Note *note = new Note(this);
        note->setId(query.value(0).toString());
        note->setTitle(query.value(1).toString());
        note->setText(query.value(2).toString());
        note->setColor(QColor(query.value(3).toString()));
        note->setCreationDate(QDate::fromString(query.value(4).toString(), Qt::ISODate));
        note->setModificationDate(QDate::fromString(query.value(5).toString(), Qt::ISODate));

        m_notes.append(note);
    }
    applyFilter();
}

Note* NoteList::addNote(const QString &title, const QString &text, const QColor &color)
{
    Note *note = new Note(this);
    QString uuid = QUuid::createUuid().toString();
    note->setId(uuid);
    note->setTitle(title);
    note->setText(text);
    note->setColor(color);
    note->setCreationDate(QDate::currentDate());
    note->setModificationDate(QDate::currentDate());

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_notes.append(note);
    endInsertRows();

    saveNoteToDatabase(note);
    applyFilter();
    return note;
}

void NoteList::saveNoteToDatabase(Note *note) {
    QSqlQuery query;
    query.prepare("INSERT INTO notes (id, title, text, color, creation_date, modification_date) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(note->id());
    query.addBindValue(note->title());
    query.addBindValue(note->text());
    query.addBindValue(note->color().name());
    query.addBindValue(note->creationDate().toString(Qt::ISODate));
    query.addBindValue(note->modificationDate().toString(Qt::ISODate));
    if (!query.exec()) {
        qWarning() << "Error: failed to insert note" << query.lastError().text();
    }
}

void NoteList::removeNote(int index) {
    if (index < 0 || index >= m_notes.size())
        return;

    Note *note = m_notes.at(index);
    beginRemoveRows(QModelIndex(), index, index);
    m_notes.removeAt(index);
    endRemoveRows();

    removeNoteFromDatabase(note->id());
    delete note;
}

void NoteList::removeNoteFromDatabase(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM notes WHERE id = ?");
    query.addBindValue(id);
    if (!query.exec()) {
        qWarning() << "Error: failed to delete note" << query.lastError().text();
    }
}

void NoteList::updateNote(Note *note)
{
    int index = m_notes.indexOf(note);
    if (index >= 0) {
        note->setModificationDate(QDateTime::currentDateTime().date());
        QModelIndex modelIndex = createIndex(index, 0);
        updateNoteInDatabase(note);

        emit dataChanged(modelIndex, modelIndex, {TitleRole, TextRole, ColorRole, ModificationDateRole});
        applyFilter();
    }
}

void NoteList::updateNoteInDatabase(Note *note) {
    QSqlQuery query;
    query.prepare("UPDATE notes SET title = ?, text = ?, color = ?, modification_date = ? WHERE id = ?");
    query.addBindValue(note->title());
    query.addBindValue(note->text());
    query.addBindValue(note->color().name());
    query.addBindValue(note->modificationDate().toString(Qt::ISODate));
    query.addBindValue(note->id());
    if (!query.exec()) {
        qWarning() << "Error: failed to update note" << query.lastError().text();
    }
}

int NoteList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_filteredNotes.count();
}

QVariant NoteList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_filteredNotes.count())
        return QVariant();

    Note *note = m_filteredNotes.at(index.row());
    switch (role) {
    case TitleRole:
        return note->title();
    case TextRole:
        return note->text();
    case ColorRole:
        return note->color();
    case CreationDateRole:
        return note->creationDate();
    case ModificationDateRole:
        return note->modificationDate();
    case NoteRole:
        return QVariant::fromValue(note);
    case IdRole:
        return note->id();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> NoteList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[TextRole] = "text";
    roles[ColorRole] = "color";
    roles[CreationDateRole] = "creationDate";
    roles[ModificationDateRole] = "modificationDate";
    roles[NoteRole] = "note";
    roles[IdRole] = "id";
    return roles;
}


QString NoteList::filterText() const
{
    return m_filterText;
}

void NoteList::setFilterText(const QString &filterText)
{
    if (m_filterText != filterText) {
        m_filterText = filterText;
        emit filterTextChanged();
        applyFilter();
    }
}

QColor NoteList::filterColor() const
{
    return m_filterColor;
}

void NoteList::setFilterColor(const QColor &filterColor)
{
    if (m_filterColor != filterColor) {
        m_filterColor = filterColor;
        emit filterColorChanged();
        applyFilter();
    }
}

void NoteList::clearFilterColor()
{
    m_filterColor = Qt::transparent;
    emit filterColorChanged();
    applyFilter();
}

void NoteList::applyFilter()
{
    beginResetModel();
    m_filteredNotes.clear();

    const QList<Note*>& constNotes = m_notes; // Явное преобразование к const ссылке
    for (const Note* note : constNotes) {
        bool matchesText = m_filterText.isEmpty() || note->title().contains(m_filterText, Qt::CaseInsensitive);
        bool matchesColor = m_filterColor == Qt::transparent || note->color() == m_filterColor;

        if (matchesText && matchesColor) {
            m_filteredNotes.append(const_cast<Note*>(note));
        }
    }

    endResetModel();
    emit dataChanged(index(0), index(m_filteredNotes.count() - 1));
}

void NoteList::exportNoteToTxt(Note *note, const QString &filePath)
{
    if (!note) {
        qWarning() << "Note is null";
        return;
    }

    if (filePath.isEmpty()) {
        return;
    }

    QString file = filePath;
    if (!file.endsWith(".txt", Qt::CaseInsensitive)) {
        file += ".txt";
    }

    createTxtFromNote(file, note);
}

void NoteList::createTxtFromNote(const QString &filePath, Note *note)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for writing:" << filePath;
        return;
    }

    QTextStream out(&file);

    // Записываем заголовок
    out << note->title() << "\n\n";

    // Записываем текст заметки
    out << note->text() << "\n";

    file.close();
    qDebug() << "TXT file successfully created at" << filePath;
}

Note* NoteList::parseNoteFromTxt(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file for reading:" << filePath;
        return nullptr;
    }

    QTextStream in(&file);
    QString title = in.readLine().trimmed();
    QString text = in.readAll().trimmed();

    Note *note = new Note(this);
    note->setTitle(title);
    note->setText(text);

    file.close();
    return note;
}

void NoteList::importNoteFromTxt(const QString &filePath)
{
    Note *note = parseNoteFromTxt(filePath);
    if (note) {
        addNote(note->title(), note->text(), Qt::transparent);
    } else {
        qWarning() << "Failed to import note from file:" << filePath;
    }
}
