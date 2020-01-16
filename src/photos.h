#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "requestmanager.h"

class Photos : public QObject
{
    Q_OBJECT
public:
    explicit Photos(QObject *parent = nullptr);
    virtual ~Photos() {};
    QList<QVariantMap> items();
    QVariant albumId(int);
    QVariant id(int);
    QVariant title(int);
    QVariant url(int);
    QVariant thumbnailUrl(int);
    int count();
    void fetchData();

public slots:
    void updateData(QString);

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_photos;
    Request m_request;

};

#endif // PHOTOS_H
