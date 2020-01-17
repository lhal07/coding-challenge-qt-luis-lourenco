#include "albumslistmodel.h"

AlbumsListModel::AlbumsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_albums = new(Albums);
    m_photos = new(Photos);
    QObject::connect(m_albums, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

void AlbumsListModel::updateData()
{
    QList<QVariantMap> albums = m_albums->items();
    QList<QVariantMap> photos = m_photos->items();

    beginResetModel();
    m_albumsMap.clear();
    foreach(const QVariantMap & album , albums) {
        QVariantMap newItem = album;
        newItem["image"] = "";
        foreach(const QVariantMap & photo , photos) {
            if (newItem["id"] == photo["albumId"]) {
                newItem["image"] = photo["thumbnailUrl"];
                break;
            }
        }

        m_albumsMap.append(newItem);
    }
    endResetModel();
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

    QVariantMap album = m_albumsMap.at(index.row());
    switch(role) {
    case UserIdRole:
        return QVariant(album["userId"]);
    case IdRole:
        return QVariant(album["id"]);
    case TitleRole:
        return QVariant(album["title"]);
    case ImageRole:
        return QVariant(album["image"]);
    }

    return QVariant();
}

int AlbumsListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_albumsMap.count();
}
