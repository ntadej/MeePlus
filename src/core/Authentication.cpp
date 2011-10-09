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

#include "core/Authentication.h"
#include "core/Common.h"
#include "core/NetworkRequest.h"
#include "core/Settings.h"
#include "json/json.h"

MPAuthentication::MPAuthentication(QObject *parent)
    : QObject(parent)
{
    _nr = new MPNetworkRequest(this);
    connect(_nr, SIGNAL(error(int)), this, SLOT(error(int)));
    connect(_nr, SIGNAL(result(QString)), this, SLOT(token(QString)));
}

MPAuthentication::~MPAuthentication()
{
    delete _nr;
}

void MPAuthentication::error(const int &err)
{
    if(err == 204)
        refreshToken();
}

void MPAuthentication::refreshToken()
{
    QNetworkRequest request(QUrl("https://accounts.google.com/o/oauth2/token"));
    request.setRawHeader("Host", "accounts.google.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    MPSettings *settings = new MPSettings(this);
    QString refresh = settings->refreshToken();
    delete settings;

    QString data = "client_id=" + MeePlus::clientId() + "&"
            "client_secret=" + MeePlus::clientSecret() + "&"
            "refresh_token=" + refresh + "&"
            "grant_type=refresh_token";

    qDebug() << data.toUtf8();

    _nr->postRequest(request, data.toUtf8());
}

void MPAuthentication::requestToken(const QString &code)
{
    QNetworkRequest request(QUrl("https://accounts.google.com/o/oauth2/token"));
    request.setRawHeader("Host", "accounts.google.com");
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setRawHeader("User-Agent", QString("MeePlus " + MeePlus::version()).toUtf8());

    QString data = "client_id=" + MeePlus::clientId() + "&"
            "client_secret=" + MeePlus::clientSecret() + "&"
            "code=" + code + "&"
            "redirect_uri=urn:ietf:wg:oauth:2.0:oob&"
            "grant_type=authorization_code";

    qDebug() << data.toUtf8();

    _nr->postRequest(request, data.toUtf8());
}

QString MPAuthentication::requestUrl() const
{
    QString url = "https://accounts.google.com/o/oauth2/auth?"
            "client_id=" + MeePlus::clientId() + "&"
            "redirect_uri=urn:ietf:wg:oauth:2.0:oob&"
            "scope=https://www.googleapis.com/auth/plus.me&"
            "response_type=code";
    return url;
}

bool MPAuthentication::responseCode(const QString &title)
{
    if(!title.contains("code"))
        return false;

    QRegExp exp(".*=(.*)");
    exp.indexIn(title);
    qDebug() << exp.cap(1);

    QString code = exp.cap(1);
    requestToken(code);

    return true;
}

void MPAuthentication::token(const QString &token)
{
    JsonReader *reader = new JsonReader();
    reader->parse(token);

    MPSettings *settings = new MPSettings(this);
    settings->setRefreshToken(reader->result().toMap()["refresh_token"].toString());
    settings->setAccessToken(reader->result().toMap()["access_token"].toString());
    settings->writeSettings();

    qDebug() << token;
    qDebug() << settings->refreshToken() << settings->accessToken();
    delete settings;

    delete reader;

    emit authenticated();
}
