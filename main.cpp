#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "qmlcontext.h"
#include <version.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setApplicationName(Product::NAME);
    app.setApplicationVersion(Product::VERSION);
    app.setOrganizationName(Product::MAINTAINER);
    app.setOrganizationDomain(Product::MAINTAINER_DOMAIN);

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/TestCryptoWallet/ui/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QmlContext *qml_context = new QmlContext(&app);
    engine.rootContext()->setContextProperty("context", qml_context);

    engine.load(url);

    return app.exec();
}
