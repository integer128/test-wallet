#ifndef VERSION_H
#define VERSION_H

#include <QString>
#include <QStringLiteral>


namespace Product {
    static const QString MAINTAINER = "MAINTAINER";
    static const QString MAINTAINER_DOMAIN = "MAINTAINER DOMAIN";
    static const QString MAINTAINER_URL = "https://" + MAINTAINER_DOMAIN + "/";
    static const QString NAME = "APPNAME";
    static const QString SHORT_NAME = "SHORT APPNAME";
    static const QString VERSION = "0.0.1";
}

namespace Gui{
    static const QString QML_STYLE = "Material";
    static const QString QML_FILE = "main.qml";
    static const QString QML_CONTEXT_NAME = "context";
    static const QString DEFAULT_THEME_NAME = "light";
    static const int DEFAULT_FONT_POINT_SIZE = 10;
}
#endif // VERSION_H
