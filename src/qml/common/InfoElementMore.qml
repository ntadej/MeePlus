/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2011 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    id: infoElementMore

    property alias name: name.text
    signal clicked

    anchors.left: parent.left
    anchors.right: parent.right

    anchors.margins: MPUi.DefaultMargin

    height: name.height + value.height

    Label {
        id: name
        font: MPUi.FieldLabelFont
        color: MPUi.FieldLabelColor

        anchors.top: parent.top
    }

    Label {
        id: value
        wrapMode: Text.WordWrap
        width: parent.width
        text: qsTr("Read more")

        anchors.top: name.bottom
    }

    Image {
        source: mouseArea.pressed ? "image://theme/icon-s-description-inverse" : "image://theme/icon-s-description"
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: infoElementMore.clicked()
    }
}
