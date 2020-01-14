#include "commentslistmodel.h"

CommentsListModel::CommentsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_comments = new(Comments);
}


QQmlListProperty<QAbstractListModel> CommentsListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void CommentsListModel::registerTypes(const char *uri)
{
    qmlRegisterType<CommentsListModel>(uri, 1, 0, "CommentsListModel");
}


QVariant CommentsListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_comments == nullptr)
        return QVariant();

    QVariantMap comment = m_comments->items().at(index.row());
    switch(role) {
    case PostIdRole:
        return QVariant(comment["postId"]);
    case IdRole:
        return QVariant(comment["id"]);
    case NameRole:
        return QVariant(comment["name"]);
    case EmailRole:
        return QVariant(comment["email"]);
    case BodyRole:
        return QVariant(comment["body"]);
    }

    return QVariant();
}

int CommentsListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_comments->items().count();
}
