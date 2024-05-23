#include "notelist.h"

NoteList::NoteList(QObject *parent) : QAbstractListModel(parent)
{

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

    return note;
}

void NoteList::removeNote(int index)
{
    if (index >= 0 && index < m_notes.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        delete m_notes.at(index);
        m_notes.removeAt(index);
        endRemoveRows();
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
    return m_notes.count();
}

QVariant NoteList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_notes.count())
        return QVariant();

    Note *note = m_notes.at(index.row());
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
