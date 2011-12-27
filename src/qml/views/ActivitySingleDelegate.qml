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

Column {
    id: column

    property alias verb: activityHeader.verb
    property alias published: activityHeader.published

    property alias actorName: activityHeader.name
    property alias actorImage: activityHeader.image
    property alias actorOriginalId: originalActor.personId
    property alias actorOriginalName: originalActor.name
    property alias actorOriginalImage: originalActor.image

    property alias content: content.text
    property alias annotation: annotation.value
    property alias aTitle: aTitle.text
    property alias aContent: aContent.text
    property alias aUrl: aUrl.value

    property alias comments: comments.text
    property alias plusoners: plusoners.text
    property alias resharers: resharers.text

    property alias photo: photo.source
    property alias photoFull: photo.sourceFull
    property alias photoHeight: photo.fullHeight
    property alias photoWidth: photo.fullWidth

    width: parent.width

    ProfileHeader {
        id: activityHeader

        anchors.leftMargin: -MPUi.DefaultMargin
        anchors.rightMargin: -MPUi.DefaultMargin
    }

    SearchPersonDelegate {
        id: originalActor
        width: parent.width
        original: true
        visible: personId !== ""
    }

    Column {
        width: parent.width
        visible: annotation.value !== ""

        Spacer { }

        InfoElement {
            id: annotation
            name: activityHeader.name + " " + qsTr("annotated")
            width: parent.width
        }

        Spacer { }

        SeparatorColumn {
            anchors.leftMargin: -MPUi.DefaultMargin
            anchors.rightMargin: -MPUi.DefaultMargin
        }
    }

    Column {
        width: parent.width
        visible: content.text !== ""

        Spacer { }

        Label {
            id: content
            wrapMode: Text.WordWrap
            width: parent.width
        }

        Spacer { }

        SeparatorColumn {
            anchors.leftMargin: -MPUi.DefaultMargin
            anchors.rightMargin: -MPUi.DefaultMargin
        }
    }

    Column {
        width: parent.width
        visible: aTitle.text != ""

        Spacer { }

        LabelSubtitle {
            id: aTitle
        }

        Spacer { }

        Label {
            id: aContent
            wrapMode: Text.WordWrap
            width: parent.width
        }

        Spacer { }

        InfoElementSimple {
            id: aUrl
            url: true
            small: true
        }

        Spacer { }

        SeparatorColumn {
            anchors.leftMargin: -MPUi.DefaultMargin
            anchors.rightMargin: -MPUi.DefaultMargin
        }
    }

    Column {
        width: parent.width
        visible: photo.source != ""

        Spacer { }

        ImageAdvanced {
            id: photo
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Spacer { }

        SeparatorColumn {
            anchors.leftMargin: -MPUi.DefaultMargin
            anchors.rightMargin: -MPUi.DefaultMargin
        }
    }

    Column {
        width: parent.width

        Spacer { }

        Row {
            spacing: MPUi.DefaultMargin
            anchors.horizontalCenter: parent.horizontalCenter

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

        Spacer { }

        SeparatorColumn {
            anchors.leftMargin: -MPUi.DefaultMargin
            anchors.rightMargin: -MPUi.DefaultMargin
        }
    }

    Component.onCompleted: {
        activityView.height += column.height
    }
}
