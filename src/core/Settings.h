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
    inline QString configurationVersion() { return _configurationVersion; }
    inline void setConfigurationVersion(const QString &s) { _configurationVersion = s; }
    inline bool configured() const { return _configured; }
    inline void setConfigured(const bool &b) { _configured = b; }
    static const bool DEFAULT_CONFIGURED;
    Q_INVOKABLE inline QString language() const { return _language; }
    Q_INVOKABLE inline void setLanguage(const QString &s) { _language = s; }

    // Authentication
    Q_INVOKABLE inline QString name() const { return _name; }
    Q_INVOKABLE inline void setName(const QString &s) { _name = s; }
    static const QString DEFAULT_NAME;
    inline QString accessToken() const { return _accessToken; }
    inline void setAccessToken(const QString &s) { _accessToken = s; }
    inline QString refreshToken() const { return _refreshToken; }
    inline void setRefreshToken(const QString &s) { _refreshToken = s; }

    // Theme
    Q_INVOKABLE inline bool inverted() const { return _inverted; }
    Q_INVOKABLE inline void setInverted(const bool &b) { _inverted = b; }
    static const bool DEFAULT_INVERTED;

private:
    // General variables
    QString _configurationVersion;
    bool _configured;
    QString _language;

    // Authentication
    QString _name;
    QString _accessToken;
    QString _refreshToken;

    // Theme
    bool _inverted;
};

#endif // MEEPLUS_SETTINGS_H_
