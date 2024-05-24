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

                    onClicked: {
                        filterTextField.text = ""
                        noteList.clearFilterColor()
                        colorFilterIndicator.color =  "transparent"
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
                            })
                        }
                    }
                },


//                IconButton{
//                    id: addButton
//                    objectName: "addButton"

//                    icon.source: "image://theme/icon-m-new"
//                    anchors.right: parent.right
//                    anchors.verticalCenter: parent.verticalCenter

//                    onClicked: {
//                        var newNote = noteList.addNote(qsTr(""), qsTr(""), "blue")
//                        var editPage = noteEditorPageComponent.createObject(pageStack, { "note": newNote });
//                        pageStack.push(editPage)
//                    }

//                },

                TextField{
                    id: filterTextField

                    anchors.left: filterClearButton.right
                    anchors.bottom: parent.bottom
                    width: parent.width/3*2

                    placeholderText: qsTr("Фильтр заметок")
                    onTextChanged: noteList.filterText = text
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

//                MenuItem {
//                    text: qsTr("Отмена")
//                    onClicked: {

//                        contextMenuVisible = false
//                    }
//                }
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


//Rectangle {
//    id: note1
//    width: parent.width - Theme.horizontalPageMargin
//    height: Theme.itemSizeLarge
//    anchors.horizontalCenter: parent.horizontalCenter
//    radius: Theme.paddingSmall

//    color: Theme.darkPrimaryColor

//    Column {
//        anchors.left: parent.left
//        anchors.leftMargin: Theme.horizontalPageMargin
//        width: parent.width/2
//        height: parent.height
//        spacing: Theme.paddingMedium

//        Label {
//            id: title1
//            text: model.title
//            width: parent.width
//            anchors.left: parent.left
//            truncationMode: TruncationMode.Elide
//        }

////                        Text {
////                            id: time1
////                            width: parent.width
////                            text: qsTr("Created: ") + model.creationDate.toString("dd.MM.yyyy")
////                            font.pointSize: Theme.fontSizeExtraSmall
////                            horizontalAlignment: Text.AlignRight
////                            color: Theme.darkSecondaryColor
////                        }
//    }
//    Rectangle{
//        id: colorSelector

//        width: Theme.iconSizeMedium
//        height: Theme.iconSizeMedium
//        anchors.right: parent.right
//        anchors.rightMargin: Theme.horizontalPageMargin

//        radius: this.width/2

//        color: model.color

//    }

//    MouseArea{
//        anchors.fill: parent
//        onClicked: {
//            var editPage = noteEditorPageComponent.createObject(pageStack, { "note": model });
//            pageStack.push(editPage);
//        }
//    }
//}



//        Rectangle {
//            id: note1
//            width: parent.width - 64
//            height: Theme.itemSizeLarge
//            anchors.horizontalCenter: parent.horizontalCenter
//            radius: Theme.paddingSmall

//            Column {
//                anchors.centerIn: parent
//                width: parent.width - 48
//                height: parent.height - 48
//                spacing: Theme.paddingMedium

//                Text {
//                    id: title1
//                    text: qsTr("Важная информация о Аврора")
//                }

//                Text {
//                    id: time1
//                    width: parent.width
//                    text: qsTr("10:46")
//                    font.pointSize: Theme.fontSizeTinyBase
//                    horizontalAlignment: Text.AlignRight
//                    color: Theme.darkSecondaryColor
//                }
//            }
//        }

//        Rectangle {
//            id: note2
//            width: parent.width - 64
//            height: Theme.itemSizeLarge
//            anchors.horizontalCenter: parent.horizontalCenter
//            radius: Theme.paddingSmall

//            Column {
//                anchors.centerIn: parent
//                width: parent.width - 48
//                height: parent.height - 48
//                spacing: Theme.paddingMedium

//                Text {
//                    id: title2
//                    text: qsTr("Важная информация о Аврора")
//                }

//                Text {
//                    id: time2
//                    width: parent.width
//                    text: qsTr("18.05.2024")
//                    font.pointSize: Theme.fontSizeTinyBase
//                    horizontalAlignment: Text.AlignRight
//                    color: Theme.darkSecondaryColor
//                }
//            }
//        }
//    }

//    Item {
//        property real basePosX: (createNoteButton.width / 2) - (createNoteButtonIcon.width / 2)
//        property real basePosY: (createNoteButton.height / 2) - (createNoteButtonIcon.height / 2)
//        property real currentPosX: (createNoteButton.width / 2) - (createNoteButtonIcon.width / 2)
//        property real currentPosY: (createNoteButton.height / 2) - (createNoteButtonIcon.height / 2)

//        id: createNoteButton
//        x: parent.width - 126
//        y: parent.height - 126

//        Rectangle {
//            id: createNoteButtonIcon
//            x: basePosX
//            y: basePosY
//            width: Theme.itemSizeSmall
//            height: Theme.itemSizeSmall
//            radius: width * 0.5
//            antialiasing: true
//            smooth: true
//        }

//        Rectangle {
//            id: createNoteButtonIconBar1
//            anchors.centerIn: createNoteButtonIcon
//            width: Theme.iconSizeExtraSmall
//            height: 4
//            antialiasing: true
//        }

//        Rectangle {
//            id: createNoteButtonIconBar2
//            anchors.centerIn: createNoteButtonIcon
//            width: Theme.iconSizeExtraSmall
//            height: 4
//            antialiasing: true
//            rotation: 90
//        }

//        MouseArea {
//            id: createNoteArea
//            anchors.fill: createNoteButtonIcon
//            onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))

//        }


