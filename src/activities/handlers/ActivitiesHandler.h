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

#ifndef MEEPLUS_ACTIVITIESHANDLER_H_
#define MEEPLUS_ACTIVITIESHANDLER_H_

#include <QtCore/QObject>

class MPNetworkRequest;
class MPActivity;

class MPActivitiesHandler : public QObject
{
Q_OBJECT
public:
    MPActivitiesHandler(QObject *parent = 0);
    ~MPActivitiesHandler();

    Q_INVOKABLE void list(const QString &person);
    Q_INVOKABLE void listNext();
    Q_INVOKABLE void request(const QString &activity);
    Q_INVOKABLE void search(const QString &string);
    Q_INVOKABLE void searchNext();

public slots:
    void retry();

signals:
    void currentActivity(MPActivity *);
    void finishedActivity();
    void finishedList();
    void newActivity(MPActivity *);
    void requestAuthentication();
    void reset();

private slots:
    void activity(const QString &activity);
    void error(const int &err);
    void listPrivate();
    void searchPrivate();

private:
    MPNetworkRequest *_nr;

    QString _currentActivity;
    QString _currentPerson;
    QString _currentSearchString;
    QString _nextPage;
    bool _primary;
};

#endif // MEEPLUS_ACTIVITIESHANDLER_H_
