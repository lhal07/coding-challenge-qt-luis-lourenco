#ifndef ALBUMS_H
#define ALBUMS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "requestmanager.h"

class Albums : public QObject
{
    Q_OBJECT
public:
    explicit Albums(QObject *parent = nullptr);
    virtual ~Albums() {};
    QList<QVariantMap> items();
    QVariant userId(int);
    QVariant id(int);
    QVariant title(int);
    int count();
    void fetchData();

public slots:
    void updateData(QString);

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_albums;
    Request m_request;
};

#endif // ALBUMS_H
