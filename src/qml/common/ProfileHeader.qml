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

Item {
    property alias image: icon.image
    property alias name: name.text

    property alias tagline: tagline.text

    property alias verb: verb.text
    property alias published: published.text

    anchors.left: parent.left
    anchors.right: parent.right

    height: column.height < 80 ? 80 + 2*MPUi.DefaultMargin : column.height + 2*MPUi.DefaultMargin

    ItemBackground { }

    Separator { }

    Avatar {
        id: icon
        active: true
        large: true
        anchors.left: parent.left
        anchors.margins: MPUi.DefaultMargin
        anchors.verticalCenter: parent.verticalCenter
    }

    Column {
        id: column
        anchors.left: icon.right
        anchors.right: parent.right
        anchors.leftMargin: MPUi.DefaultMargin
        anchors.verticalCenter: parent.verticalCenter

         LabelTitle {
             id: name
         }

         LabelSubtitle {
             id: tagline
             visible: text !== ""
         }

         Row {
             spacing: MPUi.DefaultMargin / 2

             LabelSmall {
                 id: verb
                 visible: text !== ""
             }

             LabelSmall {
                 id: published
                 visible: text !== ""
             }
         }
    }
}
