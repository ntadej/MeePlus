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

import "../js/core.js" as MPJs

Page {
    id: profilePage
    anchors.margins: MPUi.DefaultMargin
    anchors.topMargin: header.height

    ListModel {
        id: testModel
        ListElement {
            name: "Tadej Novak"
            image: ""
            tagline: "Tagline"
        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        model: testModel
        pressDelay: 140

        delegate:  Item {
            id: listItem
            width: parent.width
            height: 100

            BorderImage {
                id: background
                anchors.fill: parent
                // Fill page borders
                anchors.leftMargin: -profilePage.anchors.leftMargin
                anchors.rightMargin: -profilePage.anchors.rightMargin
                //visible: mouseArea.pressed
                source: "image://theme/meegotouch-list-background-pressed-center"
            }

            Image {
                id: icon
                source: model.image
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 32;
            }

            Column {
                anchors { left: icon.right; right: parent.right; top: parent.top; bottom: parent.bottom }
                anchors.leftMargin: 10;
                anchors.verticalCenter: parent.verticalCenter

                 Label {
                     id: mainText
                     text: model.name
                     font: MPUi.TitleFont
                 }

                 Label {
                     id: numberText
                     text: model.tagline
                     font: MPUi.SubtitleFont
                     color: MPUi.HighlightColor
                 }
            }
        }
    }
    ScrollDecorator {
        flickableItem: listView
    }

    PageHeader {
        id: header
        title: qsTr("Profile")
    }
}
