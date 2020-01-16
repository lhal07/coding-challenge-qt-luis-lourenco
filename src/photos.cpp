#include "photos.h"

Photos::Photos(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_request, SIGNAL(replyFinished(QString)),
                     this, SLOT(updateData(QString)));
    fetchData();
}

void Photos::fetchData()
{
    m_request.sendRequest("https://jsonplaceholder.typicode.com/photos");
}

void Photos::updateData(QString newData)
{
    QJsonDocument doc = QJsonDocument::fromJson(newData.toUtf8());

    if(!doc.isNull()) {
        if(doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            foreach (const QJsonValue & value, jsonArray) {
                QJsonObject obj = value.toObject();
                m_photos.append(obj.toVariantMap());
            }
            emit dataChanged();
        }
        else if(doc.isObject()) {
            QJsonObject obj = doc.object();
            m_photos.append(obj.toVariantMap());
            emit dataChanged();
        }
    }
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

int Photos::count() {
    return m_photos.count();
}
