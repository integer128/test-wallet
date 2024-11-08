#ifndef CLIPBOARDMODEL_H
#define CLIPBOARDMODEL_H

#include <QObject>
#include <QGuiApplication>
#include <QClipboard>


class ClipboardModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged FINAL)

public:
    explicit ClipboardModel(QGuiApplication *parent = nullptr);

    QString text();
    void setText(const QString &str);

public slots:
    void onChaged(QClipboard::Mode mode);

signals:
    void textChanged();

private:
    QClipboard *clipboard;
};
Q_DECLARE_METATYPE(ClipboardModel);

#endif // CLIPBOARDMODEL_H
