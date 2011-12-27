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

#include <QtCore/QObject>

#include "Translations.h"

QString MPTranslations::activityVerb(const QString &string)
{
    if (string == "post")
        return QObject::tr("posted");
    else if (string == "checkin")
        return QObject::tr("checked in");
    else if (string == "share")
        return QObject::tr("shared");
    else
        return "";
}

QString MPTranslations::gender(const QString &string)
{
    if (string == "male")
        return QObject::tr("male");
    else if (string == "female")
        return QObject::tr("female");
    else if (string == "other")
        return QObject::tr("other");
    else
        return "";
}

QString MPTranslations::organization(const QString &string)
{
    if (string == "work")
        return QObject::tr("work");
    else if (string == "school")
        return QObject::tr("school");
    else
        return "";
}

QString MPTranslations::relationshipStatus(const QString &string)
{
    if (string == "single")
        return QObject::tr("single");
    else if (string == "in_a_relationship")
        return QObject::tr("in a relationship");
    else if (string == "engaged")
        return QObject::tr("engaged");
    else if (string == "married")
        return QObject::tr("married");
    else if (string == "its_complicated")
        return QObject::tr("it's complicated");
    else if (string == "open_relationship")
        return QObject::tr("in an open relationship");
    else if (string == "widowed")
        return QObject::tr("widowed");
    else if (string == "in_domestic_partnership")
        return QObject::tr("in a domestic partnership");
    else if (string == "in_civil_union")
        return QObject::tr("in a civil union");
    else
        return "";
}
