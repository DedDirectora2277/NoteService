import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: root
    objectName: "noteEditor"
    allowedOrientations: Orientation.All


    Column {
        id:mainColumn

        width: parent.width
        height: header.height + noteTitle.height
        spacing: Theme.paddingLarge

        anchors.top: parent.top

        PageHeader {
            id: header
            objectName: "pageHeader"

            extraContent.children: [
                IconButton{ //Кнопка назад
                    id: backButton
                    objectName: "backButton"
                    icon.source: "image://theme/icon-m-back"
                    anchors.left: parent.left

                    onClicked: pageStack.push(Qt.resolvedUrl("MainPage.qml"))
                },

                Rectangle{
                    id: colorIndicator
                    objectName: "ColorIndicator"

                    color: "teal"

                    width: Theme.iconSizeMedium
                    height: Theme.iconSizeMedium
                    anchors.left: backButton.right

                    radius: colorIndicator.width/2

                    MouseArea{
                        id: selectorButton

                        anchors.fill: parent

                        onClicked: {
                            var dialog = pageStack.push("Sailfish.Silica.ColorPickerDialog")
                            dialog.accepted.connect(function() {
                                colorIndicator.color = dialog.color
                            })
                        }
                    }

                },

                IconButton { //Кнопка для вставки изображения
                    id: imageButton
                    objectName: "insertImageButton"
                    icon.source: "image://theme/icon-m-file-image"


                    anchors.right: saveButton.left

                },
                IconButton{
                    id: saveButton
                    objectName: "saveButton"
                    icon.source: "image://theme/icon-m-save"


                    anchors.right: parent.right
                }

            ]
        }


        TextField {
            id: noteTitle
            objectName: "noteTitle"

            width: parent.width
            anchors.leftMargin: Theme.horizontalPageMargin

            font.pixelSize: Theme.fontSizeLarge

            placeholderText: qsTr("Название заметки")
            readOnly: false
            inputMethodHints: Qt.ImhNone
        }
    }

    SilicaFlickable {
        id: noteTextContainer
        objectName: "noteTextContainer"

        width: parent.width
        height: parent.height - noteTitle.height - header.height

        contentHeight: noteText.height + insertedImage.height + 3 * Theme.paddingMedium + dateLabel.height
        contentWidth: noteText.width

        anchors.leftMargin: Theme.horizontalPageMargin
        anchors.bottom: parent.bottom


        interactive: true
        clip: true

        Column {
            width: parent.width

            spacing: Theme.paddingMedium

            TextArea {
                id: noteText
                objectName: "noteText"

                width: parent.width

                font.pixelSize: Theme.fontSizeMedium

                placeholderText: qsTr("Здесь начинается ваша заметка")
                readOnly: false
                inputMethodHints: Qt.ImhNone
                wrapMode: TextEdit.Wrap
            }

            Image {
                id: insertedImage
                objectName: "insertedImage"
                source: ""
                width: parent.width
                fillMode: Image.PreserveAspectFit
                visible: source !== ""
            }

            Label {
                id: dateLabel
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Date of creation: 21.12.2024")
                font.pixelSize: Theme.fontSizeSmall
            }

        }



        VerticalScrollDecorator {}
    }


}
