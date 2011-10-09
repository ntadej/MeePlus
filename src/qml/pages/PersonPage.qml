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

import "../js/core.js" as MPJs

Page {
    id: welcomePage
    tools: ToolBarLayout {
        id: welcomePageTools
        visible: true
        IconBack {}
        ButtonRow {
            platformStyle: TabButtonStyle { }
            TabButton {
                iconSource: "image://theme/icon-m-toolbar-contact"
                tab: profile
            }
            TabButton {
                iconSource: "image://theme/icon-m-toolbar-new-message"
                tab: activities
            }
        }
    }

    TabGroup {
        id: person
        currentTab: profile

        ProfilePage {
            id: profile
        }

        ActivitiesPage {
            id: activities
        }
    }

}
