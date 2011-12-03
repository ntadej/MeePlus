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
import "../icons"
import "../views"

import "../js/core.js" as MPJs

Page {
    id: searchPage
    tools: ToolBarLayout {
        id: searchPageTools
        visible: true
        IconBack {}
    }

    ListView {
        id: searchView
        anchors {left: parent.left; right: parent.right; top: header.bottom; bottom: parent.bottom}
        width: parent.width
        model: MPSearch
        pressDelay: 140

        delegate: Item {
            id: searchItem
            height: 88
            width: parent.width

            ItemBackground {
                id: itemBackground
                visible: mouseAreaItem.pressed
            }

            ProfileHeader {
                id: profileHeader
                item: true
                name: model.name
                image: model.image

                anchors.fill: parent
            }

            IconListArrow { }

            MouseArea {
                id: mouseAreaItem
                anchors.fill: itemBackground
                //onClicked:
            }
        }
        footer: Item {
            id: searchFooter
            height: 44
            width: parent.width

            ItemBackground {
                id: footerBackground
                visible: mouseAreaFooter.pressed
            }

            ProfileHeader {
                id: loadMore
                item: true
                name: qsTr("Load more")

                anchors.fill: parent
            }

            MouseArea {
                id: mouseAreaFooter
                anchors.fill: footerBackground
                //onClicked:
            }
        }
    }

    ScrollDecorator {
        flickableItem: searchView
    }

    PageHeader {
        id: header
        title: qsTr("Search results")
    }
}
