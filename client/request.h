#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>

class Request: public QObject
{
    Q_OBJECT

public:
    Request();
    void get(QString url);
    QNetworkAccessManager *manager;
};

#endif // REQUEST_H
