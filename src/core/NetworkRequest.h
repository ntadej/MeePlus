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

#ifndef MEEPLUS_NETWORK_REQUEST_H_
#define MEEPLUS_NETWORK_REQUEST_H_

#include <QtCore/QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class MPNetworkRequest : public QObject
{
Q_OBJECT
public:
	MPNetworkRequest(QObject *parent = 0);
	~MPNetworkRequest();

	void getRequest(const QNetworkRequest &request);
	void postRequest(const QNetworkRequest &request,
					 const QByteArray &data);

signals:
	void result(const QString &);

private slots:
	void httpReadyRead();
	void httpRequestFinished();

private:
	void startRequest(const QNetworkRequest &request,
					  const QByteArray &data = 0);

	QNetworkAccessManager _nam;
	QNetworkReply *_nreply;

	QByteArray _currentData;
	QNetworkRequest _currentRequest;
	QString _currentResult;

	QUrl _url;
};

#endif // MEEPLUS_NETWORK_REQUEST_H_
