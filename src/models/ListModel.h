/****************************************************************************
* MeePlus - Google+ client for Harmattan
* Copyright (C) 2011 Tadej Novak <tadej@tano.si>
* Based on MPListModel by Christophe Dumez <dchris@gmail.com>
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

#ifndef MEEPLUS_LISTMODEL_H_
#define MEEPLUS_LISTMODEL_H_

#include <QtCore/QAbstractListModel>
#include <QtCore/QList>
#include <QtCore/QVariant>

class MPListItem;

class MPListModel : public QAbstractListModel
{
Q_OBJECT
public:
    MPListModel(MPListItem *prototype, QObject *parent = 0);
    ~MPListModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void appendRow(MPListItem *item);
    void appendRows(const QList<MPListItem *> &items);
    void insertRow(const int &row, MPListItem *item);
    bool moveRow(const int &oldRow, const int &newRow, const QModelIndex &parent = QModelIndex());
    bool removeRow(const int &row, const QModelIndex &parent = QModelIndex());
    bool removeRows(const int &row, const int &count, const QModelIndex &parent = QModelIndex());
    MPListItem *row(const int &row);
    MPListItem *takeRow(const int &row);
    MPListItem *find(const QString &id) const;
    QModelIndex indexFromItem(const MPListItem *item) const;
    void clear();

private slots:
    void handleItemChange();

private:
    MPListItem *_prototype;
    QList<MPListItem *> _list;
};

#endif // MEEPLUS_LISTMODEL_H_
