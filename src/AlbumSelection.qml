import QtQuick 2.0

Item {
    property variant dataModel: ({})
    property variant currentItem: albumsListView.currentItem
    property int currentIndex: albumsListView.currentIndex
    property bool focused: false

    ListView {
        id: albumsListView
        height: parent.height
        width: parent.width
        orientation: ListView.Horizontal
        model: dataModel
        highlight: Rectangle { width: 170; height: 200; color: "lightsteelblue"; radius: 5}
        delegate: albumsDelegate
        focus: focused
    }

    Component {
        id: albumsDelegate

        Item {
            id: albumSelectedItem
            width: 170; height: 200
            property variant itemModel: model

            Rectangle {
                id: photoImage
                anchors.top: parent.top
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                width: 150
                height: 150
                color: "transparent"
                border.color: "black"
                border.width: 2
                Image {
                    id: photo
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: image
                }
            }

            Rectangle {
                color: "dimgrey"
                width: albumText.paintedWidth + 4
                height: albumText.paintedHeight + 4
                radius: 5
                anchors.top: photoImage.bottom;
                anchors.topMargin: 10;
                anchors.horizontalCenter: parent.horizontalCenter;

                Text {
                    width: 110
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    id: albumText
                    font.pixelSize: 14
                    color: "white"
                    text: title
                    elide: Text.ElideRight
                }
            }
        }
    }


}
