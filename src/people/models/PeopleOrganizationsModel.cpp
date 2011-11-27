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
#include "people/models/PeopleOrganizationsModel.h"

MPPeopleOrganizationsModel::MPPeopleOrganizationsModel(QObject *parent)
    : MPListModel(new MPPersonOrganization, parent) { }

MPPeopleOrganizationsModel::~MPPeopleOrganizationsModel() { }

MPPersonOrganization *MPPeopleOrganizationsModel::find(const QString &id) const
{
    return qobject_cast<MPPersonOrganization *>(MPListModel::find(id));
}

MPPersonOrganization *MPPeopleOrganizationsModel::row(const int &row)
{
    return qobject_cast<MPPersonOrganization *>(MPListModel::row(row));
}

MPPersonOrganization *MPPeopleOrganizationsModel::takeRow(const int &row)
{
    return qobject_cast<MPPersonOrganization *>(MPListModel::takeRow(row));
}
