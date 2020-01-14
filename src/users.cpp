#include "users.h"

Users::Users(QObject *parent) :
    QObject(parent)
{
    /* Example Data while fetch is not implemented */
    QVariantMap data1;
    data1["id"] = 1;
    data1["name"] = "Leanne Graham";
    data1["username"] = "Bret";
    data1["email"] = "Sincere@april.biz";
    data1["address"] = "{\"street\": \"Kulas Light\", \"suite\": \"Apt. 556\", \"city\": \"Gwenborough\", \"zipcode\": \"92998-3874\" \"geo\": {\"lat\": \"-37.3159\", \"lng\": \"81.1496\" } }";
    data1["phone"] = "1-770-736-8031 x56442";
    data1["website"] = "hildegard.org";
    data1["company"] = "{\"name\": \"Romaguera-Crona\", \"catchPhrase\": \"Multi-layered client-server neural-net\", \"bs\": \"harness real-time e-markets\"}";

    QVariantMap data2;
    data2["id"] = 2;
    data2["name"] = "Ervin Howell";
    data2["username"] = "Antonette";
    data2["email"] = "Shanna@melissa.tv";
    data2["address"] = "{\"street\": \"Victor Plains\", \"suite\": \"Suite 879\", \"city\": \"Wisokyburgh\", \"zipcode\": \"90566-7771\", \"geo\": { \"lat\": \"-43.9509\", \"lng\": \"-34.4618\" } }";
    data2["phone"] = "010-692-6593 x09125";
    data2["website"] = "anastasia.net";
    data2["company"] = "{\"name\": \"Deckow-Crist\", \"catchPhrase\": \"Proactive didactic contingency\", \"bs\": \"synergize scalable supply-chains\" }";

    QVariantMap data3;
    data3["id"] = 3;
    data3["name"] = "Clementine Bauch";
    data3["username"] = "Samantha";
    data3["email"] = "Nathan@yesenia.net";
    data3["address"] = "{\"street\": \"Douglas Extension\", \"suite\": \"Suite 847\", \"city\": \"McKenziehaven\", \"zipcode\": \"59590-4157\", \"geo\": { \"lat\": \"-68.6102\", \"lng\": \"-47.0653\" } }";
    data3["phone"] = "1-463-123-4447";
    data3["website"] = "ramiro.info";
    data3["company"] = "{\"name\": \"Romaguera-Jacobson\", \"catchPhrase\": \"Face to face bifurcated interface\", \"bs\": \"e-enable strategic applications\" }";

    m_users.clear();
    m_users.append(data1);
    m_users.append(data2);
    m_users.append(data3);

    emit dataChanged();
}

QList<QVariantMap> Users::items() {
    return m_users;
}

QVariant Users::id(int index) {
    return QVariant(m_users.at(index)["id"]);
}

QVariant Users::name(int index) {
    return QVariant(m_users.at(index)["name"]);
}

QVariant Users::username(int index) {
    return QVariant(m_users.at(index)["username"]);
}

QVariant Users::email(int index) {
    return QVariant(m_users.at(index)["email"]);
}

QVariant Users::address(int index) {
    return QVariant(m_users.at(index)["address"]);
}

QVariant Users::phone(int index) {
    return QVariant(m_users.at(index)["phone"]);
}

QVariant Users::website(int index) {
    return QVariant(m_users.at(index)["website"]);
}

QVariant Users::company(int index) {
    return QVariant(m_users.at(index)["company"]);
}
