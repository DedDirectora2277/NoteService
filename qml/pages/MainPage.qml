import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All
    backgroundColor: "#0A0A21"

    Column {
        width: parent.width
        spacing: Theme.paddingLarge

        PageHeader {
            objectName: "pageHeader"
            title: qsTr("Заметки")
            extraContent.children: [
                IconButton {
                    objectName: "aboutButton"
                    icon.source: "image://theme/icon-m-about"
                    anchors.verticalCenter: parent.verticalCenter

                    onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
                }
            ]
        }

        Rectangle {
            id: note1
            width: parent.width - 64
            color: "#0D1724"
            height: 120
            anchors.horizontalCenter: parent.horizontalCenter
            border.color: '#3d454f'
            radius: 12

            Column {
                anchors.centerIn: parent
                width: parent.width - 48
                height: parent.height - 48
                spacing: Theme.paddingMedium

                Text {
                    id: title1
                    text: qsTr("Важная информация о Аврора")
                    color: 'white'
                }
            }
        }

        Rectangle {
            id: note2
            width: parent.width - 64
            color: "#0D1724"
            height: 120
            anchors.horizontalCenter: parent.horizontalCenter
            border.color: '#3d454f'
            radius: 12

            Column {
                anchors.centerIn: parent
                width: parent.width - 48
                height: parent.height - 48
                spacing: Theme.paddingMedium

                Text {
                    id: title2
                    text: qsTr("Важная информация о Аврора")
                    color: 'white'
                }
            }
        }
    }


}
