#include "comments.h"

Comments::Comments(QObject *parent) :
    QObject(parent)
{
    /* Example Data while fetch is not implemented */
    QVariantMap data1;
    data1["postId"] = 1;
    data1["id"] = 1;
    data1["name"] ="id labore ex et quam laborum";
    data1["email"] = "Eliseo@gardner.biz";
    data1["body"] = "laudantium enim quasi es…am sapiente accusantium";

    QVariantMap data2;
    data2["postId"] = 1;
    data2["id"] = 2;
    data2["name"] = "quo vero reiciendis velit similique earum";
    data2["email"] = "Jayne_Kuhic@sydney.com";
    data2["body"] = "est natus enim nihil est…oluptatem reiciendis et";

    QVariantMap data3;
    data3["postId"] = 1;
    data3["id"] = 3;
    data3["name"] = "odio adipisci rerum aut animi";
    data3["email"] = "Nikita@garfield.biz";
    data3["body"] = "quia molestiae reprehend…epturi deleniti ratione";

    m_comments.clear();
    m_comments.append(data1);
    m_comments.append(data2);
    m_comments.append(data3);

    emit dataChanged();
}

QList<QVariantMap> Comments::items() {
    return m_comments;
}

QVariant Comments::postId(int index) {
    return QVariant(m_comments.at(index)["postId"]);
}

QVariant Comments::id(int index) {
    return QVariant(m_comments.at(index)["id"]);
}

QVariant Comments::name(int index) {
    return QVariant(m_comments.at(index)["name"]);
}

QVariant Comments::email(int index) {
    return QVariant(m_comments.at(index)["email"]);
}

QVariant Comments::body(int index) {
    return QVariant(m_comments.at(index)["body"]);
}

int Comments::count() {
    return m_comments.count();
}
