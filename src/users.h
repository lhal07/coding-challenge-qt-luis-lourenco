#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "requestmanager.h"

class Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = nullptr);
    virtual ~Users() {}
    QList<QVariantMap> items();
    QVariant id(int);
    QVariant name(int);
    QVariant username(int);
    QVariant email(int);
    QVariant address(int);
    QVariant phone(int);
    QVariant website(int);
    QVariant company(int);
    int count();
    void fetchData();

public slots:
    void updateData(QString);

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_users;
    Request m_request;

};

#endif // USERS_H
