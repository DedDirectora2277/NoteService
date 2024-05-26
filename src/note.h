#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QDate>

class Note : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QDate modificationDate READ modificationDate WRITE setModificationDate NOTIFY modificationDateChanged)
    Q_PROPERTY(QDate creationDate READ creationDate WRITE setCreationDate NOTIFY creationDateChanged)
    Q_PROPERTY(QString id READ id WRITE setId)

public:
    explicit Note(QObject *parent = nullptr);

    QString text() const;
        void setText(const QString &text);

    QString title() const;
    void setTitle(const QString &title);

    QColor color() const;
    void setColor(const QColor &color);

    QDate modificationDate() const;
    void setModificationDate(const QDate &modificationDate);

    QDate creationDate() const;
    void setCreationDate(const QDate &creationDate);

    QString id() const;
    void setId(QString id);

signals:
    void titleChanged();
    void textChanged();
    void colorChanged();
    void modificationDateChanged();
    void creationDateChanged();

private:
    QString m_title;
    QString m_text;
    QColor m_color;
    QDate m_creationDate;
    QDate m_modificationDate;
    QString m_id;
};

#endif // NOTE_H
