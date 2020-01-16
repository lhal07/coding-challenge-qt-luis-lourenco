#include "posts.h"

Posts::Posts(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_request, SIGNAL(replyFinished(QString)),
                     this, SLOT(updateData(QString)));
    fetchData();
}

void Posts::fetchData()
{
    m_request.sendRequest("https://jsonplaceholder.typicode.com/posts");
}

void Posts::updateData(QString newData)
{
    QJsonDocument doc = QJsonDocument::fromJson(newData.toUtf8());

    if(!doc.isNull()) {
        if(doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            foreach (const QJsonValue & value, jsonArray) {
                QJsonObject obj = value.toObject();
                m_posts.append(obj.toVariantMap());
            }
            emit dataChanged();
        }
        else if(doc.isObject()) {
            QJsonObject obj = doc.object();
            m_posts.append(obj.toVariantMap());
            emit dataChanged();
        }
    }
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
