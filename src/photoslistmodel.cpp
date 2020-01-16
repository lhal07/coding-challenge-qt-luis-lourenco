#include "photoslistmodel.h"

PhotosListModel::PhotosListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_photos = new(Photos);
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

void PhotosListModel::updateData()
{
    beginResetModel();
    m_photosMap.clear();
    m_photosMap = m_photos->items();
    endResetModel();
}

QQmlListProperty<QAbstractListModel> PhotosListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void PhotosListModel::registerTypes(const char *uri)
{
    qmlRegisterType<PhotosListModel>(uri, 1, 0, "PhotosListModel");
}


QVariant PhotosListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_photos == nullptr)
        return QVariant();

    QVariantMap photo = m_photosMap.at(index.row());
    switch(role) {
    case AlbumIdRole:
        return QVariant(photo["albumId"]);
    case IdRole:
        return QVariant(photo["id"]);
    case TitleRole:
        return QVariant(photo["title"]);
    case UrlRole:
        return QVariant(photo["url"]);
    case ThumbnailUrlRole:
        return QVariant(photo["thumbnailUrl"]);
    }

    return QVariant();
}

int PhotosListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_photosMap.count();
}

