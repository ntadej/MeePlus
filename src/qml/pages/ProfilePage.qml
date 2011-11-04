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

import "../js/core.js" as MPJs

Page {
    id: profilePage
    anchors.topMargin: header.height

    ListView {
        id: listView
        anchors.fill: parent
        width: parent.width
        model: MPProfile
        pressDelay: 140

        delegate:  Item {
            id: listItem
            width: parent.width
            height: 100

            Column {
                anchors.fill: parent
                spacing: MPUi.DefaultMargin
                ProfileHeader {
                    id: profileHeader
                    image: model.image
                    name: model.name
                    tagline: model.tagline
                }

                SectionHeader {
                    id: basicInfo
                    name: qsTr("Basic information")
                }
                InfoElement {
                    name: qsTr("Gender")
                    value: model.gender
                }
                InfoElement {
                    name: qsTr("Birthday")
                    value: model.birthday
                }
                InfoElement {
                    name: qsTr("Current location")
                    value: model.currentLocation
                }
                InfoElement {
                    name: qsTr("Relationship status")
                    value: model.relationshipStatus
                }

                SectionHeader {
                    id: aboutInfo
                    name: qsTr("About me")
                }
                InfoElement {
                    value: model.aboutMe
                }
            }
        }
    }
    ScrollDecorator {
        flickableItem: listView
    }

    PageHeader {
        id: header
        title: qsTr("Profile")
    }
}
