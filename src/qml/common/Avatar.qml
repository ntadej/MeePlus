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
    id: avatar

    property bool active: false

    width: 50
    height: 50

    BorderImage {
        id: mask
        anchors.fill: parent
        source: active ? "../images/avatar-mask-active.png" : "../images/avatar-mask.png"
    }

    BorderImage {
        id: frame
        anchors.fill: parent
        source: "../images/avatar-frame.png"
    }
}
