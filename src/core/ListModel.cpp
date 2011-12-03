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

#include "core/ListItem.h"
#include "core/ListModel.h"

MPListModel::MPListModel(MPListItem *prototype,
                         QObject *parent)
    : QAbstractListModel(parent),
      _prototype(prototype)
{
    setRoleNames(_prototype->roleNames());
}

MPListModel::~MPListModel() {
    delete _prototype;
    clear();
}

int MPListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _list.size();
}

QVariant MPListModel::data(const QModelIndex &index,
                           int role) const
{
    if(index.row() < 0 || index.row() >= _list.size())
        return QVariant();
    return _list[index.row()]->data(role);
}

void MPListModel::appendRow(MPListItem *item)
{
    appendRows(QList<MPListItem*>() << item);
}

void MPListModel::appendRows(const QList<MPListItem *> &items)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount()+items.size()-1);
    foreach (MPListItem *item, items) {
        connect(item, SIGNAL(dataChanged()), SLOT(handleItemChange()));
        _list.append(item);
    }
    endInsertRows();
}

void MPListModel::appendSingleRow(MPListItem *item)
{
    if (find(item->id())) {
        delete item;
        return;
    }

    appendRow(item);
}

void MPListModel::insertRow(const int &row, MPListItem *item)
{
    beginInsertRows(QModelIndex(), row, row);
    connect(item, SIGNAL(dataChanged()), SLOT(handleItemChange()));
    _list.insert(row, item);
    endInsertRows();
}

void MPListModel::handleItemChange()
{
    MPListItem* item = static_cast<MPListItem*>(sender());
    QModelIndex index = indexFromItem(item);
    if (index.isValid())
        emit dataChanged(index, index);
}

MPListItem * MPListModel::find(const QString &id) const
{
    foreach (MPListItem* item, _list) {
        if (item->id() == id) return item;
    }
    return 0;
}

QModelIndex MPListModel::indexFromItem(const MPListItem *item) const
{
    Q_ASSERT(item);
    for (int row = 0; row < _list.size(); ++row) {
        if (_list[row] == item) return index(row);
    }
    return QModelIndex();
}

void MPListModel::clear()
{
    qDeleteAll(_list);
    _list.clear();
}

bool MPListModel::moveRow(const int &oldRow, const int &newRow, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if (oldRow < 0 || oldRow >= _list.size() || newRow < 0 || newRow >= _list.size()) return false;
    beginMoveRows(QModelIndex(), oldRow, oldRow, QModelIndex(), newRow);
    _list.move(oldRow, newRow);
    endMoveRows();
    return true;
}

bool MPListModel::removeRow(const int &row, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if (row < 0 || row >= _list.size()) return false;
    beginRemoveRows(QModelIndex(), row, row);
    delete _list.takeAt(row);
    endRemoveRows();
    return true;
}

bool MPListModel::removeRows(const int &row, const int &count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if (row < 0 || (row+count) >= _list.size()) return false;
    beginRemoveRows(QModelIndex(), row, row+count-1);
    for (int i = 0; i < count; ++i) {
        delete _list.takeAt(row);
    }
    endRemoveRows();
    return true;
}

MPListItem *MPListModel::row(const int &row)
{
    MPListItem* item = _list[row];
    return item;
}

MPListItem *MPListModel::takeRow(const int &row)
{
    beginRemoveRows(QModelIndex(), row, row);
    MPListItem* item = _list.takeAt(row);
    endRemoveRows();
    return item;
}
