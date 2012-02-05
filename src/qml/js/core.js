/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
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

// Main
function addPage(file) {
    var component = Qt.createComponent(file)

    if (component.status === Component.Ready) {
        pageStack.push(component);
    } else {
        console.log("Error loading component:", component.errorString());
    }
}

function replacePage(file) {
    var component = Qt.createComponent(file)

    if (component.status === Component.Ready) {
        pageStack.replace(component);
    } else {
        console.log("Error loading component:", component.errorString());
    }
}

function removePage() {
    pageStack.pop()
}

function myProfile() {
    MPActivities.list("me");
    MPPeople.request("me");
}

function settings() {

}

// Login
function validateLogin(title) {
    return title.indexOf("code") !== -1
}

// Page stack
function addActivityPage(activityId) {
    addPage(MPCommon.Path + "pages/ActivityPage.qml")
    MPPageStack.addActivityPage(activityId)
}

function addLoginPage() {
    addPage(MPCommon.Path + "pages/LoginPage.qml")
    MPPageStack.addGenericPage()
}

function addPersonPage(personId) {
    addPage(MPCommon.Path + "pages/PersonPage.qml")
    MPPageStack.addPersonPage(personId)
}

function addSearchPage() {
    addPage(MPCommon.Path + "pages/SearchPage.qml")
    MPPageStack.addGenericPage()
}

function addSearchResultsPage() {
    addPage(MPCommon.Path + "pages/SearchResultsPage.qml")
    MPPageStack.addGenericPage()
}

function addSettingsPage() {
    addPage(MPCommon.Path + "pages/SettingsPage.qml")
    MPPageStack.addGenericPage()
}
