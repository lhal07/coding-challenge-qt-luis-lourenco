#include "users.h"

Users::Users(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_request, SIGNAL(replyFinished(QString)),
                     this, SLOT(updateData(QString)));
    fetchData();
}

void Users::fetchData()
{
    m_request.sendRequest("https://jsonplaceholder.typicode.com/users");
}

void Users::updateData(QString newData)
{
    QJsonDocument doc = QJsonDocument::fromJson(newData.toUtf8());

    if(!doc.isNull()) {
        if(doc.isArray()) {
            QJsonArray jsonArray = doc.array();
            foreach (const QJsonValue & value, jsonArray) {
                QJsonObject obj = value.toObject();
                m_users.append(obj.toVariantMap());
            }
            emit dataChanged();
        }
        else if(doc.isObject()) {
            QJsonObject obj = doc.object();
            m_users.append(obj.toVariantMap());
            emit dataChanged();
        }
    }
}

QList<QVariantMap> Users::items()
{
    return m_users;
}

QVariant Users::id(int index)
{
    return QVariant(m_users.at(index)["id"]);
}

QVariant Users::name(int index)
{
    return QVariant(m_users.at(index)["name"]);
}

QVariant Users::username(int index)
{
    return QVariant(m_users.at(index)["username"]);
}

QVariant Users::email(int index)
{
    return QVariant(m_users.at(index)["email"]);
}

QVariant Users::address(int index)
{
    return QVariant(m_users.at(index)["address"]);
}

QVariant Users::phone(int index)
{
    return QVariant(m_users.at(index)["phone"]);
}

QVariant Users::website(int index)
{
    return QVariant(m_users.at(index)["website"]);
}

QVariant Users::company(int index)
{
    return QVariant(m_users.at(index)["company"]);
}

int Users::count()
{
    return m_users.count();
}
