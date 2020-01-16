#ifndef POSTS_H
#define POSTS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "requestmanager.h"

class Posts : public QObject
{
    Q_OBJECT
public:
    explicit Posts(QObject *parent = nullptr);
    virtual ~Posts() {}
    QList<QVariantMap> items();
    QVariant userId(int);
    QVariant id(int);
    QVariant title(int);
    QVariant body(int);
    int count();
    void fetchData();

public slots:
    void updateData(QString);

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_posts;
    Request m_request;

};

#endif // POSTS_H
