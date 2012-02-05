/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2012 Tadej Novak <tadej@tano.si>
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

#ifndef MEEPLUS_PAGESTACK_H_
#define MEEPLUS_PAGESTACK_H_

#include <QtCore/QList>
#include <QtCore/QObject>

#include "core/Enums.h"

struct MPPage
{
    QString id;
    MPEnums::PageType type;
};

class MPPageStack : public QObject
{
Q_OBJECT
public:
    MPPageStack(QObject *parent = 0);
    ~MPPageStack();

    Q_INVOKABLE void addActivityPage(const QString &id);
    Q_INVOKABLE void addGenericPage();
    Q_INVOKABLE void addPersonPage(const QString &id);

    Q_INVOKABLE void removePage();

signals:
    void applyActivity(const QString &);
    void applyPerson(const QString &);

    void remove();

private:
    QList<MPPage> _pages;
};

#endif // MEEPLUS_PAGESTACK_H_
