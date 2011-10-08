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

#ifndef MEEPLUS_PERSON_H_
#define MEEPLUS_PERSON_H_

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "models/ListItem.h"

class Person : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    Person(const QString &id = 0,
           QObject *parent = 0);
    ~Person();

    inline QString id() const { return _id; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString name() const { return _name; }
    void setName(const QString &name);

private:
    QString _id;
    QString _name;
};

#endif // MEEPLUS_PERSON_H_
