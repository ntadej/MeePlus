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

#include "activities/items/Activity.h"
#include "core/Common.h"
#include "people/items/Person.h"

MPActivity::MPActivity(const QString &id,
                       QObject *parent)
    : MPListItem(parent),
      _id(id)
{
    _actor = 0;
    _originalActor = 0;
}

MPActivity::MPActivity()
{
    _actor = 0;
    _originalActor = 0;
}

MPActivity::~MPActivity()
{
    if (_actor)
        delete _actor;
    if (_originalActor)
        delete _originalActor;
}

QHash<int, QByteArray> MPActivity::roleNames() const
{
    QHash<int, QByteArray> titles;
    titles[DisplayRole] = "display";
    titles[DisplayIconRole] = "displayIcon";
    titles[IdRole] = "id";
    titles[TitleRole] = "title";
    titles[ContentRole] = "content";
    titles[PublishedRole] = "published";
    titles[UpdatedRole] = "updated";
    titles[UrlRole] = "url";
    titles[ActorIdRole] = "actorId";
    titles[ActorNameRole] = "actorName";
    titles[ActorImageRole] = "actorImage";
    titles[OriginalActorIdRole] = "originalActorId";
    titles[OriginalActorNameRole] = "originalActorName";
    titles[OriginalActorImageRole] = "originalActorImage";
    titles[VerbRole] = "verb";
    titles[AnnotationRole] = "annotation";
    titles[CommentsRole] = "comments";
    titles[PlusonersRole] = "plusoners";
    titles[ResharersRole] = "resharers";
    titles[ArticleTitleRole] = "articleTitle";
    titles[ArticleContentRole] = "articleContent";
    titles[ArticleUrlRole] = "articleUrl";
    titles[PhotoRole] = "photo";
    titles[PhotoFullRole] = "photoFull";
    titles[PhotoHeightRole] = "photoHeight";
    titles[PhotoWidthRole] = "photoWidth";
    return titles;
}

QVariant MPActivity::data(int role) const
{
    switch (role) {
    case DisplayRole:
        return display();
    case DisplayIconRole:
        return displayIcon();
    case IdRole:
        return id();
    case TitleRole:
        return title();
    case ContentRole:
        return content();
    case PublishedRole:
        return dateOutput(published());
    case UpdatedRole:
        return dateOutput(updated());
    case UrlRole:
        return url();
    case ActorIdRole:
        if (_actor)
            return actor()->id();
        else
            return "";
    case ActorNameRole:
        if (_actor)
            return actor()->name();
        else
            return "";
    case ActorImageRole:
        if (_actor)
            return actor()->image();
        else
            return "";
    case OriginalActorIdRole:
        if (_originalActor)
            return originalActor()->id();
        else
            return "";
    case OriginalActorNameRole:
        if (_originalActor)
            return originalActor()->name();
        else
            return "";
    case OriginalActorImageRole:
        if (_originalActor)
            return originalActor()->image();
        else
            return "";
    case VerbRole:
        return verb();
    case AnnotationRole:
        return annotation();
    case CommentsRole:
        return comments();
    case PlusonersRole:
        return plusoners();
    case ResharersRole:
        return resharers();
    case ArticleTitleRole:
        return articleTitle();
    case ArticleContentRole:
        return articleContent();
    case ArticleUrlRole:
        return articleUrl();
    case PhotoRole:
        return photo();
    case PhotoFullRole:
        return photoFull();
    case PhotoHeightRole:
        return photoHeight();
    case PhotoWidthRole:
        return photoWidth();
    default:
        return QVariant();
    }
}

QString MPActivity::dateOutput(const QDateTime &date) const
{
    return QString("%1 %2 %3 %4").arg(tr("on"), date.date().toString(Qt::DefaultLocaleShortDate), tr("at"), date.time().toString(Qt::DefaultLocaleShortDate));
}

QString MPActivity::display() const
{
    return title();
}

QIcon MPActivity::displayIcon() const
{
    return QIcon();
}

void MPActivity::setTitle(const QString &title)
{
    if (_title != title) {
        _title = title;
        emit dataChanged();
    }
}

void MPActivity::setContent(const QString &content)
{
    if (_content != content) {
        _content = content;
        emit dataChanged();
    }
}

void MPActivity::setPublished(const QDateTime &published)
{
    if (_published != published) {
        _published = published;
        emit dataChanged();
    }
}

void MPActivity::setUpdated(const QDateTime &updated)
{
    if (_updated != updated) {
        _updated = updated;
        emit dataChanged();
    }
}

void MPActivity::setUrl(const QString &url)
{
    if (_url != url) {
        _url = url;
        emit dataChanged();
    }
}

void MPActivity::setActor(MPPerson *actor)
{
    if (_actor != actor) {
        delete _actor;
        _actor = actor;
        emit dataChanged();
    }
}

void MPActivity::setOriginalActor(MPPerson *originalActor)
{
    if (_originalActor != originalActor) {
        delete _originalActor;
        _originalActor = originalActor;
        emit dataChanged();
    }
}

void MPActivity::setVerb(const QString &verb)
{
    if (_verb != verb) {
        _verb = verb;
        emit dataChanged();
    }
}

void MPActivity::setAnnotation(const QString &annotation)
{
    if (_annotation != annotation) {
        _annotation = annotation;
        emit dataChanged();
    }
}

void MPActivity::setComments(const int &comments)
{
    if (_comments != comments) {
        _comments = comments;
        emit dataChanged();
    }
}

void MPActivity::setPlusoners(const int &plusoners)
{
    if (_plusoners != plusoners) {
        _plusoners = plusoners;
        emit dataChanged();
    }
}

void MPActivity::setResharers(const int &resharers)
{
    if (_resharers != resharers) {
        _resharers = resharers;
        emit dataChanged();
    }
}

void MPActivity::setArticleTitle(const QString &articleTitle)
{
    if (_articleTitle != articleTitle) {
        _articleTitle = articleTitle;
        emit dataChanged();
    }
}

void MPActivity::setArticleContent(const QString &articleContent)
{
    if (_articleContent != articleContent) {
        _articleContent = articleContent;
        emit dataChanged();
    }
}

void MPActivity::setArticleUrl(const QString &articleUrl)
{
    if (_articleUrl != articleUrl) {
        _articleUrl = articleUrl;
        emit dataChanged();
    }
}

void MPActivity::setPhoto(const QString &photo)
{
    if (_photo != photo) {
        _photo = photo;
        emit dataChanged();
    }
}

void MPActivity::setPhotoFull(const QString &photoFull)
{
    if (_photoFull != photoFull) {
        _photoFull = photoFull;
        emit dataChanged();
    }
}

void MPActivity::setPhotoHeight(const int &photoHeight)
{
    if (_photoHeight != photoHeight) {
        _photoHeight = photoHeight;
        emit dataChanged();
    }
}

void MPActivity::setPhotoWidth(const int &photoWidth)
{
    if (_photoWidth != photoWidth) {
        _photoWidth = photoWidth;
        emit dataChanged();
    }
}
