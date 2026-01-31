#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include "Request.h"
#include <QNetworkProxy>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QObject>
#include <QTimer>
#include <QThread>

namespace Network
{
class RequestSender : public QObject
{
    Q_OBJECT
public:
    enum RequestError
    {
        NoError,
        TimeoutError
    };

    RequestSender(qint64 maxWaitTime = 35000);
    ~RequestSender();

    void setProxy(const QNetworkProxy& proxy);

    QByteArray get(Request& request);
    QByteArray post(Request& request);

    QByteArray getWhileSuccess(Request& request, int maxCount = 2);
    QByteArray postWhileSuccess(Request& request, int maxCount = 2);

    qint64 maxWaitTime() const;
    void setMaxWaitTime(qint64 max);

    RequestError error() const;
private:
    QByteArray sendRequest(Request& request, bool getRequest = true);
    QByteArray sendWhileSuccess(Request& request, int maxCount = 2, bool getRequest = true);
private:
    qint64 _maxWaitTime;
    RequestError _error;
    QNetworkProxy _proxy;
};
}

#endif // REQUESTSENDER_H
