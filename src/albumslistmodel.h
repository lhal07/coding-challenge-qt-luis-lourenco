#ifndef ALBUMSLISTMODEL_H
#define ALBUMSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "albums.h"


class AlbumsListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum AlbumItemRole {
        UserIdRole  = Qt::UserRole,
        IdRole,
        TitleRole
    };

    explicit AlbumsListModel(QAbstractListModel *parent = nullptr);
    virtual ~AlbumsListModel() {};
    QQmlListProperty<QAbstractListModel> content();
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[UserIdRole] = "userId";
        roles[IdRole] = "id";
        roles[TitleRole] = "title";
        return roles;
    }

public slots:
    void updateData();

signals:
  void countChanged(int count);

private:
    Albums *m_albums;
    QList<QVariantMap> m_albumsMap;
};

#endif // ALBUMSLISTMODEL_H
