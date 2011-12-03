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

#ifndef MEEPLUS_PERSONORGANIZATION_H_
#define MEEPLUS_PERSONORGANIZATION_H_

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "core/ListItem.h"

class MPPersonOrganization : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        PersonRole = Qt::UserRole + 1,
        NameRole,
        DepartmentRole,
        TitleRole,
        TypeRole,
        StartDateRole,
        EndDateRole,
        LocationRole,
        DescriptionRole,
        PrimaryRole
    };

    MPPersonOrganization(const QString &person,
                         const QString &name,
                         QObject *parent = 0);
    MPPersonOrganization();
    ~MPPersonOrganization();

    inline QString id() const { return _name; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString person() const { return _person; }
    void setPerson(const QString &person);
    inline QString name() const { return _name; }
    void setName(const QString &name);
    inline QString department() const { return _department; }
    void setDepartment(const QString &department);
    inline QString title() const { return _title; }
    void setTitle(const QString &title);
    inline QString type() const { return _type; }
    void setType(const QString &type);
    inline QString startDate() const { return _startDate; }
    void setStartDate(const QString &startDate);
    inline QString endDate() const { return _endDate; }
    void setEndDate(const QString &endDate);
    inline QString location() const { return _location; }
    void setLocation(const QString &location);
    inline QString description() const { return _description; }
    void setDescription(const QString &description);
    inline bool primary() const { return _primary; }
    void setPrimary(const bool &primary);

private:
    QString _person;
    QString _name;
    QString _department;
    QString _title;
    QString _type;
    QString _startDate;
    QString _endDate;
    QString _location;
    QString _description;
    bool _primary;
};

#endif // MEEPLUS_PERSONORGANIZATION_H_
