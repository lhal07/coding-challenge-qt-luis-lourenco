import QtQuick 2.0

Item {
    property variant dataModel: ({})
    height: 100
    focus: false

    ListView {
        width: parent.width
        orientation: ListView.Horizontal
        model: dataModel
        delegate: infoDelegate
    }

    Component {
        id: infoDelegate

        Item {
            width: 100; height: 70
            Rectangle {
                color: "whitesmoke"
                anchors.fill: parent
                anchors.margins: 5
                radius: 10
                width: parent.width; height: parent.height

                Column {
                    anchors.fill: parent
                    Text { id: infoField; text: name; font.pixelSize: 12; color: "dimgrey"; anchors.horizontalCenter: parent.horizontalCenter }
                    Text { id: infoTotal; text: count; font.pixelSize: 40; color: "dimgrey"; anchors.horizontalCenter: parent.horizontalCenter }
                }
            }
        }
    }



}
