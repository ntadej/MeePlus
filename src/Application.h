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

#ifndef MEEPLUS_APPLICATION_H_
#define MEEPLUS_APPLICATION_H_

#include <QtCore/QObject>

class QmlApplicationViewer;

class MPAuthentication;
class MPPeopleHandler;
class MPPeopleEmailsFilterModel;
class MPPeopleEmailsModel;
class MPPeopleFilterModel;
class MPPeopleModel;
class MPPeopleOrganizationsFilterModel;
class MPPeopleOrganizationsModel;
class MPPeopleUrlsFilterModel;
class MPPeopleUrlsModel;
class MPPerson;
class MPSettings;

class MPApplication : public QObject
{
Q_OBJECT
public:
    MPApplication(QObject *parent = 0);
    ~MPApplication();

private slots:
    void selectPerson(const QString &id);

private:
    void initPeople();

    QmlApplicationViewer *_viewer;

    MPAuthentication *_authentication;
    MPSettings *_settings;

    // People
    MPPeopleHandler *_peopleHandler;

    MPPeopleFilterModel *_profile;
    MPPeopleModel *_peopleMain;
    MPPeopleModel *_peopleSearch;

    MPPeopleEmailsModel *_emails;
    MPPeopleOrganizationsModel *_organizations;
    MPPeopleUrlsModel *_urls;

    MPPeopleEmailsFilterModel *_profileEmails;
    MPPeopleOrganizationsFilterModel *_profileOrganizations;
    MPPeopleUrlsFilterModel *_profileUrls;
};

#endif // MEEPLUS_APPLICATION_H_
