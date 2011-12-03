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
    property alias title: heading.text
    property bool orientation: screen.currentOrientation == Screen.Landscape

    color: MPUi.HighlightColor
    height: orientation ?
                MPUi.HeaderDefaultHeightLandscape :
                MPUi.HeaderDefaultHeightPortrait
    width: parent.width

    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.topMargin: -parent.anchors.topMargin
    anchors.leftMargin: -parent.anchors.leftMargin
    anchors.rightMargin: -parent.anchors.rightMargin

    Text {
        id: heading
        color: MPUi.HeaderColor
        font: MPUi.HeaderFont
        anchors.fill: parent
        anchors.topMargin: orientation ?
                               MPUi.HeaderDefaultTopSpacingLandscape :
                               MPUi.HeaderDefaultTopSpacingPortrait
        anchors.rightMargin: MPUi.DefaultMargin
        anchors.leftMargin: MPUi.DefaultMargin
    }

    MouseArea {
        anchors.fill: parent
    }

    Separator { }
}
