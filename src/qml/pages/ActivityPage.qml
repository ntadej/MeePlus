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

Page {
    id: activityPage
    tools: ToolBarLayout {
        id: activityPageTools
        visible: true
        IconBack {}
        IconMenu {}
    }

    anchors.margins: MPUi.DefaultMargin
    anchors.topMargin: header.height

    ListView {
        id: activityView
        anchors.fill: parent
        width: parent.width
        model: MPActivity
        pressDelay: 140

        height: 44

        delegate: ActivitySingleDelegate {
            verb: model.verb
            published: model.published
            actorOriginalId: model.originalActorId
            actorOriginalImage: model.originalActorImage
            actorOriginalName: model.originalActorName

            actorName: model.actorName
            actorImage: model.actorImage

            content: model.content
            annotation: model.annotation
            aTitle: model.articleTitle
            aContent: model.articleContent
            aUrl: model.articleUrl

            comments: qsTr("Comments:") + " " + model.comments
            plusoners: qsTr("+1:") + " " + model.plusoners
            resharers: qsTr("Reshares:") + " " + model.resharers

            photo: model.photo
            photoFull: model.photoFull
            photoHeight: model.photoHeight
            photoWidth: model.photoWidth
        }
    }

    ScrollDecorator {
        flickableItem: activityView
    }

    PageHeader {
        id: header
        title: qsTr("Activity")
    }
}
