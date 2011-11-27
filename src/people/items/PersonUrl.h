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

#ifndef MEEPLUS_PERSONURL_H_
#define MEEPLUS_PERSONURL_H_

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "core/ListItem.h"

class MPPersonUrl : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        ValueRole = Qt::UserRole + 1,
        TypeRole,
        PrimaryRole
    };

    MPPersonUrl(const QString &value,
                QObject *parent = 0);
    MPPersonUrl();
    ~MPPersonUrl();

    inline QString id() const { return _value; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString value() const { return _value; }
    void setValue(const QString &value);
    inline QString type() const { return _type; }
    void setType(const QString &type);
    inline bool primary() const { return _primary; }
    void setPrimary(const bool &primary);

private:
    QString _value;
    QString _type;
    bool _primary;
};

#endif // MEEPLUS_PERSONURL_H_
