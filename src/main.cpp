#include <auroraapp.h>
#include <QtQuick>

#include "notelist.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("AuroraNotes"));


    qmlRegisterType<NoteList>("Notes", 1, 0, "NoteList");
    qmlRegisterType<Note>("Notes", 1, 0, "Note");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/AuroraNotes.qml")));
    view->show();

    return application->exec();
}
