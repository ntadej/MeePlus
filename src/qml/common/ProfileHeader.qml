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

Rectangle {
    property alias image: icon.source
    property alias name: name.text
    property alias tagline: tagline.text

    anchors.left: parent.left
    anchors.right: parent.right

    height: 100 + 2*MPUi.DefaultMargin

    BorderImage {
        id: background
        anchors.fill: parent
        source: "image://theme/meegotouch-list-background-pressed-center"
    }

    Image {
        id: icon
        anchors.left: parent.left
        anchors.margins: MPUi.DefaultMargin
        anchors.verticalCenter: parent.verticalCenter
    }

    Column {
        anchors.left: icon.right
        anchors.right: parent.right
        anchors.margins: MPUi.DefaultMargin
        anchors.verticalCenter: parent.verticalCenter

         Label {
             id: name
             font: MPUi.TitleFont
         }

         Label {
             id: tagline
             width: parent.width
             wrapMode: Text.WordWrap
             font: MPUi.SubtitleFont
             color: MPUi.HighlightColor
         }
    }
}
