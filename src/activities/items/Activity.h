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

#ifndef MEEPLUS_ACTIVITY_H_
#define MEEPLUS_ACTIVITY_H_

#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include "core/ListItem.h"

class MPPerson;

class MPActivity : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        IdRole = Qt::UserRole + 1,
        TitleRole,
        PublishedRole,
        UpdatedRole,
        UrlRole,
        ActorIdRole,
        ActorNameRole,
        ActorImageRole,
        VerbRole
    };

    MPActivity(const QString &id,
               QObject *parent = 0);
    MPActivity();
    ~MPActivity();

    inline QString id() const { return _id; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString title() const { return _title; }
    void setTitle(const QString &title);
    inline QDateTime published() const { return _published; }
    void setPublished(const QDateTime &published);
    inline QDateTime updated() const { return _updated; }
    void setUpdated(const QDateTime &updated);
    inline QString url() const { return _url; }
    void setUrl(const QString &url);
    inline MPPerson *actor() const { return _actor; }
    void setActor(MPPerson *actor);
    inline QString verb() const { return _verb; }
    void setVerb(const QString &verb);

private:
    QString _id;
    QString _title;
    QDateTime _published;
    QDateTime _updated;
    QString _url;
    MPPerson *_actor;
    QString _verb;
};

#endif // MEEPLUS_ACTIVITY_H_
