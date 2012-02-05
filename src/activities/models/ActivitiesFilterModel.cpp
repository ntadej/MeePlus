/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
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

#include "activities/items/Activity.h"
#include "activities/models/ActivitiesFilterModel.h"

MPActivitiesFilterModel::MPActivitiesFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    _id = "";
    _personId = "";
}

MPActivitiesFilterModel::~MPActivitiesFilterModel() { }

bool MPActivitiesFilterModel::filterAcceptsRow(int sourceRow,
                                               const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    bool name = sourceModel()->data(index, MPActivity::TitleRole).toString().contains(filterRegExp());
    bool id = sourceModel()->data(index, MPActivity::IdRole).toString().contains(_id, Qt::CaseInsensitive);
    bool personId = sourceModel()->data(index, MPActivity::ActorIdRole).toString().contains(_personId, Qt::CaseInsensitive);

    return (name && id && personId);
}

void MPActivitiesFilterModel::setId(const QString &id)
{
    if(_id != id) {
        _id = id;
        invalidateFilter();
    }
}

void MPActivitiesFilterModel::setPersonId(const QString &personId)
{
    if(_personId != personId) {
        _personId = personId;
        invalidateFilter();
    }
}
