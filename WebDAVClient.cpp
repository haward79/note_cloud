#include "WebDAVClient.h"

WebDAVClient::WebDAVClient(QObject *parent) : QObject{parent}
{
    this->username = "anon";
    this->password = "anon";

    this->init();
}

void WebDAVClient::setUsername(QString username)
{
    this->username = username;
}

void WebDAVClient::setPassword(QString password)
{
    this->password = password;
}

void WebDAVClient::init()
{
    this->networkManager = nullptr;
    this->reply = nullptr;
    this->hasError = false;
    this->errorMsg = "";
}

void WebDAVClient::onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qDebug() << "Authenticating using username " << this->username << ".";

    authenticator->setUser(this->username);
    authenticator->setPassword(this->password);
}

void WebDAVClient::onProgress(qint64 bytesProcessed, qint64 bytesTotal)
{
    qDebug() << "Processed " << bytesProcessed << " / Total " << bytesTotal << " bytes.";
}

void WebDAVClient::onNetworkError(QNetworkReply::NetworkError code)
{
    this->hasError = true;
    this->errorMsg = this->reply->errorString();

    qDebug() << "Network error code: " << code;
}

QJsonObject WebDAVClient::downloadFile(QUrl url)
{
    // Reset stateful variables.
    this->init();

    // Setup connection.
    this->networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::authenticationRequired, this, &WebDAVClient::onAuthenticationRequired);

    // Send GET request.
    reply = networkManager->get(*(new QNetworkRequest(url)));

    // Connect signals.
    QEventLoop waitComplete;
    connect(reply, &QNetworkReply::downloadProgress, this, &WebDAVClient::onProgress);
    connect(reply, &QNetworkReply::errorOccurred, this, &WebDAVClient::onNetworkError);
    connect(reply, &QNetworkReply::finished, &waitComplete, &QEventLoop::quit);

    waitComplete.exec();

    return this->generateResponse();
}

QJsonObject WebDAVClient::uploadFile(QUrl url, QString data)
{
    // Reset stateful variables.
    this->init();

    // Setup connection.
    this->networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::authenticationRequired, this, &WebDAVClient::onAuthenticationRequired);

    // Send PUT request.
    reply = networkManager->put(*(new QNetworkRequest(url)), data.toUtf8());

    // Connect signals.
    QEventLoop waitComplete;
    connect(reply, &QNetworkReply::uploadProgress, this, &WebDAVClient::onProgress);
    connect(reply, &QNetworkReply::errorOccurred, this, &WebDAVClient::onNetworkError);
    connect(reply, &QNetworkReply::finished, &waitComplete, &QEventLoop::quit);

    waitComplete.exec();

    return this->generateResponse();
}

QJsonObject WebDAVClient::generateResponse()
{
    QJsonObject response;

    qDebug() << "Generating response.";

    if(this->hasError)
    {
        response.insert("status", false);
        response.insert("data", this->errorMsg);
    }
    else
    {
        QString data = QString(this->reply->readAll());

        qDebug() << "Process complete. " << data.size() << " bytes processed.";

        response.insert("status", true);
        response.insert("data", data);
    }

    return response;
}
