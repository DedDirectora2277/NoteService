#ifndef NOTELIST_H
#define NOTELIST_H

#include <QAbstractListModel>
#include "note.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class NoteList:public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged)
    Q_PROPERTY(QColor filterColor READ filterColor WRITE setFilterColor NOTIFY filterColorChanged)

public:
    enum NoteRoles {
        TitleRole,
        TextRole,
        ColorRole,
        CreationDateRole,
        ModificationDateRole,
        NoteRole,
        IdRole,
    };

    NoteList(QObject *parent = nullptr);

    // Методы для работы с данными
    Q_INVOKABLE Note* addNote(const QString &title, const QString &text, const QColor &color);
    Q_INVOKABLE void removeNote(int index);
    Q_INVOKABLE void updateNote(Note* note);
    Q_INVOKABLE void clearFilterColor();
    Q_INVOKABLE void exportNoteToTxt(Note *note, const QString &filePath);
    Q_INVOKABLE void importNoteFromTxt(const QString &filePath);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    QString filterText() const;
    void setFilterText(const QString &filterText);

    QColor filterColor() const;
    void setFilterColor(const QColor &filterColor);

    void loadNotes();
    void saveNoteToDatabase(Note *note);
    void removeNoteFromDatabase(QString id);
    void updateNoteInDatabase(Note *note);
    void createTxtFromNote(const QString &filePath, Note *note);

    Note* parseNoteFromTxt(const QString &filePath);


signals:
    void noteRemoved(int index);
    void filterTextChanged();
    void filterColorChanged();


private:
    QList<Note*> m_notes;
    QList<Note*> m_filteredNotes;
    QString m_filterText;
    QColor m_filterColor;

    void applyFilter();

};

#endif // NOTELIST_H
