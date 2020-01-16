#include "userslistmodel.h"

UsersListModel::UsersListModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_users = new(Users);
    QObject::connect(m_users, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

void UsersListModel::updateData()
{
    beginResetModel();
    m_usersMap.clear();
    m_usersMap = m_users->items();
    endResetModel();
}

QQmlListProperty<QAbstractListModel> UsersListModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void UsersListModel::registerTypes(const char *uri)
{
    qmlRegisterType<UsersListModel>(uri, 1, 0, "UsersListModel");
}


QVariant UsersListModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_users == nullptr)
        return QVariant();

    QVariantMap user = m_usersMap.at(index.row());
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
    return m_usersMap.count();
}
