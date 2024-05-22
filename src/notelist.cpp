#include "notelist.h"

NoteList::NoteList(QObject *parent) : QAbstractListModel(parent)
{

}

void NoteList::addNote(const QString &title, const QString &text, const QColor &color)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    Note *note = new Note(this);
    note->setId(m_notes.count() + 1);
    note->setTitle(title);
    note->setText(text);
    note->setColor(color);
    note->setCreationDate(QDate::currentDate());
    note->setModificationDate(QDate::currentDate());
    m_notes.append(note);
    endInsertRows();
}

void NoteList::removeNote(int index)
{
    if (index >= 0 && index < m_notes.count()) {
        beginRemoveRows(QModelIndex(), index, index);
        Note *note = m_notes.takeAt(index);
        delete note;
        endRemoveRows();
    }
}

void NoteList::updateNote(int index, const QString &title, const QString &text, const QColor &color)
{
    if (index >= 0 && index < m_notes.count()) {
        Note *note = m_notes.at(index);
        note->setTitle(title);
        note->setText(text);
        note->setColor(color);
        note->setModificationDate(QDate::currentDate());
        QModelIndex modelIndex = createIndex(index, index);
        emit dataChanged(modelIndex, modelIndex, {TitleRole, TextRole, ColorRole});
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
    roles[CreationDate] = "creationDate";
    roles[ModificationDate] = "modificationDate";
    return roles;
}
