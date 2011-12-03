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

#ifndef MEEPLUS_PEOPLEURLSMODEL_H_
#define MEEPLUS_PEOPLEURLSMODEL_H_

#include <QtCore/QStringList>

#include "core/ListModel.h"

class MPPersonUrl;

class MPPeopleUrlsModel : public MPListModel
{
Q_OBJECT
public:
    MPPeopleUrlsModel(QObject *parent = 0);
    ~MPPeopleUrlsModel();

    MPPersonUrl *find(const QString &id) const;
    MPPersonUrl *row(const int &row);
    MPPersonUrl *takeRow(const int &row);

public slots:
    void appendUrl(MPPersonUrl *url);
};

#endif // MEEPLUS_PEOPLEURLSMODEL_H_
