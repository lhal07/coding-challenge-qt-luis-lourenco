#include "photos.h"

Photos::Photos(QObject *parent) :
    QObject(parent)
{
    /* Example Data while fetch is not implemented */
    QVariantMap data1;
    data1["albumId"] = 1;
    data1["id"] = 1;
    data1["title"] = "accusamus beatae ad facilis cum similique qui sunt";
    data1["url"] = "https://via.placeholder.com/600/92c952";
    data1["thumbnailUrl"] = "https://via.placeholder.com/150/92c952";

    QVariantMap data2;
    data2["albumId"] = 1;
    data2["id"] = 2;
    data2["title"] = "reprehenderit est deserunt velit ipsam";
    data2["url"] = "https://via.placeholder.com/600/771796";
    data2["thumbnailUrl"] = "https://via.placeholder.com/150/771796";

    QVariantMap data3;
    data3["albumId"] = 1;
    data3["id"] = 3;
    data3["title"] = "officia porro iure quia iusto qui ipsa ut modi";
    data3["url"] = "https://via.placeholder.com/600/24f355";
    data3["thumbnailUrl"] = "https://via.placeholder.com/150/24f355";

    m_photos.clear();
    m_photos.append(data1);
    m_photos.append(data2);
    m_photos.append(data3);

    emit dataChanged();
}

QList<QVariantMap> Photos::items() {
    return m_photos;
}

QVariant Photos::albumId(int index) {
    return QVariant(m_photos.at(index)["userId"]);
}

QVariant Photos::id(int index) {
    return QVariant(m_photos.at(index)["id"]);
}

QVariant Photos::title(int index) {
    return QVariant(m_photos.at(index)["title"]);
}

QVariant Photos::url(int index) {
    return QVariant(m_photos.at(index)["url"]);
}

QVariant Photos::thumbnailUrl(int index) {
    return QVariant(m_photos.at(index)["thumbnailUrl"]);
}
