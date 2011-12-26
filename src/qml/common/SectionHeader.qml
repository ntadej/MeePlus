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
    property alias name: name.text
    property bool simple: false

    anchors.left: parent.left
    anchors.right: parent.right

    anchors.margins: MPUi.DefaultMargin

    height: 30 + 2 * MPUi.DefaultMargin / 4

    BorderImage {
        id: background
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: MPUi.DefaultMargin / 4
        height: 2
        source: "image://theme/meegotouch-separator-background-horizontal"
        visible: !simple
    }

    Label {
        id: name
        font: MPUi.SmallTitleFont
        color: MPUi.LightColor
    }
}
