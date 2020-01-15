#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "albumslistmodel.h"
#include "photoslistmodel.h"
#include "postslistmodel.h"
#include "commentslistmodel.h"
#include "userslistmodel.h"
#include "infodatamodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    AlbumsListModel albumsModel;
    albumsModel.registerTypes("Albums");
    PhotosListModel photosModel;
    photosModel.registerTypes("Albums");
    PostsListModel postsModel;
    postsModel.registerTypes("Albums");
    CommentsListModel commentsModel;
    commentsModel.registerTypes("Albums");
    UsersListModel usersModel;
    usersModel.registerTypes("Albums");
    InfoDataModel infoDataModel;
    infoDataModel.registerTypes("Albums");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
