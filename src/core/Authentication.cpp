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

#include "Authentication.h"

MPAuthentication::MPAuthentication(QObject *parent)
    : QObject(parent)
{

}

MPAuthentication::~MPAuthentication()
{

}


QString MPAuthentication::requestUrl() const
{
    QString clientId;
#ifdef CLIENT_ID
    clientId = QString().number(CLIENT_ID) + ".apps.googleusercontent.com";
#else
    return QString("error");
#endif

    QString url = "https://accounts.google.com/o/oauth2/auth?"
            "client_id=" + clientId + "&"
            "redirect_uri=urn:ietf:wg:oauth:2.0:oob&"
            "scope=https://www.googleapis.com/auth/plus.me&"
            "response_type=code";
    return url;
}

bool MPAuthentication::responseCode(const QString &title) const
{
    if(!title.contains("code"))
        return false;

    QRegExp exp(".*=(.*)");
    exp.indexIn(title);
    qDebug() << exp.cap(1);

    return true;
}
