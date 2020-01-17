#include "infodatamodel.h"

InfoDataModel::InfoDataModel(QAbstractListModel *parent) :
    QAbstractListModel(parent)
{
    m_photos = new(Photos);
    m_comments = new(Comments);
    m_posts = new(Posts);
    m_users = new(Users);

    QObject::connect(m_users, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_photos, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_comments, SIGNAL(dataChanged()), this, SLOT(updateData()));
    QObject::connect(m_posts, SIGNAL(dataChanged()), this, SLOT(updateData()));
}

void InfoDataModel::updateData()
{
    QVariantMap usersMap;
    usersMap["name"] = QVariant("Usuários");
    usersMap["count"] = QVariant(m_users->count());
    QVariantMap photosMap;
    photosMap["name"] = QVariant("Fotos");
    photosMap["count"] = QVariant(m_photos->count());
    QVariantMap commentsMap;
    commentsMap["name"] = QVariant("Comentários");
    commentsMap["count"] = QVariant(m_comments->count());
    QVariantMap postsMap;
    postsMap["name"] = QVariant("Posts");
    postsMap["count"] = QVariant(m_posts->count());

    beginResetModel();
    m_infoMap.clear();
    m_infoMap.append(usersMap);
    m_infoMap.append(photosMap);
    m_infoMap.append(commentsMap);
    m_infoMap.append(postsMap);
    endResetModel();
}

QQmlListProperty<QAbstractListModel> InfoDataModel::content()
{
    return QQmlListProperty<QAbstractListModel>(this, 0, 0, 0);
}

void InfoDataModel::registerTypes(const char *uri)
{
    qmlRegisterType<InfoDataModel>(uri, 1, 0, "InfoDataModel");
}


QVariant InfoDataModel::data(const QModelIndex &index, int role) const noexcept
{
    if (!index.isValid() || m_users == nullptr)
        return QVariant();

    QVariantMap info = m_infoMap.at(index.row());
    switch(role) {
    case NameRole:
        return QVariant(info["name"]);
    case CountRole:
        return QVariant(info["count"]);
    }

    return QVariant();
}

int InfoDataModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_infoMap.size();
}
