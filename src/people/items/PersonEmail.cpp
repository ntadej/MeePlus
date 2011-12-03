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

#include "people/items/PersonEmail.h"

MPPersonEmail::MPPersonEmail(const QString &person,
                             const QString &value,
                             QObject *parent)
    : MPListItem(parent)
{
    setPerson(person);
    setValue(value);
}

MPPersonEmail::MPPersonEmail() { }

MPPersonEmail::~MPPersonEmail() { }

QHash<int, QByteArray> MPPersonEmail::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PersonRole] = "person";
    names[DisplayRole] = "display";
    names[DisplayIconRole] = "displayIcon";
    names[ValueRole] = "value";
    names[TypeRole] = "type";
    names[PrimaryRole] = "primary";
    return names;
}

QVariant MPPersonEmail::data(int role) const
{
    switch (role)
    {
    case PersonRole:
        return person();
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case ValueRole:
        return value();
    case TypeRole:
        return type();
    case PrimaryRole:
        return primary();
    default:
        return QVariant();
    }
}

QString MPPersonEmail::display() const
{
    return value();
}

QIcon MPPersonEmail::displayIcon() const
{
    return QIcon();
}

void MPPersonEmail::setPerson(const QString &person)
{
    if(_person != person) {
        _person = person;
        emit dataChanged();
    }
}

void MPPersonEmail::setValue(const QString &value)
{
    if(_value != value) {
        _value = value;
        emit dataChanged();
    }
}

void MPPersonEmail::setType(const QString &type)
{
    if(_type != type) {
        _type = type;
        emit dataChanged();
    }
}

void MPPersonEmail::setPrimary(const bool &primary)
{
    if(_primary != primary) {
        _primary = primary;
        emit dataChanged();
    }
}
