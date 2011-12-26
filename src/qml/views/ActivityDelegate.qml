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
    property alias published: lPublished.text

    property alias actorName: aName.text
    property alias actorImage: aIcon.source
    property alias actorOriginal: aOriginal.text

    property alias comments: lComments.text
    property alias plusoners: lPlusoners.text
    property alias resharers: lResharers.text

    property alias photo: iPhoto.source

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
        width: parent.width

        spacing: MPUi.DefaultMargin / 2

        Row {
            spacing: MPUi.DefaultMargin

            Avatar {
                id: aIcon
                active: mouseAreaItem.pressed
                anchors.verticalCenter: parent.verticalCenter
            }

            Column {
                Label {
                    id: aName
                    font: MPUi.TitleFont
                }

                Row {
                    spacing: MPUi.DefaultMargin / 2

                    Label {
                        id: lVerb
                        font: MPUi.InfoFont
                        color: MPUi.LightColor
                    }

                    Label {
                        id: lPublished
                        font: MPUi.InfoFont
                        color: MPUi.LightColor
                    }
                }

                Label {
                    id: aOriginal
                    font: MPUi.InfoFont
                    color: MPUi.LightColor
                    visible: text !== ""
                }
            }
        }

        Label {
            id: lTitle
            font: MPUi.SubtitleFont
            wrapMode: Text.WordWrap
            width: parent.width
        }

        Image {
            id: iPhoto
        }

        Row {
            spacing: MPUi.DefaultMargin

            Label {
                id: lPlusoners
                font: MPUi.InfoFont
                color: MPUi.LightColor
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: lComments
                font: MPUi.InfoFont
                color: MPUi.LightColor
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: lResharers
                font: MPUi.InfoFont
                color: MPUi.LightColor
                anchors.verticalCenter: parent.verticalCenter
            }
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
