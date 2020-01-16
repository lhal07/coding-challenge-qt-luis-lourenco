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
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum InfoDataRole {
        NameRole  = Qt::UserRole,
        CountRole
    };

    explicit InfoDataModel(QAbstractListModel *parent = nullptr);
    virtual ~InfoDataModel() {}
    QQmlListProperty<QAbstractListModel> content();
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
};

#endif // INFODATAMODEL_H
