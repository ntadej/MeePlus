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
    id: searchResultsPage
    anchors.margins: MPUi.DefaultMargin
    anchors.topMargin: header.height
    tools: ToolBarLayout {
        id: searchPageTools
        visible: true
        IconBack {}
    }

    ListView {
        id: searchView
        anchors.fill: parent
        width: parent.width
        model: MPSearch
        pressDelay: 140

        delegate: Item {
            id: searchItem
            height: 50 + 2 * MPUi.DefaultMargin
            width: parent.width

            ItemBackground {
                id: itemBackground
                anchors.leftMargin: -searchResultsPage.anchors.leftMargin
                anchors.rightMargin: -searchResultsPage.anchors.rightMargin
                visible: mouseAreaItem.pressed
            }

            Separator {
                anchors.leftMargin: -searchResultsPage.anchors.leftMargin
                anchors.rightMargin: -searchResultsPage.anchors.rightMargin
            }

            Row {
                anchors.verticalCenter: parent.verticalCenter
                spacing: MPUi.DefaultMargin

                Avatar {
                    id: icon
                    active: mouseAreaItem.pressed
                    image: model.image
                    anchors.verticalCenter: parent.verticalCenter
                }

                Label {
                    id: name
                    font: MPUi.TitleFont
                    text: model.name
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            IconListArrow { }

            MouseArea {
                id: mouseAreaItem
                anchors.fill: itemBackground
                onClicked: {
                    MPPeople.request(model.id)
                    MPActivities.list(model.id)
                }
            }
        }
        footer: Item {
            id: searchFooter
            height: 44
            width: parent.width

            ItemBackground {
                id: footerBackground
                anchors.leftMargin: -searchResultsPage.anchors.leftMargin
                anchors.rightMargin: -searchResultsPage.anchors.rightMargin
                visible: mouseAreaFooter.pressed
            }

            Label {
                id: footerLabel
                font: MPUi.TitleFont
                text: qsTr("Load more")
            }

            MouseArea {
                id: mouseAreaFooter
                anchors.fill: footerBackground
                onClicked: MPPeople.searchNext()
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
