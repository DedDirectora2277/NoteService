TARGET = ru.auroraos.AuroraNotes

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \
    src/note.cpp \
    src/notelist.cpp

HEADERS += \
    src/note.h \
    src/notelist.h

DISTFILES += \
    qml/NoteListView.qml \
    rpm/ru.auroraos.AuroraNotes.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.auroraos.AuroraNotes.ts \
    translations/ru.auroraos.AuroraNotes-ru.ts \

QT += sql
QT += network
