import QtQuick 2.0
import Sailfish.Silica 1.0
import Notes 1.0
import "../"

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

    NoteListView {
            id: notesList
            model: noteList
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



