import QtQuick 2.0
import Sailfish.Silica 1.0

SilicaListView {
    id: notesList
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: headerColumn.bottom
    anchors.bottom: addNoteButton.top
    clip: true

    delegate: ListItem {
        id: clickArea
        property bool isLongPress: false
        property int pressDuration: 300
        property bool contextMenuVisible: false

        Label {
            id: noteTitle
            anchors.left: parent.left
            width: parent.width / 2
            anchors.leftMargin: Theme.horizontalPageMargin
            anchors.verticalCenter: parent.verticalCenter
            text: model.title
            truncationMode: TruncationMode.Elide
        }

        Rectangle {
            id: colorIndicator
            width: Theme.iconSizeMedium
            height: Theme.iconSizeMedium
            anchors.right: parent.right
            anchors.rightMargin: Theme.horizontalPageMargin
            anchors.verticalCenter: parent.verticalCenter
            radius: width / 2
            border {
                width: 3
                color: Theme.secondaryHighlightColor
            }
            color: model.color
        }

        Timer {
            id: pressTimer
            interval: clickArea.pressDuration
            onTriggered: {
                clickArea.isLongPress = true
                contextMenuVisible = true
                contextMenu.open()
            }
        }

        onPressed: {
            clickArea.isLongPress = false
            pressTimer.start()
        }

        onReleased: {
            if (pressTimer.running) {
                pressTimer.stop()
            }
            if (!clickArea.isLongPress) {
                var noteObject = model.note
                var editPage = noteEditorPageComponent.createObject(pageStack, { "note": noteObject })
                pageStack.push(editPage)
            } else {
                clickArea.isLongPress = false
                contextMenuVisible = false
            }
        }

        onPositionChanged: {
            if (pressTimer.running) {
                pressTimer.stop()
            }
        }

        menu: ContextMenu {
            id: contextMenu
            active: contextMenuVisible

            MenuItem {
                text: qsTr("Удалить")
                onClicked: {
                    noteList.removeNote(index)
                    contextMenuVisible = false
                }
            }

            onClosed: {
                contextMenuVisible = false
                clickArea.isLongPress = false
            }
        }
    }

    VerticalScrollDecorator {}
}
