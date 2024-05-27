import QtQuick 2.0
import Sailfish.Silica 1.0
import Notes 1.0

Page {
    id: exportPage
    allowedOrientations: Orientation.Portrait


    property string fileName: ""
    property Note note
    signal fileNameEntered(string filePath);

    Column {
        id: mainColumn
        width: parent.width
        spacing: Theme.paddingLarge
        anchors.top: parent.top

        PageHeader {
            id: header
            objectName: "pageHeader"

            extraContent.children:[
                IconButton{
                    id: saveButton
                    objectName: "saveButton"
                    icon.source: "image://theme/icon-m-save"
                    anchors.right: parent.right

                    enabled: fileNameInput.text.length > 0

                    onClicked: {
                        exportPage.fileNameEntered(StandardPaths.documents + "/" + fileName)
                        fileNameInput.focus = false;
                        pageStack.pop()
                    }

                }

            ]
        }

        TextField {
            id: fileNameInput
            width: parent.width
            placeholderText: qsTr("Название файла")
            text: exportPage.fileName

            inputMethodHints: Qt.ImhNone
            EnterKey.iconSource: "image://theme/icon-m-enter-next"
            EnterKey.onClicked: {
                exportPage.fileNameEntered(StandardPaths.documents + "/" + fileName)
                fileNameInput.focus = false;
                pageStack.pop()

            }

            onTextChanged: {
                exportPage.fileName = text
            }
        }

        Label{
            anchors.left: parent.left
            anchors.leftMargin: Theme.horizontalPageMargin
            text: qsTr("Файлы сохраняются в папке Документы")
        }

    }

}
