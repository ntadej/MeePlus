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

import "../common"

Item {
    property alias title: lTitle.text
    property alias verb: lVerb.text
    property alias actorName: aName.text
    property alias actorImage: aIcon.source

    width: parent.width
    height: column.height + 2 * MPUi.DefaultMargin

    ItemBackground {
        id: itemBackground
        anchors.leftMargin: -activitiesPage.anchors.leftMargin
        anchors.rightMargin: -activitiesPage.anchors.rightMargin
        visible: mouseAreaItem.pressed
    }

    Separator {
        anchors.leftMargin: -activitiesPage.anchors.leftMargin
        anchors.rightMargin: -activitiesPage.anchors.rightMargin
    }

    Column {
        id: column
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: MPUi.DefaultMargin
        anchors.topMargin: MPUi.DefaultMargin

        Row {
            spacing: MPUi.DefaultMargin

            Avatar {
                id: aIcon
                active: mouseAreaItem.pressed
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: aName
                font: MPUi.SubtitleFont
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: lVerb
                font: MPUi.TitleFont
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Label {
            id: lTitle
            font: MPUi.SubtitleFont
        }
    }

    MouseArea {
        id: mouseAreaItem
        anchors.fill: itemBackground
        onClicked: {

        }
    }

    Component.onCompleted: {
        activitiesView.height += column.height
    }
}
