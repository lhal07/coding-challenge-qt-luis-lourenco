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
    albumsModel.registerTypes("Albums");
    PhotosListModel photosModel;
    photosModel.registerTypes("Albums");
    PostsListModel postsModel;
    postsModel.registerTypes("Albums");
    CommentsListModel commentsModel;
    commentsModel.registerTypes("Albums");

    const QUrl url(QStringLiteral("qrc:/src/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
