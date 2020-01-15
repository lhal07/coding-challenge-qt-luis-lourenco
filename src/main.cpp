#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardPaths>

#include "albumslistmodel.h"
#include "photoslistmodel.h"
#include "postslistmodel.h"
#include "commentslistmodel.h"
#include "userslistmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();

    AlbumsListModel albumsModel;
    context->setContextProperty(QStringLiteral("albumsListModel"), &albumsModel);
    albumsModel.registerTypes("Albums");
    PhotosListModel photosModel;
    context->setContextProperty(QStringLiteral("photosListModel"), &photosModel);
    photosModel.registerTypes("Albums");
    PostsListModel postsModel;
    context->setContextProperty(QStringLiteral("postsListModel"), &postsModel);
    postsModel.registerTypes("Albums");
    CommentsListModel commentsModel;
    context->setContextProperty(QStringLiteral("commentsListModel"), &commentsModel);
    commentsModel.registerTypes("Albums");
    UsersListModel usersModel;
    context->setContextProperty(QStringLiteral("usersListModel"), &usersModel);
    usersModel.registerTypes("Albums");

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
