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

#include "people/items/PersonOrganization.h"

MPPersonOrganization::MPPersonOrganization(const QString &person,
                                           const QString &name,
                                           QObject *parent)
    : MPListItem(parent)
{
    setPerson(person);
    setName(name);
}

MPPersonOrganization::MPPersonOrganization() { }

MPPersonOrganization::~MPPersonOrganization() { }

QHash<int, QByteArray> MPPersonOrganization::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PersonRole] = "person";
    names[DisplayRole] = "display";
    names[DisplayIconRole] = "displayIcon";
    names[NameRole] = "name";
    names[DepartmentRole] = "department";
    names[TitleRole] = "title";
    names[TypeRole] = "type";
    names[StartDateRole] = "startDate";
    names[EndDateRole] = "endDate";
    names[LocationRole] = "location";
    names[DescriptionRole] = "description";
    names[PrimaryRole] = "primary";
    return names;
}

QVariant MPPersonOrganization::data(int role) const
{
    switch (role)
    {
    case PersonRole:
        return person();
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case NameRole:
        return name();
    case DepartmentRole:
        return department();
    case TitleRole:
        return title();
    case TypeRole:
        return type();
    case StartDateRole:
        return startDate();
    case EndDateRole:
        return endDate();
    case LocationRole:
        return location();
    case DescriptionRole:
        return description();
    case PrimaryRole:
        return primary();
    default:
        return QVariant();
    }
}

QString MPPersonOrganization::display() const
{
    return name();
}

QIcon MPPersonOrganization::displayIcon() const
{
    return QIcon();
}

void MPPersonOrganization::setPerson(const QString &person)
{
    if(_person != person) {
        _person = person;
        emit dataChanged();
    }
}

void MPPersonOrganization::setName(const QString &name)
{
    if(_name != name) {
        _name = name;
        emit dataChanged();
    }
}

void MPPersonOrganization::setDepartment(const QString &department)
{
    if(_department != department) {
        _department = department;
        emit dataChanged();
    }
}

void MPPersonOrganization::setTitle(const QString &title)
{
    if(_title != title) {
        _title = title;
        emit dataChanged();
    }
}

void MPPersonOrganization::setType(const QString &type)
{
    if(_type != type) {
        _type = type;
        emit dataChanged();
    }
}

void MPPersonOrganization::setStartDate(const QString &startDate)
{
    if(_startDate != startDate) {
        _startDate = startDate;
        emit dataChanged();
    }
}

void MPPersonOrganization::setEndDate(const QString &endDate)
{
    if(_endDate != endDate) {
        _endDate = endDate;
        emit dataChanged();
    }
}

void MPPersonOrganization::setLocation(const QString &location)
{
    if(_location != location) {
        _location = location;
        emit dataChanged();
    }
}

void MPPersonOrganization::setDescription(const QString &description)
{
    if(_description != description) {
        _description = description;
        emit dataChanged();
    }
}

void MPPersonOrganization::setPrimary(const bool &primary)
{
    if(_primary != primary) {
        _primary = primary;
        emit dataChanged();
    }
}
