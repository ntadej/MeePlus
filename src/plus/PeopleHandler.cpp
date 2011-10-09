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
#include "plus/PeopleHandler.h"

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
    if(err == 204)
        emit requestAuthentication();
}

void MPPeopleHandler::profile(const QString &profile)
{
    JsonReader *reader = new JsonReader();
    reader->parse(profile);

    qDebug() << profile;
    qDebug() << reader->result();

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
