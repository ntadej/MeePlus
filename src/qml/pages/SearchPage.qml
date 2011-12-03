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
    anchors.margins: MPUi.DefaultMargin
    tools: ToolBarLayout {
        id: searchPageTools
        visible: true
        IconBack {}
    }

    Connections {
        target: MPPeople
        onFinishedSearch: {
            MPJs.addPage("SearchResultsPage.qml")
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 2 * MPUi.DefaultMargin
        width: parent.width

        TextField {
            id: search
            height: 60
            width: parent.width
            anchors.margins: MPUi.DefaultMargin

            platformSipAttributes: SipAttributes { actionKeyHighlighted: true }

            placeholderText: qsTr("Search ...")
            platformStyle: TextFieldStyle { paddingRight: clearButton.width }
            Image {
                id: clearButton
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                source: "image://theme/icon-m-input-clear"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        search.text = ""
                    }
                }
            }
        }

        Button {
            id: go
            text: qsTr("Search")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                MPPeople.search(search.text)
            }
        }
    }

    PageHeader {
        id: header
        title: qsTr("Search G+")
    }
}
