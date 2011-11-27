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

#include "core/ListItem.h"

class MPPeopleEmailsModel;
class MPPeopleOrganizationsModel;
class MPPeopleUrlsModel;
class MPPersonEmail;
class MPPersonOrganization;
class MPPersonUrl;

class MPPerson : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        IdRole = Qt::UserRole + 1,
        NameRole,
        NicknameRole,
        TaglineRole,
        BirthdayRole,
        GenderRole,
        AboutMeRole,
        CurrentLocationRole,
        RelationshipStatusRole,
        UrlRole,
        ImageRole
    };

    MPPerson(const QString &id,
             QObject *parent = 0);
    MPPerson();
    ~MPPerson();

    inline QString id() const { return _id; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString name() const { return _name; }
    void setName(const QString &name);
    inline QString nickname() const { return _nickname; }
    void setNickname(const QString &nickname);
    inline QString tagline() const { return _tagline; }
    void setTagline(const QString &tagline);
    inline QString birthday() const { return _birthday; }
    void setBirthday(const QString &birthday);
    inline QString gender() const { return _gender; }
    void setGender(const QString &gender);
    inline QString aboutMe() const { return _aboutMe; }
    void setAboutMe(const QString &aboutMe);
    inline QString currentLocation() const { return _currentLocation; }
    void setCurrentLocation(const QString &currentLocation);
    inline QString relationshipStatus() const { return _relationshipStatus; }
    void setRelationshipStatus(const QString &relationshipStatus);
    inline QString url() const { return _url; }
    void setUrl(const QString &url);
    inline QString image() const { return _image; }
    void setImage(const QString &image);

    MPPeopleEmailsModel *emails() { return _emailsModel; }
    void addEmail(MPPersonEmail *e);
    MPPeopleOrganizationsModel *organizations() { return _organizationsModel; }
    void addOrganization(MPPersonOrganization *o);
    MPPeopleUrlsModel *urls() { return _urlsModel; }
    void addUrl(MPPersonUrl *u);

private:
    QString _id;
    QString _name;
    QString _nickname;
    QString _tagline;
    QString _birthday;
    QString _gender;
    QString _aboutMe;
    QString _currentLocation;
    QString _relationshipStatus;
    QString _url;
    QString _image;

    MPPeopleEmailsModel *_emailsModel;
    MPPeopleOrganizationsModel *_organizationsModel;
    MPPeopleUrlsModel *_urlsModel;
};

#endif // MEEPLUS_PERSON_H_
