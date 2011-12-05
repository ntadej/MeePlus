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

    // Tests - only one active at a time!
    //_peopleHandler->requestProfile("me");
    //_peopleHandler->search("Larry Page");
}

MPApplication::~MPApplication()
{
    delete _authentication;
    delete _settings;

    // People
    delete _emails;
    delete _organizations;
    delete _urls;
    delete _peopleHandler;
    delete _peopleMain;
    delete _peopleSearch;
    delete _profileEmails;
    delete _profileOrganizations;
    delete _profileUrls;
    delete _profile;

    delete _viewer;
}

void MPApplication::initPeople()
{
    _peopleHandler = new MPPeopleHandler(this);
    _viewer->rootContext()->setContextProperty("MPPeople", _peopleHandler);

    connect(_peopleHandler, SIGNAL(requestAuthentication()), _authentication, SLOT(refreshToken()));
    connect(_authentication, SIGNAL(authenticated()), _peopleHandler, SLOT(retry()));

    _peopleMain = new MPPeopleModel(this);
    _profile = new MPPeopleFilterModel(this);
    _profile->setSourceModel(_peopleMain);
    _viewer->rootContext()->setContextProperty("MPProfile", _profile);
    _peopleSearch = 0;
    _search = new MPPeopleFilterModel(this);
    _viewer->rootContext()->setContextProperty("MPSearch", _search);

    _emails = new MPPeopleEmailsModel(this);
    _organizations = new MPPeopleOrganizationsModel(this);
    _urls = new MPPeopleUrlsModel(this);
    _profileEmails = new MPPeopleEmailsFilterModel(this);
    _profileEmails->setSourceModel(_emails);
    _viewer->rootContext()->setContextProperty("MPProfileEmails", _profileEmails);
    _profileOrganizations = new MPPeopleOrganizationsFilterModel(this);
    _profileOrganizations->setSourceModel(_organizations);
    _viewer->rootContext()->setContextProperty("MPProfileOrganizations", _profileOrganizations);
    _profileUrls = new MPPeopleUrlsFilterModel(this);
    _profileUrls->setSourceModel(_urls);
    _viewer->rootContext()->setContextProperty("MPProfileUrls", _profileUrls);

    connect(_peopleHandler, SIGNAL(newEmail(MPPersonEmail *)), _emails, SLOT(appendEmail(MPPersonEmail *)));
    connect(_peopleHandler, SIGNAL(newOrganization(MPPersonOrganization *)), _organizations, SLOT(appendOrganization(MPPersonOrganization *)));
    connect(_peopleHandler, SIGNAL(newUrl(MPPersonUrl *)), _urls, SLOT(appendUrl(MPPersonUrl *)));

    connect(_peopleHandler, SIGNAL(currentProfile(MPPerson *)), _peopleMain, SLOT(appendPerson(MPPerson *)));
    connect(_peopleHandler, SIGNAL(currentProfileId(QString)), this, SLOT(selectPerson(QString)));

    connect(_peopleHandler, SIGNAL(searchReset()), this, SLOT(initPeopleSearch()));
}

void MPApplication::initPeopleSearch()
{
    if (_peopleSearch) {
        disconnect(_peopleHandler, SIGNAL(searchPerson(MPPerson *)), _peopleSearch, SLOT(appendPerson(MPPerson *)));
        delete _peopleSearch;
    }

    _peopleSearch = new MPPeopleModel(this);
    _search->setSourceModel(_peopleSearch);
    connect(_peopleHandler, SIGNAL(searchPerson(MPPerson *)), _peopleSearch, SLOT(appendPerson(MPPerson *)));
}

void MPApplication::selectPerson(const QString &id)
{
    _profile->setId(id);

    if (!_peopleMain->find(id))
        return;

    _profileEmails->setPerson(id);
    _profileOrganizations->setPerson(id);
    _profileUrls->setPerson(id);
}
