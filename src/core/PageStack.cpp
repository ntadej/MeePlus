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

#include <QDebug>

#include "core/PageStack.h"

MPPageStack::MPPageStack(QObject *parent)
    : QObject(parent)
{
    addGenericPage();
}

MPPageStack::~MPPageStack() { }

void MPPageStack::addActivityPage(const QString &id)
{
    MPPage page;
    page.id = id;
    page.type = MPEnums::Activity;

    qDebug() << "Page added:" << "Activity" << id;

    _pages.append(page);
}

void MPPageStack::addGenericPage()
{
    MPPage page;
    page.type = MPEnums::Generic;

    qDebug() << "Page added:" << "Generic";

    _pages.append(page);
}

void MPPageStack::addPersonPage(const QString &id)
{
    MPPage page;
    page.id = id;
    page.type = MPEnums::Person;

    qDebug() << "Page added:" << "Person" << id;

    _pages.append(page);
}

void MPPageStack::removePage()
{
    _pages.removeLast();

    if(_pages.empty())
        return;

    qDebug() << "Page removed";

    switch (_pages.last().type)
    {
    case MPEnums::Activity:
        emit applyActivity(_pages.last().id);
        break;
    case MPEnums::Person:
        emit applyPerson(_pages.last().id);
        break;
    case MPEnums::Generic:
    default:
        break;
    }

    emit remove();
}
