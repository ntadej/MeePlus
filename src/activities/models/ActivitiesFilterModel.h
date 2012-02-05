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

#ifndef MEEPLUS_ACTIVITIESFILTERMODEL_H_
#define MEEPLUS_ACTIVITIESFILTERMODEL_H_

#include <QtGui/QSortFilterProxyModel>

class MPActivitiesFilterModel : public QSortFilterProxyModel
{
Q_OBJECT
public:
    MPActivitiesFilterModel(QObject *parent = 0);
    ~MPActivitiesFilterModel();

    Q_INVOKABLE QString id() const { return _id; }
    Q_INVOKABLE QString personId() const { return _personId; }

public slots:
    Q_INVOKABLE void setId(const QString &id);
    Q_INVOKABLE void setPersonId(const QString &personId);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
    QString _id;
    QString _personId;
};

#endif // MEEPLUS_ACTIVITIESFILTERMODEL_H_
