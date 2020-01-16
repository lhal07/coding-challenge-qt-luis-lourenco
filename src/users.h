#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QList>

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

signals:
    void dataChanged();

private:
    QList<QVariantMap> m_users;

};

#endif // USERS_H
