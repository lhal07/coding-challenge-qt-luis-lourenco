#ifndef COMMENTSLISTMODEL_H
#define COMMENTSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "comments.h"


class CommentsListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum CommentItemRole {
        PostIdRole  = Qt::UserRole,
        IdRole,
        NameRole,
        EmailRole,
        BodyRole
    };

    explicit CommentsListModel(QAbstractListModel *parent = nullptr);
    virtual ~CommentsListModel() {}
    QQmlListProperty<QAbstractListModel> content();
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[PostIdRole] = "userId";
        roles[IdRole] = "id";
        roles[NameRole] = "name";
        roles[EmailRole] = "email";
        roles[BodyRole] = "body";
        return roles;
    }

public slots:
    void updateData();

signals:
  void countChanged(int count);

private:
    Comments *m_comments;
    QList<QVariantMap> m_commentsMap;

};

#endif // COMMENTSLISTMODEL_H
