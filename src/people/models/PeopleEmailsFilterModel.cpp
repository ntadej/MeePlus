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
#include "people/models/PeopleEmailsFilterModel.h"

MPPeopleEmailsFilterModel::MPPeopleEmailsFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent) { }

MPPeopleEmailsFilterModel::~MPPeopleEmailsFilterModel() { }

bool MPPeopleEmailsFilterModel::filterAcceptsRow(int sourceRow,
                                                 const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    bool v = sourceModel()->data(index, MPPersonEmail::ValueRole).toString().contains(filterRegExp());
    bool p = sourceModel()->data(index, MPPersonEmail::PersonRole).toString() == _person;

    return (p && v);
}

void MPPeopleEmailsFilterModel::setPerson(const QString &person)
{
    if (_person != person) {
        _person = person;
        invalidateFilter();
    }
}
