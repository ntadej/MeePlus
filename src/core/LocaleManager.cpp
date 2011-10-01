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
#include <QtCore/QLocale>

#include "core/Common.h"
#include "core/LocaleManager.h"
#include "core/Settings.h"

MPLocaleManager::MPLocaleManager()
{
    _translator = new QTranslator();
    QCoreApplication::installTranslator(_translator);
    setLocale();
}

MPLocaleManager::~MPLocaleManager()
{
    QCoreApplication::removeTranslator(_translator);
    delete _translator;
}

QString MPLocaleManager::language(const QString &locale)
{
    QString language = QLocale::languageToString(QLocale(locale).language());

    if(language == "C")
        return "English";
    else
        return language;
}

QStringList MPLocaleManager::loadTranslations()
{
    QDir dir(MeePlus::locateResource("/lang/sl_SI.qm").replace("/sl_SI.qm", ""));
    QStringList list;
    QLocale locale = QLocale::English;
    list << QLocale::languageToString(locale.language());

    foreach (QString fileName, dir.entryList(QDir::Files)) {
        if(fileName.contains(".qm") && !fileName.contains("empty")) {
            locale = QLocale(fileName);
            list << locale.name();
        }
    }

    return list;
}

void MPLocaleManager::setLocale()
{
    QString locale;
    MPSettings *settings = new MPSettings();
    if(settings->language().isEmpty())
        locale = QLocale::system().name();
    else
        locale = QLocale(settings->language()).name();
    delete settings;

    QString langPath = MeePlus::locateResource("/lang/" + locale + ".qm").replace("/" + locale + ".qm", "");
    _translator->load(QString(locale), langPath);
}
