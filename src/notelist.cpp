#include "notelist.h"

NoteList::NoteList(QObject *parent) : QAbstractListModel(parent), m_filterColor(Qt::transparent)
{
    m_filterText = "";
}

Note* NoteList::addNote(const QString &title, const QString &text, const QColor &color)
{
    Note *note = new Note(this);
    note->setId(m_notes.count() + 1);
    note->setTitle(title);
    note->setText(text);
    note->setColor(color);
    note->setCreationDate(QDate::currentDate());
    note->setModificationDate(QDate::currentDate());

    connect(note, &Note::titleChanged, this, [this, note]() { updateNote(note); });
    connect(note, &Note::textChanged, this, [this, note]() { updateNote(note); });
    connect(note, &Note::colorChanged, this, [this, note]() { updateNote(note); });
    connect(note, &Note::modificationDateChanged, this, [this, note]() { updateNote(note); });

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_notes.append(note);
    endInsertRows();

    applyFilter();
    return note;
}

void NoteList::removeNote(int index)
{
    if (index >= 0 && index < m_notes.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        delete m_notes.at(index);
        m_notes.removeAt(index);
        endRemoveRows();
        applyFilter();
        emit noteRemoved(index);
    }
}

void NoteList::updateNote(Note *note)
{
    int index = m_notes.indexOf(note);
    if (index >= 0) {
        note->setModificationDate(QDateTime::currentDateTime().date());
        QModelIndex modelIndex = createIndex(index, 0);
        emit dataChanged(modelIndex, modelIndex, {TitleRole, TextRole, ColorRole, ModificationDateRole});
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
