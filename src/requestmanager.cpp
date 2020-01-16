#include "requestmanager.h"

Request::Request()
    : QObject(0)
{
    m_manager = new QNetworkAccessManager();
    QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(managerFinished(QNetworkReply*)));
}

Request::~Request()
{
    this->disconnect();
}

void Request::managerFinished(QNetworkReply *reply) {
    if (reply->error()) {
        return;
    }

    QString answer = reply->readAll();
    emit replyFinished(answer);
}

void Request::sendRequest(QString url)
{
    m_request.setUrl(QUrl(url));
    m_manager->get(m_request);
}
