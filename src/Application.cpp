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
#include "people/handlers/PeopleHandler.h"
#include "people/items/Person.h"
#include "people/models/PeopleEmailsFilterModel.h"
#include "people/models/PeopleEmailsModel.h"
#include "people/models/PeopleFilterModel.h"
#include "people/models/PeopleModel.h"
#include "people/models/PeopleOrganizationsFilterModel.h"
#include "people/models/PeopleOrganizationsModel.h"
#include "people/models/PeopleUrlsFilterModel.h"
#include "people/models/PeopleUrlsModel.h"

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

    initPeople();

    _viewer->setMainQmlFile(QLatin1String("qml/main.qml"));
    _viewer->showExpanded();

    // Tests
    _people->requestProfile("me");
}

MPApplication::~MPApplication()
{
    delete _authentication;
    delete _currentEmails;
    delete _currentOrganizations;
    delete _currentUrls;
    delete _people;
    delete _profileModel;
    delete _profile;
    delete _settings;

    delete _viewer;
}

void MPApplication::initPeople()
{
    _people = new MPPeopleHandler(this);
    _viewer->rootContext()->setContextProperty("MPPeople", _people);

    connect(_people, SIGNAL(requestAuthentication()), _authentication, SLOT(refreshToken()));
    connect(_authentication, SIGNAL(authenticated()), _people, SLOT(retry()));

    _profileModel = new MPPeopleModel(this);
    _profile = new MPPeopleFilterModel(this);
    _profile->setSourceModel(_profileModel);
    _viewer->rootContext()->setContextProperty("MPProfile", _profile);

    _currentEmails = new MPPeopleEmailsFilterModel(this);
    _viewer->rootContext()->setContextProperty("MPProfileEmails", _currentEmails);
    _currentOrganizations = new MPPeopleOrganizationsFilterModel(this);
    _viewer->rootContext()->setContextProperty("MPProfileOrganizations", _currentOrganizations);
    _currentUrls = new MPPeopleUrlsFilterModel(this);
    _viewer->rootContext()->setContextProperty("MPProfileUrls", _currentUrls);

    connect(_people, SIGNAL(currentProfile(MPPerson *)), this, SLOT(selectPerson(MPPerson *)));
}

void MPApplication::selectPerson(MPPerson *person)
{
    _profileModel->addSinglePerson(person);

    _currentEmails->setSourceModel(person->emails());
    _currentOrganizations->setSourceModel(person->organizations());
    _currentUrls->setSourceModel(person->urls());
}
