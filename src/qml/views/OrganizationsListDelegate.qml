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
    property alias name: name.text
    property alias title: title.text
    property alias type: type.text

    property alias startDate: startDate.text
    property alias endDate: endDate.text

    width: parent.width
    height: column.height + 2 * MPUi.DefaultMargin

    Separator {
        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
    }

    Column {
        id: column
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: MPUi.DefaultMargin
        anchors.topMargin: MPUi.DefaultMargin
        width: parent.width

        spacing: MPUi.DefaultMargin / 2

        LabelSmall {
            id: type
        }

        Label {
            id: name
            wrapMode: Text.WordWrap
            width: parent.width

            visible: text !== ""
        }

        Label {
            id: title
            wrapMode: Text.WordWrap
            width: parent.width

            visible: text !== ""
        }


        Row {
            spacing: MPUi.DefaultMargin

            LabelSmall {
                id: startDate
                anchors.verticalCenter: parent.verticalCenter
                visible: text !== ""
            }

            LabelSmall {
                id: dateSpacer
                anchors.verticalCenter: parent.verticalCenter
                text: "-"
                visible: startDate.text !== ""
            }

            LabelSmall {
                id: endDate
                anchors.verticalCenter: parent.verticalCenter
                visible: text !== ""
            }
        }
    }

    Component.onCompleted: {
        organizationsList.height += column.height
    }
}
