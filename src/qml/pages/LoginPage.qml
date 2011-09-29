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
import QtWebKit 1.0
import com.nokia.meego 1.0

import "../common"

import "../js/core.js" as MeePlusJs

Page {
    id: welcomePage
    anchors.margins: MeePlusUi.DefaultMargin
    tools: ToolBarLayout {
        id: welcomePageTools
        visible: true
        ButtonOrientation {}
        IconMenu {}
    }

    WebView {
        id: login
        url: "https://accounts.google.com/o/oauth2/auth?client_id=" + MeePlusCommon.GoogleClientId + "&redirect_uri=urn:ietf:wg:oauth:2.0:oob&scope=https://www.google.com/m8/feeds/&response_type=code"

        preferredHeight: height
        preferredWidth: width

        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -parent.anchors.bottomMargin
        anchors.leftMargin: -parent.anchors.leftMargin
        anchors.rightMargin: -parent.anchors.rightMargin

        onTitleChanged: { visible: MeePlusJs.validateLogin(title); console.debug(title); console.debug(MeePlusJs.validateLogin(title)) }
    }

    PageHeader {
        id: header

        title: "MeePlus (Alpha)"
    }
}
