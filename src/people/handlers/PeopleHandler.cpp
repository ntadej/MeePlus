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
#include <QtCore/QRegExp>
#include <QtCore/QUrl>
#include <QtNetwork/QNetworkRequest>

#include "core/Common.h"
#include "core/NetworkRequest.h"
#include "core/Settings.h"
#include "json/json.h"
#include "people/handlers/PeopleHandler.h"
#include "people/items/Person.h"
#include "people/items/PersonEmail.h"
#include "people/items/PersonOrganization.h"
#include "people/items/PersonUrl.h"

MPPeopleHandler::MPPeopleHandler(QObject *parent)
    : QObject(parent)
{
    _nr = new MPNetworkRequest(this);
    connect(_nr, SIGNAL(error(int)), this, SLOT(error(int)));
    connect(_nr, SIGNAL(result(QString)), this, SLOT(profile(QString)));
}

MPPeopleHandler::~MPPeopleHandler()
{
    delete _nr;
}

void MPPeopleHandler::error(const int &err)
{
    if (err == 204)
        emit requestAuthentication();
}

void MPPeopleHandler::profile(const QString &profile)
{
    JsonReader *reader = new JsonReader();
    reader->parse(profile);

    //qDebug() << profile;
    qDebug() << reader->result();

    if (reader->result().toMap()["kind"].toString() == "plus#person") {
        MPPerson *person = new MPPerson(reader->result().toMap()["id"].toString());
        person->setName(reader->result().toMap()["displayName"].toString());
        person->setAboutMe(reader->result().toMap()["aboutMe"].toString());
        person->setBirthday(reader->result().toMap()["birthday"].toString());
        person->setCurrentLocation(reader->result().toMap()["currentLocation"].toString());
        person->setGender(reader->result().toMap()["gender"].toString());
        person->setImage(reader->result().toMap()["image"].toMap()["url"].toString());
        person->setNickname(reader->result().toMap()["nickname"].toString());
        person->setRelationshipStatus(reader->result().toMap()["relationshipStatus"].toString());
        person->setTagline(reader->result().toMap()["tagline"].toString());
        person->setUrl(reader->result().toMap()["url"].toString());

        foreach (QVariant v, reader->result().toMap()["emails"].toList()) {
            MPPersonEmail *email = new MPPersonEmail(person->id(), v.toMap()["value"].toString());
            email->setType(v.toMap()["type"].toString());
            email->setPrimary(v.toMap()["primary"].toBool());

            emit newEmail(email);
        }

        foreach (QVariant v, reader->result().toMap()["organizations"].toList()) {
            MPPersonOrganization *org = new MPPersonOrganization(person->id(), v.toMap()["name"].toString());
            org->setDepartment(v.toMap()["department"].toString());
            org->setTitle(v.toMap()["title"].toString());
            org->setType(v.toMap()["type"].toString());
            org->setStartDate(v.toMap()["startDate"].toString());
            org->setEndDate(v.toMap()["endDate"].toString());
            org->setLocation(v.toMap()["location"].toString());
            org->setDescription(v.toMap()["description"].toString());
            org->setPrimary(v.toMap()["primary"].toBool());

            emit newOrganization(org);
        }

        foreach (QVariant v, reader->result().toMap()["urls"].toList()) {
            MPPersonUrl *url = new MPPersonUrl(person->id(), v.toMap()["value"].toString());
            url->setType(v.toMap()["type"].toString());
            url->setPrimary(v.toMap()["primary"].toBool());

            emit newUrl(url);
        }

        QString id = person->id();

        emit currentProfile(person);
        emit currentProfileId(id);

        emit finishedProfile();
    } else if (reader->result().toMap()["kind"].toString() == "plus#peopleFeed") {
        foreach (QVariant item, reader->result().toMap()["items"].toList()) {
            if (item.toMap()["kind"].toString() == "plus#person") {
                MPPerson *person = new MPPerson(item.toMap()["id"].toString());
                person->setName(item.toMap()["displayName"].toString());
                person->setImage(item.toMap()["image"].toMap()["url"].toString());

                emit searchPerson(person);
            }
        }

        emit finishedSearch();
    }

    delete reader;
}

void MPPeopleHandler::requestProfile(const QString &profile)
{
    _currentProfile = profile;

    MPSettings *settings = new MPSettings(this);
    QNetworkRequest request(QUrl("https://www.googleapis.com/plus/v1/people/" + profile + "?access_token=" + settings->accessToken()));
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    _nr->getRequest(request);
}

void MPPeopleHandler::retry()
{
    requestProfile(_currentProfile);
}

void MPPeopleHandler::search(const QString &string)
{
    emit searchReset();

    _currentSearchString = string;

    MPSettings *settings = new MPSettings(this);
    QNetworkRequest request(QUrl("https://www.googleapis.com/plus/v1/people?query=" + string + "&access_token=" + settings->accessToken()));
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    _nr->getRequest(request);
}
