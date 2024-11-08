#ifndef TX_H
#define TX_H

#include <QObject>
#include <QDateTime>
#include <QQmlEngine>


class Tx : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString txId READ txId WRITE setTxId NOTIFY txIdChanged FINAL)
    Q_PROPERTY(int amount READ amount WRITE setAmount NOTIFY amountChanged FINAL)
    Q_PROPERTY(TxType txType READ txType CONSTANT)
    Q_PROPERTY(QString dt READ datetime CONSTANT)

public:
    enum TxType {
        Receive,
        Send
    };
    Q_ENUM(TxType)

public:
    explicit Tx(QObject *parent, const QString &txId, int amount, TxType type);

    QString txId();
    void setTxId(const QString &id);

    int amount();
    void setAmount(int value);

    TxType txType();

    QString datetime();

signals:
    void txIdChanged();
    void amountChanged();

private:
    QString tx_id;
    int amount_;
    TxType tx_type;
    QDateTime dt;
};

Q_DECLARE_METATYPE(Tx);
#endif // TX_H
