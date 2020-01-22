#ifndef PHOTOSLISTMODEL_H
#define PHOTOSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "photos.h"


class PhotosListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AlbumItemRole {
        AlbumIdRole  = Qt::UserRole,
        IdRole,
        TitleRole,
        UrlRole,
        ThumbnailUrlRole
    };

    explicit PhotosListModel(QAbstractListModel *parent = nullptr);
    explicit PhotosListModel(const PhotosListModel&, QAbstractListModel *parent = nullptr);
    explicit PhotosListModel(Photos *photos, QList<QVariantMap> photosMap, QList<QVariantMap> album, int albumId, QAbstractListModel *parent = nullptr);
    virtual ~PhotosListModel() {};
    PhotosListModel& operator=(const PhotosListModel&);
    Q_PROPERTY(int albumId READ albumId WRITE setAlbumId);
    Q_PROPERTY(QList<QVariantMap> album READ album WRITE setAlbum);
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[AlbumIdRole] = "albumId";
        roles[IdRole] = "id";
        roles[TitleRole] = "title";
        roles[UrlRole] = "url";
        roles[ThumbnailUrlRole] = "thumbnailUrl";
        return roles;
    }
    Q_INVOKABLE QList<QVariantMap> album();
    Q_INVOKABLE void setAlbum(QList<QVariantMap> album=QList<QVariantMap>());
    Q_INVOKABLE int albumId();
    Q_INVOKABLE void setAlbumId(int albumId=-1);
    //Q_INVOKABLE QList<QVariantMap> getPhotos();

public slots:
    void updateData();

signals:
  void countChanged(int count);

private:
    Photos *m_photos;
    QList<QVariantMap> m_photosMap;
    QList<QVariantMap> m_album;
    int m_albumId;

};

Q_DECLARE_METATYPE(PhotosListModel);

#endif // PHOTOSLISTMODEL_H
