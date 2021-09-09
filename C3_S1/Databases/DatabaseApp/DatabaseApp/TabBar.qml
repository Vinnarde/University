import QtQuick 2.3

Item 
{
    Rectangle
    {
        id: tab1
        width: 100
        height: 30
        color: "gold"
        radius: 5
        Text
        {
            text: "Assistant Schedule"
            anchors
            {
                top: parent.top
                topMargin: 5
                horizontalCenter: parent.horizontalCenter
            }
        }
        anchors
        {
            top: parent.top
            left: parent.left
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                parent.color = "gold";
                tab2.color = "lightgrey";
                loadcom.source = "ShowAssistantSchedule.qml";
            }
        }
    }
    Rectangle
    {
        id: tab2
        width: 100
        height: 30
        color: "lightgrey"
        radius: 5
        Text
        {
            text: "Insert Transaction"
            anchors
            {
                top: parent.top
                topMargin: 5
                horizontalCenter: parent.horizontalCenter
            }
        }
        anchors
        {
            top: parent.top
            left: tab1.right
            leftMargin: 5
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                parent.color = "gold";
                tab1.color = "lightgrey";
                loadcom.source = "InsertTransaction.qml";
            }
        }
    }
    Rectangle
    {
        anchors
        {
            top: parent.top
            topMargin: 20
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        radius: 5
        gradient:Gradient
        {
            GradientStop{ position: 0.0; color: "lightgrey" }
            GradientStop{ position: 0.1; color: "white" }
            GradientStop{ position: 0.9; color: "lightgrey" }
        }
        border.color: "grey"
        Loader
        {
            id: loadcom;
            source: "ShowAssistantSchedule.qml"
            anchors.fill: parent
        }
    }
}