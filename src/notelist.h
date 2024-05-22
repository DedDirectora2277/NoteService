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
        CreationDate,
        ModificationDate,
    };

    NoteList(QObject *parent = nullptr);

    // Методы для работы с данными
    Q_INVOKABLE void addNote(const QString &title, const QString &text, const QColor &color);
    Q_INVOKABLE void removeNote(int index);
    Q_INVOKABLE void updateNote(int index, const QString &title, const QString &text, const QColor &color);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Note*> m_notes;
};

#endif // NOTELIST_H
