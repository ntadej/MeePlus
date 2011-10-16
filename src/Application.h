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
class MPPeopleFilterModel;
class MPPeopleModel;
class MPSettings;

class MPApplication : public QObject
{
Q_OBJECT
public:
    MPApplication(QObject *parent = 0);
    ~MPApplication();

private:
    QmlApplicationViewer *_viewer;

    MPAuthentication *_authentication;
    MPPeopleHandler *_people;
    MPPeopleFilterModel *_profileF;
    MPPeopleModel *_profile;
    MPSettings *_settings;
};

#endif // MEEPLUS_APPLICATION_H_
