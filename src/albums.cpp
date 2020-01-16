#include "albums.h"

Albums::Albums(QObject *parent) :
    QObject(parent)
{

    QObject::connect(&m_request, SIGNAL(replyFinished(QString)),
                     this, SLOT(updateData(QString)));
    fetchData();
}

void Albums::fetchData()
{
    m_request.sendRequest("https://jsonplaceholder.typicode.com/albums");
}

void Albums::updateData(QString newData)
{
    QJsonDocument doc = QJsonDocument::fromJson(newData.toUtf8());

    if(!doc.isNull()) {
        if(doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            foreach (const QJsonValue & value, jsonArray) {
                QJsonObject obj = value.toObject();
                m_albums.append(obj.toVariantMap());
            }
            emit dataChanged();
        }
        else if(doc.isObject()) {
            QJsonObject obj = doc.object();
            m_albums.append(obj.toVariantMap());
            emit dataChanged();
        }
    }
}

QList<QVariantMap> Albums::items() {
    return m_albums;
}

QVariant Albums::userId(int index) {
    return QVariant(m_albums.at(index)["userId"]);
}

QVariant Albums::id(int index) {
    return QVariant(m_albums.at(index)["id"]);
}

QVariant Albums::title(int index) {
    return QVariant(m_albums.at(index)["title"]);
}

int Albums::count() {
    return m_albums.count();
}
