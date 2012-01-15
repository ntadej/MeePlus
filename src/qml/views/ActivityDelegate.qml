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

Item {
    property string activityId: ""

    property alias title: title.text
    property alias verb: verb.text
    property alias published: published.text

    property alias actorName: aName.text
    property alias actorImage: aIcon.image
    property alias actorOriginal: aOriginal.text

    property alias comments: comments.text
    property alias plusoners: plusoners.text
    property alias resharers: resharers.text

    property alias photo: photo.source

    width: parent.width
    height: column.height + 2 * MPUi.DefaultMargin

    ItemBackground {
        id: itemBackground
        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
        visible: mouseAreaItem.pressed
    }

    Separator {
        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
    }

    IconListArrow { }

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
                LabelTitle {
                    id: aName
                }

                Row {
                    spacing: MPUi.DefaultMargin / 2

                    LabelSmall {
                        id: verb
                    }

                    LabelSmall {
                        id: published
                    }
                }

                LabelSmall {
                    id: aOriginal
                    visible: text !== ""
                }
            }
        }

        Label {
            id: title
            wrapMode: Text.WordWrap
            width: parent.width
        }

        Image {
            id: photo
        }

        Row {
            spacing: MPUi.DefaultMargin

            LabelSmall {
                id: plusoners
                anchors.verticalCenter: parent.verticalCenter
            }

            LabelSmall {
                id: comments
                anchors.verticalCenter: parent.verticalCenter
            }

            LabelSmall {
                id: resharers
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    MouseArea {
        id: mouseAreaItem
        anchors.fill: itemBackground
        onClicked: {
            MPActivity.setId(activityId)
            personPage.showActivity()
        }
    }

    Component.onCompleted: {
        activitiesView.height += column.height
    }
}
