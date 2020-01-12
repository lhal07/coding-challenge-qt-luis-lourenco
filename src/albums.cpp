#include "albums.h"

Albums::Albums(QObject *parent) :
    QObject(parent)
{
    /* Example Data while fetch is not implemented */
    QVariantMap data1;
    data1["userId"] = 1;
    data1["id"] = 1;
    data1["title"] = "quidem molestiae enim";

    QVariantMap data2;
    data2["userId"] = 1;
    data2["id"] = 2;
    data2["title"] = "sunt qui excepturi placeat culpa";

    QVariantMap data3;
    data3["userId"] = 1;
    data3["id"] = 3;
    data3["title"] = "omnis laborum odio";

    m_albums.clear();
    m_albums.append(data1);
    m_albums.append(data2);
    m_albums.append(data3);

    emit dataChanged();
}

QList<QVariantMap> Albums::items() {
    return m_albums;
}

QVariant Albums::userId(int index) {
    return QVariant(m_albums.at(index)["userId"]);
}

QVariant Albums::id(int index) {
    return QVariant(m_albums.at(index)["userId"]);
}

QVariant Albums::title(int index) {
    return QVariant(m_albums.at(index)["userId"]);
}
