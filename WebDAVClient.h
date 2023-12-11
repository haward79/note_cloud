#ifndef WEBDAVCLIENT_H
#define WEBDAVCLIENT_H

#include <QApplication>
#include <QObject>
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QJsonObject>
#include <QEventLoop>

class WebDAVClient : public QObject
{
    Q_OBJECT

public:
    WebDAVClient(QObject * = nullptr);
    void setUsername(QString);
    void setPassword(QString);
    QJsonObject downloadFile(QUrl);
    QJsonObject uploadFile(QUrl, QString);

private:
    QString username;
    QString password;
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;
    bool hasError;
    QString errorMsg;
    void init();
    QJsonObject generateResponse();

private slots:
    void onAuthenticationRequired(QNetworkReply *, QAuthenticator *);
    void onProgress(qint64, qint64);
    void onNetworkError(QNetworkReply::NetworkError);

signals:
};

#endif // WEBDAVCLIENT_H
