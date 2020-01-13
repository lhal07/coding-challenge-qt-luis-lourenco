#include "postslistmodel.h"

PostsListModel::PostsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_posts = new(Posts);
}


QQmlListProperty<QAbstractListModel> PostsListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void PostsListModel::registerTypes(const char *uri)
{
    qmlRegisterType<PostsListModel>(uri, 1, 0, "PostsListModel");
}


QVariant PostsListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_posts == nullptr)
        return QVariant();

    QVariantMap post = m_albums->items().at(index.row());
    switch(role) {
    case UserIdRole:
        return QVariant(post["userId"]);
    case IdRole:
        return QVariant(post["id"]);
    case TitleRole:
        return QVariant(post["title"]);
    case BodyRole:
        return QVariant(post["body"]);
    }

    return QVariant();
}

int PostsListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_posts->items().count();
}
