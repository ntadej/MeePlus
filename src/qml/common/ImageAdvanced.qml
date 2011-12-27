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

Image {
    id: imageAdvanced

    property alias sourceFull: imageLarge.source
    property int fullHeight: 0
    property int fullWidth: 0

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: imageDialog.open()
    }

    Dialog {
        id: imageDialog
        //width: 480
        //height: 480
        anchors.margins: 0
        content: Image {
            id: imageLarge
            height: fullHeight
            width: fullWidth
        }
    }
}
