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

    ListView {
        id: listView
        anchors {left: parent.left; right: parent.right; top: searchBox.bottom; bottom: parent.bottom}
        model: XmltvChannels
        pressDelay: 140

        delegate:  Item {
            id: listItem
            height: 88
            width: parent.width

            BorderImage {
                id: background
                anchors.fill: parent
                // Fill page porders
                anchors.leftMargin: -playlistPage.anchors.leftMargin
                anchors.rightMargin: -playlistPage.anchors.rightMargin
                visible: mouseArea.pressed
                source: "image://theme/meegotouch-list-background-pressed-center"
            }

            Image {
                id: icon
                source: "image://theme/icon-m-content-video"
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 32;
            }

            Label {
                id: numberText
                anchors.left: icon.right;
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 16;
                text: model.number + "."
                font: TanoUi.SubtitleFont
                color: TanoUi.HighlightColor
            }

            Row {
                anchors { left: numberText.right; right: parent.right; top: parent.top; bottom: parent.bottom }
                anchors.leftMargin: 10;

                 Label {
                     id: mainText
                     anchors.verticalCenter: parent.verticalCenter
                     text: model.display
                     font: TanoUi.TitleFont
                     wrapMode: Text.WordWrap
                     width: parent.width
                 }
            }


            MouseArea {
                id: mouseArea
                anchors.fill: background
                onClicked: {
                    TanoJsCore.addPage("ScheduleListPage.qml")
                    var page = pageStack.currentPage
                    page.setChannel(epg)
                }
            }
        }
    }
    ScrollDecorator {
        flickableItem: listView
    }
}
