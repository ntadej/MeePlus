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

#ifndef MEEPLUS_PROFILEHANDLER_H_
#define MEEPLUS_PROFILEHANDLER_H_

#include <QtCore/QObject>

class MPNetworkRequest;
class MPPerson;
class MPPersonEmail;
class MPPersonOrganization;
class MPPersonUrl;

class MPPeopleHandler : public QObject
{
Q_OBJECT
public:
    MPPeopleHandler(QObject *parent = 0);
    ~MPPeopleHandler();

    Q_INVOKABLE void requestProfile(const QString &profile);
    Q_INVOKABLE void search(const QString &string);

public slots:
    void retry();

signals:
    void currentProfile(MPPerson *);
    void currentProfileId(const QString &);
    void finishedProfile();
    void finishedSearch();
    void newEmail(MPPersonEmail *);
    void newOrganization(MPPersonOrganization *);
    void newUrl(MPPersonUrl *);
    void requestAuthentication();
    void searchPerson(MPPerson *);
    void searchReset();

private slots:
    void error(const int &err);
    void profile(const QString &profile);

private:
    MPNetworkRequest *_nr;

    QString _currentProfile;
    QString _currentSearchString;
};

#endif // MEEPLUS_PROFILEHANDLER_H_
