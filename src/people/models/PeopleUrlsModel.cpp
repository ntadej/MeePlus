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

#include "people/items/PersonUrl.h"
#include "people/models/PeopleUrlsModel.h"

MPPeopleUrlsModel::MPPeopleUrlsModel(QObject *parent)
    : MPListModel(new MPPersonUrl, parent) { }

MPPeopleUrlsModel::~MPPeopleUrlsModel() { }

MPPersonUrl *MPPeopleUrlsModel::find(const QString &id) const
{
    return qobject_cast<MPPersonUrl *>(MPListModel::find(id));
}

MPPersonUrl *MPPeopleUrlsModel::row(const int &row)
{
    return qobject_cast<MPPersonUrl *>(MPListModel::row(row));
}

MPPersonUrl *MPPeopleUrlsModel::takeRow(const int &row)
{
    return qobject_cast<MPPersonUrl *>(MPListModel::takeRow(row));
}

void MPPeopleUrlsModel::appendUrl(MPPersonUrl *url)
{
    appendSingleRow(url);
}
