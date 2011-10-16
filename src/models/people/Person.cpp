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

#include "models/people/Person.h"

MPPerson::MPPerson(const QString &id,
                   QObject *parent)
    : MPListItem(parent),
      _id(id) { }

MPPerson::MPPerson() { }

MPPerson::~MPPerson() { }

QHash<int, QByteArray> MPPerson::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DisplayRole] = "display";
    names[DisplayIconRole] = "displayIcon";
    names[IdRole] = "id";
    names[NameRole] = "name";
    names[NicknameRole] = "nickname";
    names[TaglineRole] = "tagline";
    names[BirthdayRole] = "birthday";
    names[GenderRole] = "gender";
    names[AboutMeRole] = "aboutMe";
    names[CurrentLocationRole] = "currentLocation";
    names[RelationshipStatusRole] = "relationshipStatus";
    names[UrlRole] = "url";
    names[ImageRole] = "image";
    return names;
}

QVariant MPPerson::data(int role) const
{
    switch (role)
    {
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case IdRole:
        return id();
    case NameRole:
        return name();
    case NicknameRole:
        return nickname();
    case TaglineRole:
        return tagline();
    case BirthdayRole:
        return birthday();
    case GenderRole:
        return gender();
    case AboutMeRole:
        return aboutMe();
    case CurrentLocationRole:
        return currentLocation();
    case RelationshipStatusRole:
        return relationshipStatus();
    case UrlRole:
        return url();
    case ImageRole:
        return image();
    default:
        return QVariant();
    }
}

QString MPPerson::display() const
{
    return name();
}

QIcon MPPerson::displayIcon() const
{
    return QIcon();
}

void MPPerson::setName(const QString &name)
{
    if(_name != name) {
        _name = name;
        emit dataChanged();
    }
}

void MPPerson::setNickname(const QString &nickname)
{
    if(_nickname != nickname) {
        _nickname = nickname;
        emit dataChanged();
    }
}

void MPPerson::setTagline(const QString &tagline)
{
    if(_tagline != tagline) {
        _tagline = tagline;
        emit dataChanged();
    }
}

void MPPerson::setBirthday(const QString &birthday)
{
    if(_birthday != birthday) {
        _birthday = birthday;
        emit dataChanged();
    }
}

void MPPerson::setGender(const QString &gender)
{
    if(_gender != gender) {
        _gender = gender;
        emit dataChanged();
    }
}

void MPPerson::setAboutMe(const QString &aboutMe)
{
    if(_aboutMe != aboutMe) {
        _aboutMe = aboutMe;
        emit dataChanged();
    }
}

void MPPerson::setCurrentLocation(const QString &currentLocation)
{
    if(_currentLocation != currentLocation) {
        _currentLocation = currentLocation;
        emit dataChanged();
    }
}

void MPPerson::setRelationshipStatus(const QString &relationshipStatus)
{
    if(_relationshipStatus != relationshipStatus) {
        _relationshipStatus = relationshipStatus;
        emit dataChanged();
    }
}

void MPPerson::setUrl(const QString &url)
{
    if(_url != url) {
        _url = url;
        emit dataChanged();
    }
}

void MPPerson::setImage(const QString &image)
{
    if(_image != image) {
        _image = image;
        emit dataChanged();
    }
}
