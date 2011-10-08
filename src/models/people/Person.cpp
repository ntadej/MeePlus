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

#include "models/people/Person.h"

Person::Person(const QString &id,
               QObject *parent)
    : MPListItem(parent),
      _id(id)
{

}

Person::~Person() { }

QHash<int, QByteArray> Person::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DisplayRole] = "display";
    names[DisplayIconRole] = "displayIcon";
    names[IdRole] = "id";
    names[NameRole] = "name";
    return names;
}

QVariant Person::data(int role) const
{
    switch (role)
    {
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case IdRole:
        return id();
    case NameRole:
        return name();
    default:
        return QVariant();
    }
}

QString Person::display() const
{
    return name();
}

QIcon Person::displayIcon() const
{
    return QIcon();
}

void Person::setName(const QString &name)
{
    if(_name != name) {
        _name = name;
        emit dataChanged();
    }
}
