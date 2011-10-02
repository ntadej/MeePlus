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

#include <QtCore/QDir>

#include "core/Common.h"
#include "core/Settings.h"

// Define defaults - General
const bool MPSettings::DEFAULT_CONFIGURED = false;
// Authentication
const QString MPSettings::DEFAULT_NAME = "Google";
// Theme
const bool MPSettings::DEFAULT_INVERTED = false;

MPSettings::MPSettings(QObject *parent)
    : QSettings(QSettings::IniFormat,
                QSettings::UserScope,
                "MeePlus",
                "Main",
                parent)
{
    readSettings();
}

MPSettings::~MPSettings() { }

void MPSettings::readSettings()
{
    setConfigurationVersion(value("general/version", MeePlus::version()).toString());
    setConfigured(value("general/configured", DEFAULT_CONFIGURED).toBool());
    setLanguage(value("general/language").toString());

    setName(value("auth/name", DEFAULT_NAME).toString());
    setAccessToken(value("auth/access-token").toString());
    setRefreshToken(value("auth/refresh-token").toString());

    setInverted(value("theme/inverted", DEFAULT_INVERTED).toBool());
}

void MPSettings::writeSettings()
{
    setValue("general/version", configurationVersion());
    setValue("general/configured", configured());
    setValue("general/language", language());

    setValue("auth/name", name());
    setValue("auth/access-token", accessToken());
    setValue("auth/refresh-token", refreshToken());

    setValue("theme/inverted", inverted());

    sync();
}
