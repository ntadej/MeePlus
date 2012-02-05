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

#include <QtCore/QRegExp>
#include <QtCore/QUrl>
#include <QtGui/QTextEdit>
#include <QtNetwork/QNetworkRequest>

#include "core/Common.h"
#include "core/NetworkRequest.h"
#include "core/Settings.h"
#include "core/Translations.h"
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

    if (reader->result().toMap()["kind"].toString() == "plus#activity") {
        MPActivity *activity = processActivity(reader->result().toMap());

        emit currentActivity(activity);
        emit finishedActivity();
    } else if (reader->result().toMap()["kind"].toString() == "plus#activityFeed") {
        foreach (QVariant item, reader->result().toMap()["items"].toList()) {
            if (item.toMap()["kind"].toString() == "plus#activity") {
                MPActivity *activity = processActivity(item.toMap());

                emit newActivity(activity);
            }
        }

        _nextPage = reader->result().toMap()["nextPageToken"].toString();

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
    request.setRawHeader("User-Agent", QString("MeePlus " + MPCommon::version()).toUtf8());

    _nr->getRequest(request);
}

MPActivity *MPActivitiesHandler::processActivity(const QVariantMap &map)
{
    QRegExp reshared("(Reshared post from .*\n)");
    QTextEdit text;

    MPActivity *activity = new MPActivity(map["id"].toString());
    activity->setTitle(map["title"].toString().replace(reshared, ""));
    text.setHtml(map["object"].toMap()["content"].toString());
    activity->setContent(text.toPlainText());
    activity->setAnnotation(map["annotation"].toString());
    activity->setPublished(QDateTime::fromString(map["published"].toString(), Qt::ISODate));
    activity->setPublished(QDateTime::fromString(map["published"].toString(), Qt::ISODate));
    activity->setVerb(MPTranslations::activityVerb(map["verb"].toString()));

    MPPerson *actor = new MPPerson(map["actor"].toMap()["id"].toString());
    actor->setName(map["actor"].toMap()["displayName"].toString());
    actor->setImage(map["actor"].toMap()["image"].toMap()["url"].toString().replace("sz=50","sz="));
    activity->setActor(actor);

    MPPerson *originalActor = new MPPerson(map["object"].toMap()["actor"].toMap()["id"].toString());
    originalActor->setName(map["object"].toMap()["actor"].toMap()["displayName"].toString());
    originalActor->setImage(map["object"].toMap()["actor"].toMap()["image"].toMap()["url"].toString().replace("sz=50","sz="));
    activity->setOriginalActor(originalActor);

    activity->setComments((map["object"].toMap()["replies"].toMap()["totalItems"].toInt()));
    activity->setPlusoners((map["object"].toMap()["plusoners"].toMap()["totalItems"].toInt()));
    activity->setResharers((map["object"].toMap()["resharers"].toMap()["totalItems"].toInt()));

    foreach (QVariant item, map["object"].toMap()["attachments"].toList()) {
        if (item.toMap()["objectType"].toString() == "article") {
            text.setHtml(item.toMap()["displayName"].toString());
            activity->setArticleTitle(text.toPlainText());
            text.setHtml(item.toMap()["content"].toString());
            activity->setArticleContent(text.toPlainText());
            activity->setArticleUrl(item.toMap()["url"].toString());
        } else if (item.toMap()["objectType"].toString() == "photo") {
            activity->setPhoto(QUrl::fromEncoded(item.toMap()["image"].toMap()["url"].toByteArray()).toString());
            activity->setPhotoFull(QUrl::fromEncoded(item.toMap()["fullImage"].toMap()["url"].toByteArray()).toString());
            activity->setPhotoHeight(item.toMap()["fullImage"].toMap()["height"].toInt());
            activity->setPhotoWidth(item.toMap()["fullImage"].toMap()["width"].toInt());
        }
    }

    return activity;
}

void MPActivitiesHandler::request(const QString &activity)
{
    _currentActivity = activity;

    MPSettings *settings = new MPSettings(this);
    QNetworkRequest request(QUrl("https://www.googleapis.com/plus/v1/activities/" + activity + "?access_token=" + settings->accessToken()));
    delete settings;

    request.setRawHeader("Host", "www.googleapis.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MPCommon::version()).toUtf8());

    _nr->getRequest(request);
}

void MPActivitiesHandler::retry()
{
    request(_currentActivity);
    list(_currentPerson);
    search(_currentSearchString);
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
    request.setRawHeader("User-Agent", QString("MeePlus " + MPCommon::version()).toUtf8());

    _nr->getRequest(request);
}
