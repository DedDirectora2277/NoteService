import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {
    id: signUpPage
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    Column{
        id: signUpColumn

        anchors.right: parent.right
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        spacing: Theme.paddingLarge
        Label{
            id: signUpLabel
            text: qsTr("Регистрация")
        }
        TextField{
            id: userNameSignUpField

            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: Theme.horizontalPageMargin
            anchors.rightMargin: Theme.horizontalPageMargin

            label: qsTr("Имя пользователя")

        }
        PasswordField{
            id: passwordSignUpField

            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: Theme.horizontalPageMargin
            anchors.rightMargin: Theme.horizontalPageMargin

            EnterKey.iconSource: "image://theme/icon-m-enter-next"
            EnterKey.clicked: signInPage.accept()

            label: qsTr("Пароль")

        }
        Button{
            id: submitButton

            preferredWidth: Theme.buttonWidthLarge
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Войти")
            onClicked: {
                signUpPage.accept()
            }
        }
    }
}
