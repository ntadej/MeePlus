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

#include <QtDeclarative/QDeclarativeContext>

#include "Application.h"

#include "qmlapplicationviewer/qmlapplicationviewer.h"

#include "core/Authentication.h"
#include "core/Constants.h"
#include "core/Settings.h"
#include "models/PeopleFilterModel.h"
#include "models/PeopleModel.h"
#include "plus/PeopleHandler.h"

MPApplication::MPApplication(QObject *parent)
    : QObject(parent)
{
    _viewer = new QmlApplicationViewer();
    _viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);

    _viewer->rootContext()->setContextProperty("MPCommon", MeePlus::Constants::common());
    _viewer->rootContext()->setContextProperty("MPUi", MeePlus::Constants::ui());

    _settings = new MPSettings(this);
    _viewer->rootContext()->setContextProperty("MPSettings", _settings);

    _authentication = new MPAuthentication(this);
    _viewer->rootContext()->setContextProperty("MPAuthentication", _authentication);

    _people = new MPPeopleHandler(this);
    _viewer->rootContext()->setContextProperty("MPPeople", _people);

    connect(_people, SIGNAL(requestAuthentication()), _authentication, SLOT(refreshToken()));
    connect(_authentication, SIGNAL(authenticated()), _people, SLOT(retry()));

    _profile = new MPPeopleModel(this);
    _profileF = new MPPeopleFilterModel(this);
    _profileF->setSourceModel(_profile);
    _viewer->rootContext()->setContextProperty("MPProfile", _profileF);

    connect(_people, SIGNAL(currentProfile(MPPerson *)), _profile, SLOT(addSinglePerson(MPPerson *)));

    _viewer->setMainQmlFile(QLatin1String("qml/main.qml"));
    _viewer->showExpanded();

    // Tests
    _people->requestProfile("me");
}

MPApplication::~MPApplication()
{
    delete _authentication;
    delete _people;
    delete _profileF;
    delete _profile;
    delete _settings;

    delete _viewer;
}
