#include "infodatamodel.h"

InfoDataModel::InfoDataModel(QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(new Photos),
    m_comments(new Comments),
    m_posts(new Posts),
    m_users(new Users),
    m_infoMap(QList<QVariantMap>())
{
    init();
}

InfoDataModel::InfoDataModel(const InfoDataModel& other, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(other.m_photos),
    m_comments(other.m_comments),
    m_posts(other.m_posts),
    m_users(other.m_users),
    m_infoMap(other.m_infoMap)
{
    init();
}

InfoDataModel::InfoDataModel(Photos *photos, Comments *comments, Posts *posts, Users *users, QList<QVariantMap> infoMap, QAbstractListModel *parent) :
    QAbstractListModel(parent),
    m_photos(photos),
    m_comments(comments),
    m_posts(posts),
    m_users(users),
    m_infoMap(infoMap)
{
    init();
}

void InfoDataModel::init()
{
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

InfoDataModel& InfoDataModel::operator=(const InfoDataModel& other)
{
    if (this != &other) {
        delete m_photos;
        m_photos = nullptr;
        m_photos = other.m_photos;

        delete m_comments;
        m_comments = nullptr;
        m_comments = other.m_comments;

        delete m_posts;
        m_posts = nullptr;
        m_posts = other.m_posts;

        delete m_users;
        m_users = nullptr;
        m_users = other.m_users;

        beginResetModel();
        m_infoMap.clear();
        m_infoMap = other.m_infoMap;
        endResetModel();
    }
    return *this;
}
