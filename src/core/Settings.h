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

#ifndef MEEPLUS_SETTINGS_H_
#define MEEPLUS_SETTINGS_H_

#include <QtCore/QSettings>

class MPSettings : public QSettings
{
Q_OBJECT
public:
    MPSettings(QObject * parent = 0);
    ~MPSettings();

    Q_INVOKABLE void readSettings();
    Q_INVOKABLE void writeSettings();

    // General
    Q_INVOKABLE inline QString language() const { return _language; }
    Q_INVOKABLE inline void setLanguage(const QString &s) { _language = s; }

    // Authentication
    inline QString accessToken() const { return _accessToken; }
    inline void setAccessToken(const QString &s) { _accessToken = s; }
    inline QString refreshToken() const { return _refreshToken; }
    inline void setRefreshToken(const QString &s) { _refreshToken = s; }

private:
    // General
    QString _language;

    // Authentication
    QString _accessToken;
    QString _refreshToken;
};

#endif // MEEPLUS_SETTINGS_H_
