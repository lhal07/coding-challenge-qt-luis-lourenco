#ifndef COMMENTS_H
#define COMMENTS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>

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

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_comments;

};

#endif // COMMENTS_H
