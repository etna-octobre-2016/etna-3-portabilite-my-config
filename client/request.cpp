#include "request.h"
#include <QList>
#include <QSslError>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

Request::Request()
{
    manager = new QNetworkAccessManager(this);
}

void Request::get(QString url)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    manager->get(request);
}
