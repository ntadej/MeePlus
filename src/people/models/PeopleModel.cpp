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

#include "people/items/Person.h"
#include "people/models/PeopleModel.h"

MPPeopleModel::MPPeopleModel(QObject *parent)
    : MPListModel(new MPPerson, parent) { }

MPPeopleModel::~MPPeopleModel() { }

MPPerson *MPPeopleModel::find(const QString &id) const
{
    return qobject_cast<MPPerson *>(MPListModel::find(id));
}

MPPerson *MPPeopleModel::row(const int &row)
{
    return qobject_cast<MPPerson *>(MPListModel::row(row));
}

MPPerson *MPPeopleModel::takeRow(const int &row)
{
    return qobject_cast<MPPerson *>(MPListModel::takeRow(row));
}

void MPPeopleModel::addSinglePerson(MPPerson *person)
{
    clear();
    appendRow(person);
}
