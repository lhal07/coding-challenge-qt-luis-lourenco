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
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum AlbumItemRole {
        AlbumIdRole  = Qt::UserRole,
        IdRole,
        TitleRole,
        UrlRole,
        ThumbnailUrlRole
    };

    explicit PhotosListModel(QAbstractListModel *parent = nullptr);
    virtual ~PhotosListModel() {};
    QQmlListProperty<QAbstractListModel> content();
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

signals:
  void countChanged(int count);

private:
    Photos *m_photos;
};

#endif // PHOTOSLISTMODEL_H
