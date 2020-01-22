#include "albumslistmodel.h"

class QAbstractListModel;

AlbumsListModel::AlbumsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_albums(new Albums),
    m_photos(new Photos),
    m_albumsMap(QList<QVariantMap>())
{
    QObject::connect(m_albums, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

AlbumsListModel::AlbumsListModel(const AlbumsListModel& other, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_albums(other.m_albums),
    m_photos(other.m_photos),
    m_albumsMap(other.m_albumsMap)
{
    QObject::connect(m_albums, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

AlbumsListModel::AlbumsListModel(Albums *albums, Photos *photos, QList<QVariantMap> albumsMap, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_albums(albums),
    m_photos(photos),
    m_albumsMap(albumsMap)
{
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

QVariantMap AlbumsListModel::get(int row)
{
    QHash<int,QByteArray> names = roleNames();
    QHashIterator<int, QByteArray> i(names);
    QVariantMap res;
    while (i.hasNext()) {
        i.next();
        QModelIndex idx = index(row, 0);
        QVariant data = idx.data(i.key());
        res[i.value()] = data;
        //qDebug() << i.key() << ": " << i.value() << endl;
    }
    return res;
}

uint AlbumsListModel::size() const
{
    return m_albumsMap.size();
}

AlbumsListModel& AlbumsListModel::operator=(const AlbumsListModel& other)
{
    if (this != &other) {
        delete m_albums;
        m_albums = nullptr;
        m_albums = other.m_albums;
        delete m_photos;
        m_photos = nullptr;
        m_photos = other.m_photos;

        beginResetModel();
        m_albumsMap.clear();
        m_albumsMap = other.m_albumsMap;
        endResetModel();
    }
    return *this;
}
