import QtQuick 2.0
import Sailfish.Silica 1.0
import Notes 1.0

Page {
    id: mainPage
    objectName: "mainPage"
    allowedOrientations: Orientation.All



    NoteList {
        id: noteList
    }

    Column {
        id: headerColumn
        width: parent.width
        spacing: Theme.paddingLarge

        PageHeader {
            objectName: "pageHeader"
            extraContent.children: [

                IconButton{
                    id: filterClearButton
                    objectName: "filterClearButton"

                    icon.source: "image://theme/icon-m-clear"

                    visible: false

                    onClicked: {
                        filterTextField.text = ""
                        noteList.clearFilterColor()
                        colorFilterIndicator.color =  "transparent"
                        filterClearButton.visible = false
                    }
                },

//                IconButton {
//                    id: aboutButton
//                    objectName: "aboutButton"
//                    icon.source: "image://theme/icon-m-about"

//                    anchors.verticalCenter: parent.verticalCenter
//                    anchors.left: parent.left

//                    onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
//                },


//                IconButton{
//                    id: filterCancelButton
//                },


                Rectangle{
                    id: colorFilterIndicator

                    width: Theme.iconSizeMedium
                    height: Theme.iconSizeMedium
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    radius: colorFilterIndicator.width/2
                    border{
                        width: 3
                        color: Theme.secondaryHighlightColor
                    }

                    color: noteList.filterColor

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            var dialog = pageStack.push("Sailfish.Silica.ColorPickerDialog")
                            dialog.accepted.connect(function() {
                                colorFilterIndicator.color = dialog.color
                                noteList.filterColor = dialog.color
                                filterClearButton.visible = true
                            })

                        }
                    }
                },




                TextField{
                    id: filterTextField

                    anchors.left: filterClearButton.right
                    anchors.bottom: parent.bottom
                    width: parent.width/3*2

                    placeholderText: qsTr("Фильтр заметок")
                    onTextChanged: {
                        noteList.filterText = text
                        if (filterTextField.text != ""){
                            filterClearButton.visible = true
                        } else if(Qt.colorEqual(colorFilterIndicator.color, "transparent")){
                            filterClearButton.visible = false
                        }
                    }
                }

            ]
        }
    }

    SilicaListView {
        id: notesList
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: headerColumn.bottom
        anchors.bottom: addNoteButton.top
        //anchors.bottom: parent.bottom
        model: noteList

        clip: true
        delegate: ListItem{
            id: clickArea
            property bool isLongPress: false
            property int pressDuration: 100
            property bool contextMenuVisible: false

            Label{
                id: noteTitle

                anchors.left: parent.left
                width: parent.width/2
                anchors.leftMargin: Theme.horizontalPageMargin
                anchors.verticalCenter: parent.verticalCenter

                text: model.title
                truncationMode: TruncationMode.Elide
            }
            Rectangle{
                id: colorIndicator

                width: Theme.iconSizeMedium
                height: Theme.iconSizeMedium
                anchors.right: parent.right
                anchors.rightMargin: Theme.horizontalPageMargin
                anchors.verticalCenter: parent.verticalCenter

                radius: colorIndicator.width/2

                border{
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
                }
            }
            onPressed: {
                clickArea.isLongPress = false
                pressTimer.start()
            }
            onReleased: {
                pressTimer.stop()
                if (!clickArea.isLongPress) {
                    var noteObject = model.note
                    var editPage = noteEditorPageComponent.createObject(pageStack, { "note": noteObject })
                    pageStack.push(editPage)
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

             }

        }

        VerticalScrollDecorator{}
   }

    Button{
        id: addNoteButton
        objectName: "addNoteButton"

        anchors.bottom: parent.bottom
        preferredWidth: parent.width


        text: qsTr("Добавить заметку")


        onClicked: {
            var newNote = noteList.addNote(qsTr(""), qsTr(""), colorPicker.colors[0])
            var editPage = noteEditorPageComponent.createObject(pageStack, { "note": newNote });
            pageStack.push(editPage)
        }
    }

    Component {
        id: noteEditorPageComponent
        NoteEditor {
            id: noteEditorPage
        }
    }
    ColorPicker {
            id: colorPicker
            visible: false
        }
}



