#include "userslistmodel.h"

UsersListModel::CommentsListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_users = new(Users);
}


QQmlListProperty<QAbstractListModel> UsersListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void UsersListModel::registerTypes(const char *uri)
{
    qmlRegisterType<UsersListModel>(uri, 1, 0, "CommentsListModel");
}


QVariant UsersListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_users == nullptr)
        return QVariant();

    QVariantMap user = m_albums->items().at(index.row());
    switch(role) {
    case IdRole:
        return QVariant(user["id"]);
    case NameRole:
        return QVariant(user["name"]);
    case UserNameRole:
        return QVariant(user["username"]);
    case EmailRole:
        return QVariant(user["email"]);
    case AddressRole:
        return QVariant(user["address"]);
    case PhoneRole:
        return QVariant(user["phone"]);
    case WebsiteRole:
        return QVariant(user["website"]);
    case CompanyRole:
        return QVariant(user["company"]);
    }

    return QVariant();
}

int UsersListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_users->items().count();
}
