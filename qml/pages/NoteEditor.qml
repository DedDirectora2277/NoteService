import QtQuick 2.0
import Sailfish.Silica 1.0
import Notes 1.0


Page {
    id: noteEditorPage
    objectName: "noteEditor"
    allowedOrientations: Orientation.All

    property Note note

//    onNoteChanged: {
//            if (note) {
//                noteTitle.text = note.title
//                noteText.text = note.text
//                colorIndicator.color = note.color
//            } else {
//                console.error("Note is null")
//            }
//        }

    Column {
        id: mainColumn
        width: parent.width
        spacing: Theme.paddingLarge
        anchors.top: parent.top

        PageHeader {
            id: header
            objectName: "pageHeader"

            extraContent.children: [
                IconButton {
                    id: backButton
                    objectName: "backButton"
                    icon.source: "image://theme/icon-m-back"
                    anchors.left: parent.left
                    onClicked: {
                        pageStack.pop()
                    }
                },
                Rectangle {
                    id: colorIndicator
                    objectName: "colorIndicator"
                    color: note ? note.color : "transparent"
                    width: Theme.iconSizeMedium
                    height: Theme.iconSizeMedium
                    anchors.left: backButton.right
                    radius: colorIndicator.width / 2
                    border{
                        width: 3
                        color: Theme.secondaryHighlightColor
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            var dialog = pageStack.push("Sailfish.Silica.ColorPickerDialog")
                            dialog.accepted.connect(function() {
                                colorIndicator.color = dialog.color
                                note.color = dialog.color
                            })
                        }
                    }
                },
                IconButton {
                    id: imageButton
                    objectName: "insertImageButton"
                    icon.source: "image://theme/icon-m-file-image"
                    anchors.right: saveButton.left
                },
                IconButton {
                    id: saveButton
                    objectName: "saveButton"
                    icon.source: "image://theme/icon-m-save"
                    anchors.right: parent.right
                    onClicked: {
                        // Логика сохранения заметки
                        pageStack.pop()
                    }
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
            text: note ? note.title : ""
            readOnly: false
            inputMethodHints: Qt.ImhNone
            EnterKey.iconSource: "image://theme/icon-m-enter-next"
            EnterKey.onClicked: noteText.forceActiveFocus()
            onTextChanged: if (note) note.title = text
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
        anchors.top: mainColumn.bottom
        anchors.topMargin: Theme.paddingLarge
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
                text: note ? note.text : ""
                readOnly: false
                inputMethodHints: Qt.ImhNone
                wrapMode: TextEdit.Wrap
                onTextChanged: if (note) note.text = text
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
                text: note ? qsTr("Created: ") + note.creationDate.toLocaleDateString() : ""
                font.pixelSize: Theme.fontSizeSmall
            }
        }

        VerticalScrollDecorator {}
    }
}


//Page {
//    id: noteEditorPage
//    objectName: "noteEditor"
//    allowedOrientations: Orientation.All

//    property Note note

//    Column {
//        id:mainColumn

//        width: parent.width
//        height: header.height + noteTitle.height
//        spacing: Theme.paddingLarge

//        anchors.top: parent.top

//        PageHeader {
//            id: header
//            objectName: "pageHeader"

//            extraContent.children: [
//                IconButton{ //Кнопка назад
//                    id: backButton
//                    objectName: "backButton"
//                    icon.source: "image://theme/icon-m-back"

//                    anchors.left: parent.left

//                    onClicked: {
//                        pageStack.pop()
//                    }
//                },

//                Rectangle{
//                    id: colorIndicator
//                    objectName: "ColorIndicator"

//                    color: note.color

//                    width: Theme.iconSizeMedium
//                    height: Theme.iconSizeMedium
//                    anchors.left: backButton.right

//                    radius: colorIndicator.width/2

//                    MouseArea{
//                        id: selectorButton

//                        anchors.fill: parent

//                        onClicked: {
//                            var dialog = pageStack.push("Sailfish.Silica.ColorPickerDialog")
//                            dialog.accepted.connect(function() {
//                                colorIndicator.color = dialog.color
//                                note.color = dialog.color
//                            })
//                        }
//                    }

//                },

//                IconButton { //Кнопка для вставки изображения
//                    id: imageButton
//                    objectName: "insertImageButton"
//                    icon.source: "image://theme/icon-m-file-image"


//                    anchors.right: saveButton.left

//                },
//                IconButton{
//                    id: saveButton
//                    objectName: "saveButton"
//                    icon.source: "image://theme/icon-m-save"


//                    anchors.right: parent.right
//                }

//            ]
//        }


//        TextField {
//            id: noteTitle
//            objectName: "noteTitle"

//            width: parent.width
//            anchors.leftMargin: Theme.horizontalPageMargin

//            font.pixelSize: Theme.fontSizeLarge

//            placeholderText: qsTr("Название заметки")
//            text: note.title
//            readOnly: false
//            inputMethodHints: Qt.ImhNone

//            onTextChanged: note.title = text
//        }
//    }

//    SilicaFlickable {
//        id: noteTextContainer
//        objectName: "noteTextContainer"

//        width: parent.width
//        height: parent.height - noteTitle.height - header.height

//        contentHeight: noteText.height + insertedImage.height + 3 * Theme.paddingMedium + dateLabel.height
//        contentWidth: noteText.width

//        anchors.leftMargin: Theme.horizontalPageMargin
//        anchors.bottom: parent.bottom
//        anchors.top: mainColumn.bottom
//        anchors.topMargin: Theme.paddingLarge


//        interactive: true
//        clip: true

//        Column {
//            width: parent.width

//            spacing: Theme.paddingMedium

//            TextArea {
//                id: noteText
//                objectName: "noteText"

//                width: parent.width

//                font.pixelSize: Theme.fontSizeMedium

//                placeholderText: qsTr("Здесь начинается ваша заметка")
//                text: note.text
//                readOnly: false
//                inputMethodHints: Qt.ImhNone
//                wrapMode: TextEdit.Wrap

//                onTextChanged: note.text = text
//            }

//            Image {
//                id: insertedImage
//                objectName: "insertedImage"
//                source: ""
//                width: parent.width
//                fillMode: Image.PreserveAspectFit
//                visible: source !== ""
//            }

//            Label {
//                id: dateLabel
//                anchors.horizontalCenter: parent.horizontalCenter
//                text: qsTr("Created: ") + note.creationDate.toLocaleString(Qt.DefaultLocaleShortDate)
//                font.pixelSize: Theme.fontSizeSmall
//            }

//        }



//        VerticalScrollDecorator {}
//    }


//}
