#ifndef USERSLISTMODEL_H
#define USERSLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml>
#include <QAbstractListModel>
#include <QStringList>
#include "users.h"


class UsersListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QAbstractListModel> content READ content)
    Q_CLASSINFO("DefaultProperty", "content")
public:
    enum UserItemRole {
        IdRole  = Qt::UserRole,
        NameRole,
        UserNameRole,
        EmailRole,
        AddressRole,
        PhoneRole,
        WebsiteRole,
        CompanyRole
    };

    explicit UsersListModel(QAbstractListModel *parent = nullptr);
    virtual ~UsersListModel() {}
    QQmlListProperty<QAbstractListModel> content();
    static void registerTypes(const char *uri);
    Q_INVOKABLE QVariant data(const QModelIndex &index = QModelIndex(), int role = Qt::DisplayRole) const noexcept override;
    Q_INVOKABLE int rowCount(const QModelIndex &index = QModelIndex()) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[IdRole] = "id";
        roles[NameRole] = "name";
        roles[UserNameRole] = "username";
        roles[EmailRole] = "email";
        roles[AddressRole] = "address";
        roles[PhoneRole] = "phone";
        roles[WebsiteRole] = "website";
        roles[CompanyRole] = "company";
        return roles;
    }

signals:
  void countChanged(int count);

private:
    Users *m_users;
};

#endif // USERSLISTMODEL_H
