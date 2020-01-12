#ifndef ALBUMS_H
#define ALBUMS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>

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

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_albums;

};

#endif // ALBUMS_H
