#ifndef INFODATAMODEL_H
#define INFODATAMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>

#include "users.h"
#include "photos.h"
#include "posts.h"
#include "comments.h"


class InfoDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum InfoDataRole {
        NameRole  = Qt::UserRole,
        CountRole
    };

    explicit InfoDataModel(QAbstractListModel *parent = nullptr);
    explicit InfoDataModel(const InfoDataModel&, QAbstractListModel *parent = nullptr);
    explicit InfoDataModel(Photos *photos, Comments *comments, Posts *posts, Users *users, QList<QVariantMap> infoMap, QAbstractListModel *parent = nullptr);
    InfoDataModel& operator=(const InfoDataModel&);
    virtual ~InfoDataModel() {}
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[CountRole] = "count";
        return roles;
    }

public slots:
    void updateData();

signals:
  void countChanged(int count);

private:
    Photos *m_photos;
    Comments *m_comments;
    Posts *m_posts;
    Users *m_users;
    QList<QVariantMap> m_infoMap;

    void init();
};

Q_DECLARE_METATYPE(InfoDataModel);

#endif // INFODATAMODEL_H
