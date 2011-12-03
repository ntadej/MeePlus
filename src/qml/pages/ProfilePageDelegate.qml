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

Column {
    id: column

    property alias image: profileHeader.image
    property alias name: profileHeader.name
    property alias tagline: profileHeader.tagline

    property alias gender: iGender.value
    property alias birthday: iBirthday.value
    property alias location: iLocation.value
    property alias relationship: iRelationship.value
    property alias about: iAbout.value

    width: parent.width
    ProfileHeader {
        id: profileHeader
    }
    Spacer { }

    SectionHeader {
        id: basicInfo
        name: qsTr("Basic information")
    }
    InfoElement {
        id: iGender
        name: qsTr("Gender")
    }
    Spacer { height: MPUi.DefaultMargin/2; visible: iGender.visible }
    InfoElement {
        id: iBirthday
        name: qsTr("Birthday")
    }
    Spacer { height: MPUi.DefaultMargin/2; visible: iBirthday.visible }
    InfoElement {
        id: iLocation
        name: qsTr("Current location")
    }
    Spacer { height: MPUi.DefaultMargin/2; visible: iLocation.visible }
    InfoElement {
        id: iRelationship
        name: qsTr("Relationship status")
    }
    Spacer { height: MPUi.DefaultMargin/2; visible: iRelationship.visible }
    Spacer { height: MPUi.DefaultMargin/2}

    SectionHeader {
        id: aboutInfo
        name: qsTr("About me")
        visible: iAbout.visible
    }
    InfoElement {
        id: iAbout
    }
    Spacer { visible: iAbout.visible }

    EmailsList {
        id: emailsList
        visible: count
    }
    Spacer { visible: emailsList.visible }
    UrlsList {
        id: urlsList
        visible: count
    }
    Spacer { visible: urlsList.visible }
    OrganizationsList {
        id: organizationsList
        visible: count
    }
    Spacer { visible: organizationsList.visible }

    Component.onCompleted: {
        profileView.height += column.height
    }
}
