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

#include <QtCore/QDebug>
#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>

#include "qmlapplicationviewer/qmlapplicationviewer.h"

#include "core/Authentication.h"
#include "core/Constants.h"
#include "core/Settings.h"
#include "plus/PeopleHandler.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    viewer.rootContext()->setContextProperty("MPCommon", MeePlus::Constants::common());
    viewer.rootContext()->setContextProperty("MPUi", MeePlus::Constants::ui());

    MPSettings *settings = new MPSettings();
    viewer.rootContext()->setContextProperty("MPSettings", settings);

    MPAuthentication *auth = new MPAuthentication();
    viewer.rootContext()->setContextProperty("MPAuth", auth);

    MPPeopleHandler *profile = new MPPeopleHandler();
    viewer.rootContext()->setContextProperty("MPProfile", auth);

    QObject::connect(profile, SIGNAL(requestAuthentication()), auth, SLOT(refreshToken()));
    QObject::connect(auth, SIGNAL(authenticated()), profile, SLOT(retry()));

    viewer.setMainQmlFile(QLatin1String("qml/main.qml"));
    viewer.showExpanded();

    // Tests
    profile->requestProfile("me");

    return app.exec();
}
