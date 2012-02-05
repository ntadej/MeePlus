/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
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

Item {
    id: searchItem
    height: 50 + 2 * MPUi.DefaultMargin
    width: parent.width

    property string personId: ""
    property alias name: name.text
    property alias image: icon.image
    property bool original: false

    ItemBackground {
        id: itemBackground
        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
        visible: mouseAreaItem.pressed && !original
    }

    Separator {
        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
    }

    Row {
        anchors.verticalCenter: parent.verticalCenter
        spacing: MPUi.DefaultMargin
        width: parent.width

        Avatar {
            id: icon
            active: mouseAreaItem.pressed && !original
            anchors.verticalCenter: parent.verticalCenter
        }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width

            LabelSmall {
                id: label
                text: qsTr("Original post by")
                visible: original
            }

            LabelTitle {
                id: name
            }
        }
    }

    IconListArrow {
        visible: !original
    }

    MouseArea {
        id: mouseAreaItem
        anchors.fill: itemBackground
        onClicked: {
            MPPeople.request(personId)
            MPActivities.list(personId)
        }
    }
}

