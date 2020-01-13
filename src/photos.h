#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>

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

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_photos;

};

#endif // PHOTOS_H
