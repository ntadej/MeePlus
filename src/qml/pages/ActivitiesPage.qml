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
import "../views"

Page {
    id: activitiesPage
    anchors.margins: MPUi.DefaultMargin
    anchors.topMargin: header.height

    ListView {
        id: activitiesView
        anchors.fill: parent
        width: parent.width
        model: MPActivitiesList
        pressDelay: 140

        height: 44

        delegate: ActivityDelegate {
            title: model.title
            verb: model.verb
            published: model.published
            actorOriginal: model.originalActorName !== "" ? (qsTr("Original post by:") + " " + model.originalActorName) : ""

            actorName: model.actorName
            actorImage: model.actorImage

            comments: qsTr("Comments:") + " " + model.comments
            plusoners: qsTr("+1:") + " " + model.plusoners
            resharers: qsTr("Reshares:") + " " + model.resharers

            photo: model.photo
        }

        footer: Item {
            id: activitiesFooter
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
                onClicked: MPActivities.listNext()
            }
        }
    }

    ScrollDecorator {
        flickableItem: activitiesView
    }

    PageHeader {
        id: header
        title: qsTr("Activities")
    }
}
