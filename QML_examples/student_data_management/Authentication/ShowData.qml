import QtQuick 2.15
// import studentData 1.0
Item {



    Component
    {
        id: headerComponent
        DataHeader
        {
            // anchors.fill: parent
        }
    }


    ListView
    {
        id: listView
        width: parent.width/2
        height: parent.height
        spacing: 5
        model: studentModel
        header: headerComponent
        headerPositioning: ListView.OverlayHeader
        delegate: studentDelegate
    }

    Component
    {
        id: studentDelegate
        Rectangle
        {
            id: background
            width: listView.width
            height: listView.height / 5
            color: "grey"

            Row
            {
                spacing: 10
                width: parent.width
                height: parent.height
                topPadding: parent.height / 2.5

                Text {
                    id: slno
                    text: model.index + 1
                }

                Text {
                    id: stname
                    text: studentName
                }

                Text {
                    id: stphone
                    text: contactNumber
                }

                Text {
                    id: stfathername
                    text: fatherName
                }

                Text {
                    id: stmail
                    text: mailId
                }

                Text {
                    id: stusername
                    text: userName
                }

                Text {
                    id: stpassword
                    text: password
                }
            }
        }
    }

}
