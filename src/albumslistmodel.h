#ifndef ALBUMSLISTMODEL_H
#define ALBUMSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "albums.h"
#include "photos.h"


class AlbumsListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AlbumItemRole {
        UserIdRole  = Qt::UserRole,
        IdRole,
        TitleRole,
        ImageRole
    };

    explicit AlbumsListModel(QAbstractListModel *parent = nullptr);
    explicit AlbumsListModel(const AlbumsListModel&, QAbstractListModel *parent = nullptr);
    explicit AlbumsListModel(Albums *albums, Photos *photos, QList<QVariantMap> albumsMap, QAbstractListModel *parent = nullptr);
    virtual ~AlbumsListModel() { QObject::disconnect(); }
    AlbumsListModel& operator=(const AlbumsListModel&);
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[UserIdRole] = "userId";
        roles[IdRole] = "id";
        roles[TitleRole] = "title";
        roles[ImageRole] = "image";
        return roles;
    }
    Q_INVOKABLE QVariantMap get(int row);
    Q_INVOKABLE uint size() const;

public slots:
    void updateData();

signals:
  void countChanged(int count);

private:
    Albums *m_albums;
    Photos *m_photos;
    QList<QVariantMap> m_albumsMap;
};

Q_DECLARE_METATYPE(AlbumsListModel);

#endif // ALBUMSLISTMODEL_H
