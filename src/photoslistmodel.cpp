#include "photoslistmodel.h"

PhotosListModel::PhotosListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(new Photos),
    m_photosMap(QList<QVariantMap>()),
    m_album(QList<QVariantMap>()),
    m_albumId(-1)
{
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

PhotosListModel::PhotosListModel(const PhotosListModel& other, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(other.m_photos),
    m_photosMap(other.m_photosMap),
    m_album(other.m_album),
    m_albumId(other.m_albumId)
{
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

PhotosListModel::PhotosListModel(Photos *photos, QList<QVariantMap> photosMap, QList<QVariantMap> album, int albumId, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(photos),
    m_photosMap(photosMap),
    m_album(album),
    m_albumId(albumId)
{
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

void PhotosListModel::updateData()
{
    beginResetModel();
    m_photosMap.clear();
    m_photosMap = album();
    endResetModel();
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

QList<QVariantMap> PhotosListModel::album()
{
    //qDebug() << "===================";
    //qDebug() << m_albumId;
    QList<QVariantMap> photos = m_photos->items();
    QList<QVariantMap> albumPhotos;
    if (m_albumId < 0) {
        albumPhotos = photos;
    } else {
        foreach(const QVariantMap photo, photos) {
            if (photo["albumId"] == m_albumId) {
                albumPhotos.append(photo);
            }
        }
    }
    //qDebug() << albumPhotos;
    return albumPhotos;
}

void PhotosListModel::setAlbum(QList<QVariantMap> album)
{
    m_album = album;
}

int PhotosListModel::albumId()
{
    return m_albumId;
}

void PhotosListModel::setAlbumId(int albumId)
{
    m_albumId = albumId;
    updateData();
}

int PhotosListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_photosMap.count();
}

PhotosListModel& PhotosListModel::operator=(const PhotosListModel& other)
{
    if (this != &other) {
        delete m_photos;
        m_photos = nullptr;
        m_photos = other.m_photos;

        beginResetModel();
        m_photosMap.clear();
        m_album.clear();
        m_photosMap = other.m_photosMap;
        m_album = other.m_album;
        endResetModel();
    }
    return *this;
}
