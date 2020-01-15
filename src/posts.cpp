#include "posts.h"

Posts::Posts(QObject *parent) :
    QObject(parent)
{
    /* Example Data while fetch is not implemented */
    QVariantMap data1;
    data1["userId"] = 1;
    data1["id"] = 1;
    data1["title"] = "sunt aut facere repellat provident occaecati excepturi optio reprehenderit";
    data1["body"] = "quia et suscipit\nsuscipit recusandae consequuntur expedita et cum\nreprehenderit molestiae ut ut quas totam\nnostrum rerum est autem sunt rem eveniet architecto";

    QVariantMap data2;
    data2["userId"] = 1;
    data2["id"] = 2;
    data2["title"] = "qui est esse";
    data2["body"] = "est rerum tempore vitae\nsequi sint nihil reprehenderit dolor beatae ea dolores neque\nfugiat blanditiis voluptate porro vel nihil molestiae ut reiciendis\nqui aperiam non debitis possimus qui neque nisi nulla";

    QVariantMap data3;
    data3["userId"] = 1;
    data3["id"] = 3;
    data3["title"] = "ea molestias quasi exercitationem repellat qui ipsa sit aut";
    data3["body"] = "et iusto sed quo iure\nvoluptatem occaecati omnis eligendi aut ad\nvoluptatem doloribus vel accusantium quis pariatur\nmolestiae porro eius odio et labore et velit aut";

    m_posts.clear();
    m_posts.append(data1);
    m_posts.append(data2);
    m_posts.append(data3);

    emit dataChanged();
}

QList<QVariantMap> Posts::items() {
    return m_posts;
}

QVariant Posts::userId(int index) {
    return QVariant(m_posts.at(index)["userId"]);
}

QVariant Posts::id(int index) {
    return QVariant(m_posts.at(index)["id"]);
}

QVariant Posts::title(int index) {
    return QVariant(m_posts.at(index)["title"]);
}

QVariant Posts::body(int index) {
    return QVariant(m_posts.at(index)["body"]);
}

int Posts::count() {
    return m_posts.count();
}
