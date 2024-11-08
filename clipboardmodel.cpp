#include "clipboardmodel.h"

#include <QStringLiteral>

ClipboardModel::ClipboardModel(QGuiApplication *parent)
    : QObject(parent)
    , clipboard(parent->clipboard())
{
    connect(clipboard, &QClipboard::changed, this, &ClipboardModel::onChaged);
}

void ClipboardModel::setText(const QString &str)
{
    clipboard->setText(str);

    emit textChanged();
}

void ClipboardModel::onChaged(QClipboard::Mode mode)
{
    if (mode == QClipboard::Mode::Clipboard)
        emit textChanged();
}

QString ClipboardModel::text()
{
    return clipboard->text();
}
