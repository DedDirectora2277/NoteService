import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All

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
            height: Theme.itemSizeLarge
            anchors.horizontalCenter: parent.horizontalCenter
            radius: Theme.paddingSmall

            Column {
                anchors.centerIn: parent
                width: parent.width - 48
                height: parent.height - 48
                spacing: Theme.paddingMedium

                Text {
                    id: title1
                    text: qsTr("Важная информация о Аврора")
                }

                Text {
                    id: time1
                    width: parent.width
                    text: qsTr("10:46")
                    font.pointSize: Theme.fontSizeTinyBase
                    horizontalAlignment: Text.AlignRight
                    color: Theme.darkSecondaryColor
                }
            }
        }

        Rectangle {
            id: note2
            width: parent.width - 64
            height: Theme.itemSizeLarge
            anchors.horizontalCenter: parent.horizontalCenter
            radius: Theme.paddingSmall

            Column {
                anchors.centerIn: parent
                width: parent.width - 48
                height: parent.height - 48
                spacing: Theme.paddingMedium

                Text {
                    id: title2
                    text: qsTr("Важная информация о Аврора")
                }

                Text {
                    id: time2
                    width: parent.width
                    text: qsTr("18.05.2024")
                    font.pointSize: Theme.fontSizeTinyBase
                    horizontalAlignment: Text.AlignRight
                    color: Theme.darkSecondaryColor
                }
            }
        }
    }

    Item {
        property real basePosX: (createNoteButton.width / 2) - (createNoteButtonIcon.width / 2)
        property real basePosY: (createNoteButton.height / 2) - (createNoteButtonIcon.height / 2)
        property real currentPosX: (createNoteButton.width / 2) - (createNoteButtonIcon.width / 2)
        property real currentPosY: (createNoteButton.height / 2) - (createNoteButtonIcon.height / 2)

        id: createNoteButton
        x: parent.width - 126
        y: parent.height - 126

        Rectangle {
            id: createNoteButtonIcon
            x: basePosX
            y: basePosY
            width: Theme.itemSizeSmall
            height: Theme.itemSizeSmall
            radius: width * 0.5
            antialiasing: true
            smooth: true
        }

        Rectangle {
            id: createNoteButtonIconBar1
            anchors.centerIn: createNoteButtonIcon
            width: Theme.iconSizeExtraSmall
            height: 4
            antialiasing: true
            color: 'black'
        }

        Rectangle {
            id: createNoteButtonIconBar2
            anchors.centerIn: createNoteButtonIcon
            width: Theme.iconSizeExtraSmall
            height: 4
            antialiasing: true
            rotation: 90
            color: 'black'
        }

        MouseArea {
            id: createNoteArea
            anchors.fill: createNoteButtonIcon
            onClicked: pageStack.push(Qt.resolvedUrl("NoteEditor.qml"))

        }
    }
}
