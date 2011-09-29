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

import QtQuick 1.0
import QtWebKit 1.0
import com.nokia.meego 1.0

Rectangle {
    property bool done: false;

    property alias title: webview.title
    property alias url: webview.url

    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    anchors.bottomMargin: -parent.anchors.bottomMargin
    anchors.leftMargin: -parent.anchors.leftMargin
    anchors.rightMargin: -parent.anchors.rightMargin

    WebView {
        id: webview

        anchors.fill: parent
        preferredHeight: height
        preferredWidth: width

        onLoadStarted: parent.state = "loading"
        onLoadFinished: parent.state = done ? "loading" : "base"
    }

    Rectangle {
        id: loading
        color: "white"
        opacity: 0

        BusyIndicator {
            id: indicator
            anchors.centerIn: parent
            platformStyle: BusyIndicatorStyle { size: "large" }
            running: true
        }

        anchors.fill: parent
    }

    states: [
        State {
            name: "loading"

            PropertyChanges {
                target: loading
                opacity: 100
            }
        }
    ]

    transitions: Transition {
        NumberAnimation { duration: 500; properties: "opacity"; easing.type: Easing.InOutQuad }
    }
}
