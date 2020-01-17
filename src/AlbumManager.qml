import QtQuick 2.0
import QtQuick.Layouts 1.12
import Albums 1.0

ColumnLayout {
    property bool showAlbumMenu: true

    AlbumsListModel { id: albumsModel }
    PhotosListModel { id: photosModel }
    InfoDataModel { id: infoDataModel }

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        border.color: "black"
        border.width: 2
        radius: 10

        Text {
            id: headerText
            text: showAlbumMenu? "Albuns" : "Album"
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 30
            font.pointSize: 24
        }

        AlbumSelector {
            id: albumsList
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.top: headerText.bottom
            anchors.topMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            height: 200
            clip: true
            dataModel: albumsModel
            visible: showAlbumMenu
        }

        InfoList {
            id: infoList
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: albumsList.bottom
            anchors.topMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 20
            height: 100
            clip: true
            dataModel: infoDataModel
            visible: showAlbumMenu
        }

        PhotoSelection {
            id: photosGrid
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.top: headerText.bottom
            anchors.topMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            dataModel: photosModel
            visible: !showAlbumMenu
        }

    }
}
