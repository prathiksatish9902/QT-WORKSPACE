import QtQuick 2.15
import QtQuick.Layouts 1.15

GridLayout{
    columns: 3
    Layout.alignment: Qt.AlignCenter
OperationalIcon
{
    id: _ncCuttingIcon
    iconSource: "qrc:/Icons/cuttingicon.png"
    label: qsTr("NC Cutting")
}
OperationalIcon
{
    id: _directCuttingIcon
    iconSource: "qrc:/Icons/cuttingicon.png"
    label: qsTr("Direct Cutting")
}

OperationalIcon
{
    id: _easyCuttingIcon
    iconSource: "qrc:/Icons/cuttingicon.png"
    label: qsTr("Easy Cutting")
}

OperationalIcon
{
    id: _optiCuttingIcon
    iconSource: "qrc:/Icons/cuttingicon.png"
    label: qsTr("Opti Cutting")
}

OperationalIcon
{
    id: _jobManagementIcon
    iconSource: "qrc:/Icons/cuttingicon.png"
    label: qsTr("Job Management")
}
}
