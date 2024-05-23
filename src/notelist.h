#ifndef NOTELIST_H
#define NOTELIST_H

#include <QAbstractListModel>
#include "note.h"

class NoteList:public QAbstractListModel
{
    Q_OBJECT


public:
    enum NoteRoles {
        TitleRole,
        TextRole,
        ColorRole,
        CreationDateRole,
        ModificationDateRole,
        NoteRole,
    };

    NoteList(QObject *parent = nullptr);

    // Методы для работы с данными
    Q_INVOKABLE Note* addNote(const QString &title, const QString &text, const QColor &color);
    Q_INVOKABLE void removeNote(int index);
    Q_INVOKABLE void updateNote(Note* note);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:
    void noteRemoved(int index);

private:
    QList<Note*> m_notes;
};

#endif // NOTELIST_H
