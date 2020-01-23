import QtQuick 2.0
import QtQuick.Layouts 1.12
import Albums 1.0

ColumnLayout {
    property bool showAlbumMenu: true
    property bool showPhotosMenu: false

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
            text: showAlbumMenu? "Albuns" : albumsList.currentItem.itemModel.title
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.right: parent.right
            anchors.rightMargin: 30
            font.pointSize: 24
            elide: Text.ElideRight
            visible: showAlbumMenu || showPhotosMenu
        }

        AlbumSelection {
            id: albumsList
            anchors.top: headerText.bottom
            anchors.topMargin: 25
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            height: 200
            clip: true
            focused: visible
            dataModel: albumsModel
            visible: showAlbumMenu && !showPhotosMenu
        }

        PhotoSelection {
            id: photosGrid
            anchors.top: headerText.bottom
            anchors.topMargin: 25
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.right: parent.right
            anchors.rightMargin: 25
            height: 200
            clip: true
            focused: visible
            dataModel: photosModel
            visible: !showAlbumMenu && showPhotosMenu
        }

        Rectangle {
            id: fullscreenPhoto
            color: "white"
            border.color: "black"
            border.width: 2
            anchors.fill: parent
            focus: visible
            visible: !showAlbumMenu && !showPhotosMenu
            Image {
                id: photo
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: photosGrid.currentItem.itemModel? photosGrid.currentItem.itemModel.url : ""
            }
        }

        InfoList {
            id: infoList
            anchors.top: albumsList.bottom
            anchors.topMargin: 25
            anchors.left: parent.left
            anchors.leftMargin: 80
            anchors.right: parent.right
            anchors.rightMargin: 80
            height: 100
            clip: true
            dataModel: infoDataModel
            visible: albumsList.visible || photosGrid.visible
        }

        function checkPhotosModel() {
            return albumsList.currentItem.itemModel?true:false
        }

        function updatePhotosModel() {
            var albumId = albumsList.currentItem.itemModel.id;
            photosModel.setAlbumId(albumId);
        }

        function goToPhotoMenu() {
            showAlbumMenu = false;
            showPhotosMenu = true;
        }

        function goToAlbumMenu() {
            showAlbumMenu = true;
            showPhotosMenu = false;
        }

        function showFullscreenPhoto() {
            showAlbumMenu = false;
            showPhotosMenu = false;
        }

        Keys.onPressed: {
            switch(event.key) {
            case Qt.Key_Return:
                if (showAlbumMenu) {
                    updatePhotosModel();
                    goToPhotoMenu();
                } else if (showPhotosMenu) {
                    showFullscreenPhoto();
                }
                event.accepted = true;
                break;

            case Qt.Key_Escape:
                if (showPhotosMenu) {
                    goToAlbumMenu();
                } else if (!showAlbumMenu) {
                    goToPhotoMenu();
                }

                event.accepted = true;
                break;
            }
        }
    }
}
