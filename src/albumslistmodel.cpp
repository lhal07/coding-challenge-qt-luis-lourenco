#include "albumslistmodel.h"

AlbumsListModel::AlbumsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_albums = new(Albums);
}


QQmlListProperty<QAbstractListModel> AlbumsListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void AlbumsListModel::registerTypes(const char *uri)
{
    qmlRegisterType<AlbumsListModel>(uri, 1, 0, "AlbumsListModel");
}


QVariant AlbumsListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_albums == nullptr)
        return QVariant();

    QVariantMap album = m_albums->items().at(index.row());
    switch(role) {
    case UserIdRole:
        return QVariant(album["userId"]);
    case IdRole:
        return QVariant(album["id"]);
    case TitleRole:
        return QVariant(album["title"]);
    }

    return QVariant();
}

int AlbumsListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_albums->items().count();
}
