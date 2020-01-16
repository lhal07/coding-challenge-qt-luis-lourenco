#ifndef COMMENTS_H
#define COMMENTS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "requestmanager.h"

class Comments : public QObject
{
    Q_OBJECT
public:
    explicit Comments(QObject *parent = nullptr);
    virtual ~Comments() {}
    QList<QVariantMap> items();
    QVariant postId(int);
    QVariant id(int);
    QVariant name(int);
    QVariant email(int);
    QVariant body(int);
    int count();
    void fetchData();

public slots:
    void updateData(QString);

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_comments;
    Request m_request;

};

#endif // COMMENTS_H
