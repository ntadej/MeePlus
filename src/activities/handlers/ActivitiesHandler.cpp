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
#include "activities/handlers/ActivitiesHandler.h"
#include "activities/items/Activity.h"
#include "people/items/Person.h"

MPActivitiesHandler::MPActivitiesHandler(QObject *parent)
    : QObject(parent)
{
    _nr = new MPNetworkRequest(this);
    connect(_nr, SIGNAL(error(int)), this, SLOT(error(int)));
    connect(_nr, SIGNAL(result(QString)), this, SLOT(activity(QString)));
}

MPActivitiesHandler::~MPActivitiesHandler()
{
    delete _nr;
}

void MPActivitiesHandler::activity(const QString &activity)
{
    JsonReader *reader = new JsonReader();
    reader->parse(activity);

    //qDebug() << reader->result();

    if (MeePlus::codec()->toUnicode(reader->result().toMap()["kind"].toByteArray()) == "plus#activity") {
        MPActivity *activity = new MPActivity(MeePlus::codec()->toUnicode(reader->result().toMap()["id"].toByteArray()));
        activity->setTitle(MeePlus::codec()->toUnicode(reader->result().toMap()["title"].toByteArray()));
        activity->setPublished(QDateTime::fromString(MeePlus::codec()->toUnicode(reader->result().toMap()["published"].toByteArray())));
        activity->setPublished(QDateTime::fromString(MeePlus::codec()->toUnicode(reader->result().toMap()["published"].toByteArray())));
        activity->setVerb(MeePlus::codec()->toUnicode(reader->result().toMap()["verb"].toByteArray()));
        // Date example "2011-12-17T11:04:51.095Z"

        MPPerson *actor = new MPPerson(MeePlus::codec()->toUnicode(reader->result().toMap()["actor"].toMap()["id"].toByteArray()));
        actor->setName(MeePlus::codec()->toUnicode(reader->result().toMap()["actor"].toMap()["displayName"].toByteArray()));
        actor->setImage(MeePlus::codec()->toUnicode(reader->result().toMap()["actor"].toMap()["image"].toMap()["url"].toByteArray()));
        activity->setActor(actor);

        emit currentActivity(activity);
        emit finishedActivity();
    } else if (MeePlus::codec()->toUnicode(reader->result().toMap()["kind"].toByteArray()) == "plus#activityFeed") {
        foreach (QVariant item, reader->result().toMap()["items"].toList()) {
            if (MeePlus::codec()->toUnicode(item.toMap()["kind"].toByteArray()) == "plus#activity") {
                MPActivity *activity = new MPActivity(MeePlus::codec()->toUnicode(item.toMap()["id"].toByteArray()));
                activity->setTitle(MeePlus::codec()->toUnicode(item.toMap()["title"].toByteArray()));
                activity->setPublished(QDateTime::fromString(MeePlus::codec()->toUnicode(item.toMap()["published"].toByteArray())));
                activity->setPublished(QDateTime::fromString(MeePlus::codec()->toUnicode(item.toMap()["published"].toByteArray())));
                activity->setVerb(MeePlus::codec()->toUnicode(item.toMap()["verb"].toByteArray()));

                MPPerson *actor = new MPPerson(MeePlus::codec()->toUnicode(item.toMap()["actor"].toMap()["id"].toByteArray()));
                actor->setName(MeePlus::codec()->toUnicode(item.toMap()["actor"].toMap()["displayName"].toByteArray()));
                actor->setImage(MeePlus::codec()->toUnicode(item.toMap()["actor"].toMap()["image"].toMap()["url"].toByteArray()));
                activity->setActor(actor);

                qDebug() << activity->title();

                emit newActivity(activity);
            }
        }

        _nextPage = MeePlus::codec()->toUnicode(reader->result().toMap()["nextPageToken"].toByteArray());
        qDebug() << "Next page:" << MeePlus::codec()->toUnicode(reader->result().toMap()["nextPageToken"].toByteArray());

        if (_primary)
            emit finishedList();
    }

    delete reader;
}

void MPActivitiesHandler::error(const int &err)
{
    if (err == 204)
        emit requestAuthentication();
}

void MPActivitiesHandler::list(const QString &person)
{
    emit reset();

    _currentPerson = person;
    _primary = true;
    _nextPage = "";

    listPrivate();
}

void MPActivitiesHandler::listNext()
{
    _primary = false;
    listPrivate();
}

void MPActivitiesHandler::listPrivate()
{
    if (_currentPerson.isEmpty())
        return;

    QNetworkRequest request;
    MPSettings *settings = new MPSettings(this);
    if (_nextPage.isEmpty()) {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/people/" + _currentPerson + "/activities/" + "public" + "?maxResults=10" + "&access_token=" + settings->accessToken()));
    } else {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/people/" + _currentPerson + "/activities/" + "public" + "?pageToken=" + _nextPage + "&maxResults=10" + "&access_token=" + settings->accessToken()));
    }
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    _nr->getRequest(request);
}


void MPActivitiesHandler::request(const QString &activity)
{
    _currentActivity = activity;

    MPSettings *settings = new MPSettings(this);
    QNetworkRequest request(QUrl("https://www.googleapis.com/plus/v1/activities/" + activity + "?access_token=" + settings->accessToken()));
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    _nr->getRequest(request);
}

void MPActivitiesHandler::retry()
{
    request(_currentActivity);
}

void MPActivitiesHandler::search(const QString &string)
{
    emit reset();

    _currentSearchString = string;
    _primary = true;
    _nextPage = "";

    searchPrivate();
}

void MPActivitiesHandler::searchNext()
{
    _primary = false;
    searchPrivate();
}

void MPActivitiesHandler::searchPrivate()
{
    if (_currentSearchString.isEmpty())
        return;

    QNetworkRequest request;
    MPSettings *settings = new MPSettings(this);
    if (_nextPage.isEmpty()) {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/activities?query=" + _currentSearchString + "&maxResults=10" + "&access_token=" + settings->accessToken()));
    } else {
        request = QNetworkRequest(QUrl("https://www.googleapis.com/plus/v1/activities?query=" + _currentSearchString + "&pageToken=" + _nextPage + "&maxResults=10" + "&access_token=" + settings->accessToken()));
    }
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    _nr->getRequest(request);
}
