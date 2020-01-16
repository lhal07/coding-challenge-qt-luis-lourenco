#ifndef POSTS_H
#define POSTS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>

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

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_posts;

};

#endif // POSTS_H
