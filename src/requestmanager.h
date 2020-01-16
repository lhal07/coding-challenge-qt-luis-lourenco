#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QUrl>


class Request : public QObject
{
    Q_OBJECT

public:
    explicit Request();
    virtual ~Request();
    void sendRequest(QString url);

signals:
    void replyFinished(QString resp);

private slots:
    void managerFinished(QNetworkReply *reply);

private:

    QNetworkAccessManager *m_manager;
    QNetworkRequest        m_request;
};

#endif // REQUESTMANAGER_H
