import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: noteItem
    width: parent.width
    height: Theme.itemSizeLarge
    Column {
        id: content
        width: parent.width
        spacing: Theme.paddingLarge

        Item {
            id: titleContainer



            Text {
                anchors.left: parent.left

                text: model.title
                font.pixelSize: Theme.fontSizeLarge
                color: "black"
            }

            Rectangle {
                id: colorIndicator

                width: Theme.iconSizeMedium
                height: Theme.iconSizeMedium
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter

                color: model.color
                radius: colorIndicator.width/2
            }

        }


        Label {
            text: qsTr("Created: ") + model.creationDate.toLocaleString(Qt.DefaultLocaleShortDate)
            font.pixelSize: Theme.fontSizeMedium
        }
        Label {
            text: qsTr("Modified: ") + model.modificationDate.toLocaleString(Qt.DefaultLocaleShortDate)
            font.pixelSize: Theme.fontSizeMedium
        }
    }

}
