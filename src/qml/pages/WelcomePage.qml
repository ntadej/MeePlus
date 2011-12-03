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

import "../js/core.js" as MPJs

Page {
    id: welcomePage
    anchors.margins: MPUi.DefaultMargin
    anchors.topMargin: header.height
    tools: ToolBarLayout {
        id: welcomePageTools
        visible: true
        IconSettings {}
        IconLogin {}
        IconMenu {}
    }

    onStatusChanged: MPJs.settings()

    Connections {
        target: MPPeople
        onFinishedProfile: {
            MPJs.addPage("PersonPage.qml")
        }
    }

    ListModel {
        id: pagesModel
        ListElement {
            page: ""
            title: "My profile"
            subtitle: "Checkout your profile"
            image: "image://theme/icon-m-common-drilldown-arrow"
        }
        ListElement {
            page: "SearchPage.qml"
            title: "Search G+"
            subtitle: "Search for users, pages, etc."
            image: "image://theme/icon-m-common-drilldown-arrow"
        }
    }

    ListView {
        id: welcomeView
        anchors.fill: parent
        model: pagesModel

        delegate: Item {
            id: listItem
            height: 88
            width: parent.width

            BorderImage {
                id: background
                anchors.fill: parent
                // Fill page porders
                anchors.leftMargin: -welcomePage.anchors.leftMargin
                anchors.rightMargin: -welcomePage.anchors.rightMargin
                visible: mouseArea.pressed
                source: "../images/background-pressed.png"
            }

            Row {
                anchors.fill: parent

                Column {
                    anchors.verticalCenter: parent.verticalCenter

                    Label {
                        id: mainText
                        text: model.title
                        font: MPUi.TitleFont
                    }

                    Label {
                        id: subText
                        text: model.subtitle
                        font: MPUi.SubtitleFont
                        color: MPUi.HighlightColor

                        visible: text != ""
                    }
                }
            }
            Image {
                source: model.image
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                id: mouseArea
                anchors.fill: background
                onClicked: {
                    if(model.title == "My profile") {
                        MPPeople.requestProfile("me");
                    }
                    if(model.page !== "")
                        MPJs.addPage(model.page)
                }
            }
        }
    }

    ScrollDecorator {
        flickableItem: welcomeView
    }

    PageHeader {
        id: header
        title: "MeePlus"
    }
}
