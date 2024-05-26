#include "note.h"

Note::Note(QObject *parent) : QObject(parent), m_id(-1)
{

}


QString Note::text() const
{
    return m_text;
}

void Note::setText(const QString &text)
{
    if (text != m_text) {
        m_text = text;
        emit textChanged();
    }
}

QString Note::title() const
{
    return m_title;
}


void Note::setTitle(const QString &title)
{
    if (title != m_title) {
        m_title = title;
        emit titleChanged();
    }
}

QColor Note::color() const
{
    return m_color;
}

void Note::setColor(const QColor &color)
{
    if (color != m_color) {
        m_color = color;
        emit colorChanged();
    }
}

QDate Note::modificationDate() const
{
    return m_modificationDate;
}

void Note::setModificationDate(const QDate &date)
{
    if (date != m_modificationDate) {
        m_modificationDate = date;
        emit modificationDateChanged();
    }
}

QDate Note::creationDate() const
{
    return m_creationDate;
}

void Note::setCreationDate(const QDate &date)
{
    if (date != m_creationDate) {
        m_creationDate = date;
        emit creationDateChanged();
    }
}

QString Note::id() const
{
    return m_id;
}

void Note::setId(QString id)
{
    if (m_id != id) {
        m_id = id;
    }
}
