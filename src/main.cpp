#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "albumslistmodel.h"
#include "photoslistmodel.h"
#include "postslistmodel.h"
#include "commentslistmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    AlbumsListModel albumsModel;
    albumsModel.registerTypes("Albums.type");
    PhotosListModel photosModel;
    photosModel.registerTypes("Albums.type");
    PostsListModel postsModel;
    postsModel.registerTypes("Albums.type");
    CommentsListModel commentsModel;
    commentsModel.registerTypes("Albums.type");
    UsersListModel usersModel;
    usersModel.registerTypes("Albums.type");

    const QUrl url(QStringLiteral("qrc:/src/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
