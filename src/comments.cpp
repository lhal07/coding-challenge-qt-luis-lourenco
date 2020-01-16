#include "comments.h"

Comments::Comments(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_request, SIGNAL(replyFinished(QString)),
                     this, SLOT(updateData(QString)));
    fetchData();
}

void Comments::fetchData()
{
    m_request.sendRequest("https://jsonplaceholder.typicode.com/comments");
}

void Comments::updateData(QString newData)
{
    QJsonDocument doc = QJsonDocument::fromJson(newData.toUtf8());

    if(!doc.isNull()) {
        if(doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            foreach (const QJsonValue & value, jsonArray) {
                QJsonObject obj = value.toObject();
                m_comments.append(obj.toVariantMap());
            }
            emit dataChanged();
        }
        else if(doc.isObject()) {
            QJsonObject obj = doc.object();
            m_comments.append(obj.toVariantMap());
            emit dataChanged();
        }
    }
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
