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
#include "core/Translations.h"
#include "json/json.h"
#include "people/handlers/PeopleHandler.h"
#include "people/items/Person.h"
#include "people/items/PersonInformation.h"
#include "people/items/PersonOrganization.h"

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

    qDebug() << profile;
    //qDebug() << reader->result();

    if (MPCommon::codec()->toUnicode(reader->result().toMap()["kind"].toByteArray()) == "plus#person") {
        MPPerson *person = new MPPerson(MPCommon::codec()->toUnicode(reader->result().toMap()["id"].toByteArray()));
        person->setName(MPCommon::codec()->toUnicode(reader->result().toMap()["displayName"].toByteArray()));
        person->setAboutMe(MPCommon::codec()->toUnicode(reader->result().toMap()["aboutMe"].toByteArray()));
        person->setBirthday(MPCommon::codec()->toUnicode(reader->result().toMap()["birthday"].toByteArray()));
        person->setCurrentLocation(MPCommon::codec()->toUnicode(reader->result().toMap()["currentLocation"].toByteArray()));
        person->setGender(MPTranslations::gender(MPCommon::codec()->toUnicode(reader->result().toMap()["gender"].toByteArray())));
        person->setImage(MPCommon::codec()->toUnicode(reader->result().toMap()["image"].toMap()["url"].toByteArray()).replace("sz=50","sz="));
        person->setNickname(MPCommon::codec()->toUnicode(reader->result().toMap()["nickname"].toByteArray()));
        person->setRelationshipStatus(MPTranslations::relationshipStatus(MPCommon::codec()->toUnicode(reader->result().toMap()["relationshipStatus"].toByteArray())));
        person->setTagline(MPCommon::codec()->toUnicode(reader->result().toMap()["tagline"].toByteArray()));
        person->setUrl(MPCommon::codec()->toUnicode(reader->result().toMap()["url"].toByteArray()));

        foreach (QVariant v, reader->result().toMap()["emails"].toList()) {
            MPPersonInformation *email = new MPPersonInformation(person->id(), MPCommon::codec()->toUnicode(v.toMap()["value"].toByteArray()));
            email->setType(MPCommon::codec()->toUnicode(v.toMap()["type"].toByteArray()));
            email->setPrimary(v.toMap()["primary"].toBool());

            emit newEmail(email);
        }

        foreach (QVariant v, reader->result().toMap()["organizations"].toList()) {
            MPPersonOrganization *org = new MPPersonOrganization(person->id(), MPCommon::codec()->toUnicode(v.toMap()["name"].toByteArray()));
            org->setDepartment(MPCommon::codec()->toUnicode(v.toMap()["department"].toByteArray()));
            org->setTitle(MPCommon::codec()->toUnicode(v.toMap()["title"].toByteArray()));
            org->setType(MPTranslations::organization(MPCommon::codec()->toUnicode(v.toMap()["type"].toByteArray())));
            org->setStartDate(MPCommon::codec()->toUnicode(v.toMap()["startDate"].toByteArray()));
            org->setEndDate(MPCommon::codec()->toUnicode(v.toMap()["endDate"].toByteArray()));
            org->setLocation(MPCommon::codec()->toUnicode(v.toMap()["location"].toByteArray()));
            org->setDescription(MPCommon::codec()->toUnicode(v.toMap()["description"].toByteArray()));
            org->setPrimary(v.toMap()["primary"].toBool());

            emit newOrganization(org);
        }

        foreach (QVariant v, reader->result().toMap()["placesLived"].toList()) {
            MPPersonInformation *place = new MPPersonInformation(person->id(), MPCommon::codec()->toUnicode(v.toMap()["value"].toByteArray()));
            place->setPrimary(v.toMap()["primary"].toBool());

            if(place->primary())
                place->setValue(place->value() + " " + tr("(Current)"));

            emit newPlace(place);
        }

        foreach (QVariant v, reader->result().toMap()["urls"].toList()) {
            MPPersonInformation *url = new MPPersonInformation(person->id(), MPCommon::codec()->toUnicode(v.toMap()["value"].toByteArray()));
            url->setType(MPCommon::codec()->toUnicode(v.toMap()["type"].toByteArray()));
            url->setPrimary(v.toMap()["primary"].toBool());

            emit newUrl(url);
        }

        QString id = person->id();

        emit currentProfile(person);
        emit currentProfileId(id);

        emit finishedProfile();
    } else if (MPCommon::codec()->toUnicode(reader->result().toMap()["kind"].toByteArray()) == "plus#peopleFeed") {
        foreach (QVariant item, reader->result().toMap()["items"].toList()) {
            if (MPCommon::codec()->toUnicode(item.toMap()["kind"].toByteArray()) == "plus#person") {
                MPPerson *person = new MPPerson(MPCommon::codec()->toUnicode(item.toMap()["id"].toByteArray()));
                person->setName(MPCommon::codec()->toUnicode(item.toMap()["displayName"].toByteArray()));
                person->setImage(MPCommon::codec()->toUnicode(item.toMap()["image"].toMap()["url"].toByteArray()).replace("sz=50","sz="));

                emit newPerson(person);
            }
        }

        _nextPage = MPCommon::codec()->toUnicode(reader->result().toMap()["nextPageToken"].toByteArray());
        qDebug() << "Next page:" << MPCommon::codec()->toUnicode(reader->result().toMap()["nextPageToken"].toByteArray());

        if (_primary)
            emit finishedSearch();
    }

    delete reader;
}

void MPPeopleHandler::request(const QString &profile)
{
    _currentProfile = profile;

    MPSettings *settings = new MPSettings(this);
    QNetworkRequest request(QUrl("https://www.googleapis.com/plus/v1/people/" + profile + "?access_token=" + settings->accessToken()));
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MPCommon::version()).toUtf8());

    _nr->getRequest(request);
}

void MPPeopleHandler::retry()
{
    request(_currentProfile);
}

void MPPeopleHandler::search(const QString &string)
{
    emit reset();

    _currentSearchString = string;
    _primary = true;
    _nextPage = "";

    searchPrivate();
}

void MPPeopleHandler::searchNext()
{
    _primary = false;
    searchPrivate();
}

void MPPeopleHandler::searchPrivate()
{
    if (_currentSearchString.isEmpty())
        return;

    QNetworkRequest request;
    MPSettings *settings = new MPSettings(this);
    if (_nextPage.isEmpty()) {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/people?query=" + _currentSearchString + "&maxResults=20" + "&access_token=" + settings->accessToken()));
    } else {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/people?query=" + _currentSearchString + "&pageToken=" + _nextPage + "&maxResults=20" + "&access_token=" + settings->accessToken()));
    }
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MPCommon::version()).toUtf8());

    _nr->getRequest(request);
}
