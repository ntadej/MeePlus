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

#include "activities/items/Activity.h"
#include "people/items/Person.h"

MPActivity::MPActivity(const QString &id,
                       QObject *parent)
    : MPListItem(parent),
      _id(id)
{
    _actor = 0;
}

MPActivity::MPActivity()
{
    _actor = 0;
}

MPActivity::~MPActivity()
{
    if (_actor)
        delete _actor;
}

QHash<int, QByteArray> MPActivity::roleNames() const
{
    QHash<int, QByteArray> titles;
    titles[DisplayRole] = "display";
    titles[DisplayIconRole] = "displayIcon";
    titles[IdRole] = "id";
    titles[TitleRole] = "title";
    titles[PublishedRole] = "published";
    titles[UpdatedRole] = "updated";
    titles[UrlRole] = "url";
    titles[ActorIdRole] = "actorId";
    titles[ActorNameRole] = "actorName";
    titles[ActorImageRole] = "actorImage";
    titles[VerbRole] = "verb";
    return titles;
}

QVariant MPActivity::data(int role) const
{
    switch (role) {
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case IdRole:
        return id();
    case TitleRole:
        return title();
    case PublishedRole:
        return published();
    case UpdatedRole:
        return updated();
    case UrlRole:
        return url();
    case ActorIdRole:
        if (_actor)
            return actor()->id();
    case ActorNameRole:
        if (_actor)
            return actor()->name();
    case ActorImageRole:
        if (_actor)
            return actor()->image();
    case VerbRole:
        return verb();
    default:
        return QVariant();
    }
}

QString MPActivity::display() const
{
    return title();
}

QIcon MPActivity::displayIcon() const
{
    return QIcon();
}

void MPActivity::setTitle(const QString &title)
{
    if (_title != title) {
        _title = title;
        emit dataChanged();
    }
}

void MPActivity::setPublished(const QDateTime &published)
{
    if (_published != published) {
        _published = published;
        emit dataChanged();
    }
}

void MPActivity::setUpdated(const QDateTime &updated)
{
    if (_updated != updated) {
        _updated = updated;
        emit dataChanged();
    }
}

void MPActivity::setUrl(const QString &url)
{
    if (_url != url) {
        _url = url;
        emit dataChanged();
    }
}

void MPActivity::setActor(MPPerson *actor)
{
    if (_actor != actor) {
        delete _actor;
        _actor = actor;
        emit dataChanged();
    }
}

void MPActivity::setVerb(const QString &verb)
{
    if (_verb != verb) {
        _verb = verb;
        emit dataChanged();
    }
}
