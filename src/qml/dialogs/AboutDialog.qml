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

QueryDialog {
    titleText: qsTr("About MeePlus " + MPCommon.MeePlusVersion)
    message: "© 2011 Tadej Novak\n\n" +
             qsTr("MeePlus is an unofficial Google+ client for Nokia N9. You can browse people, activities and other content on Google+.") +
             qsTr("\n\nNOTE:\nDue to current Google API restrictions only public content is available!")

    rejectButtonText: "Close"
}
