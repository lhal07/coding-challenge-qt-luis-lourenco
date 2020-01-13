#ifndef POSTSLISTMODEL_H
#define POSTSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "posts.h"


class PostsListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum PostItemRole {
        UserIdRole  = Qt::UserRole,
        IdRole,
        TitleRole,
        BodyRole
    };

    explicit PostsListModel(QAbstractListModel *parent = nullptr);
    virtual ~PostsListModel() {};
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
        roles[BodyRole] = "body";
        return roles;
    }

signals:
  void countChanged(int count);

private:
    Posts *m_posts;
};

#endif // POSTSLISTMODEL_H
