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

#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QSettings>

#include "core/Common.h"
#include "core/Config.h"

QString MeePlus::clientId()
{
    QString clientId = "";
#ifdef CLIENT_ID
    clientId = QString(CLIENT_ID);
#endif

    return clientId;
}

QString MeePlus::clientSecret()
{
    QString clientSecret = "";
#ifdef CLIENT_SECRET
    clientSecret = QString(CLIENT_SECRET);
#endif

    return clientSecret;
}

QString MeePlus::locateResource(const QString &file)
{
    QString path;

    if (QFileInfo(file).exists())
        path = QFileInfo(file).absoluteFilePath();

    // Try application exe working path
    else if (QFileInfo(QDir::currentPath() + "/" + file).exists())
        path = QFileInfo(QDir::currentPath() + "/" + file).absoluteFilePath();

    // Try application exe directory
    else if (QFileInfo(QCoreApplication::applicationDirPath() + "/" + file).exists())
        path = QFileInfo(QCoreApplication::applicationDirPath() + "/" + file).absoluteFilePath();

    // Try installation directory
    else if (QFileInfo("/opt/meeplus/share/" + file).exists())
        path = QFileInfo("/opt/meeplus/share/" + file).absoluteFilePath();

    return path;
}

QString MeePlus::settingsPath()
{
    QSettings *settings = new QSettings(QSettings::IniFormat,
                                        QSettings::UserScope,
                                        "MeePlus",
                                        "Main");
    QString path = settings->fileName().replace("Main.ini", "");
    delete settings;

    return path;
}

QString MeePlus::version()
{
    QString version;
#ifdef VERSION_PATCH
    version = QString(VERSION) + "-" + QString(VERSION_PATCH);
#else
    version = QString(VERSION);
#endif

    return version;
}
