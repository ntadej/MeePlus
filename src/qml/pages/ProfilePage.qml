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
    id: profilePage
    anchors.topMargin: header.height
    anchors.margins: MPUi.DefaultMargin

    ListView {
        id: profileView
        anchors.fill: parent
        width: parent.width
        model: MPProfile
        pressDelay: 140

        delegate: ProfilePageDelegate {
            image: model.image
            name: model.name
            tagline: model.tagline

            gender: model.gender
            birthday: model.birthday
            location: model.currentLocation
            relationship: model.relationshipStatus
            about: model.aboutMe
        }
    }

    ScrollDecorator {
        flickableItem: profileView
    }

    PageHeader {
        id: header
        title: qsTr("Profile")
    }
}
