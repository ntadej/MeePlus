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

#ifndef MEEPLUS_ACTIVITY_H_
#define MEEPLUS_ACTIVITY_H_

#include <QtCore/QDateTime>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include "core/ListItem.h"

class MPPerson;

class MPActivity : public MPListItem
{
Q_OBJECT
public:
    enum Roles {
        DisplayRole = Qt::DisplayRole,
        DisplayIconRole = Qt::DecorationRole,
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ContentRole,
        PublishedRole,
        UpdatedRole,
        UrlRole,
        ActorIdRole,
        ActorNameRole,
        ActorImageRole,
        OriginalActorIdRole,
        OriginalActorNameRole,
        OriginalActorImageRole,
        VerbRole,
        AnnotationRole,
        CommentsRole,
        PlusonersRole,
        ResharersRole,
        ArticleTitleRole,
        ArticleContentRole,
        ArticleUrlRole,
        PhotoRole,
        PhotoFullRole,
        PhotoHeightRole,
        PhotoWidthRole
    };

    MPActivity(const QString &id,
               QObject *parent = 0);
    MPActivity();
    ~MPActivity();

    inline QString id() const { return _id; }
    QVariant data(int role) const;
    QString display() const;
    QIcon displayIcon() const;
    QHash<int, QByteArray> roleNames() const;

    inline QString title() const { return _title; }
    void setTitle(const QString &title);
    inline QString content() const { return _content; }
    void setContent(const QString &content);
    inline QDateTime published() const { return _published; }
    void setPublished(const QDateTime &published);
    inline QDateTime updated() const { return _updated; }
    void setUpdated(const QDateTime &updated);
    inline QString url() const { return _url; }
    void setUrl(const QString &url);
    inline MPPerson *actor() const { return _actor; }
    void setActor(MPPerson *actor);
    inline MPPerson *originalActor() const { return _originalActor; }
    void setOriginalActor(MPPerson *originalActor);
    inline QString verb() const { return _verb; }
    void setVerb(const QString &verb);
    inline QString annotation() const { return _annotation; }
    void setAnnotation(const QString &annotation);
    inline int comments() const { return _comments; }
    void setComments(const int &comments);
    inline int plusoners() const { return _plusoners; }
    void setPlusoners(const int &plusoners);
    inline int resharers() const { return _resharers; }
    void setResharers(const int &resharers);
    inline QString articleTitle() const { return _articleTitle; }
    void setArticleTitle(const QString &articleTitle);
    inline QString articleContent() const { return _articleContent; }
    void setArticleContent(const QString &articleContent);
    inline QString articleUrl() const { return _articleUrl; }
    void setArticleUrl(const QString &articleUrl);
    inline QString photo() const { return _photo; }
    void setPhoto(const QString &photo);
    inline QString photoFull() const { return _photoFull; }
    void setPhotoFull(const QString &photoFull);
    inline int photoHeight() const { return _photoHeight; }
    void setPhotoHeight(const int &photoHeight);
    inline int photoWidth() const { return _photoWidth; }
    void setPhotoWidth(const int &photoWidth);

private:
    QString dateOutput(const QDateTime &date) const;

    QString _id;
    QString _title;
    QString _content;
    QDateTime _published;
    QDateTime _updated;
    QString _url;
    MPPerson *_actor;
    MPPerson *_originalActor;
    QString _verb;
    QString _annotation;
    int _comments;
    int _plusoners;
    int _resharers;
    QString _articleTitle;
    QString _articleContent;
    QString _articleUrl;
    QString _photo;
    QString _photoFull;
    int _photoHeight;
    int _photoWidth;
};

#endif // MEEPLUS_ACTIVITY_H_
