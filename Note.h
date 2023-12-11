#ifndef NOTE_H
#define NOTE_H

#include <QThread>
#include <QMessageBox>
#include <QString>
#include "Sleep.h"
#include "Settings.h"
#include "WebDAVClient.h"

class Note : public QThread
{
    Q_OBJECT

public:
    Note(Settings&);
    QString getNote();
    bool setNote(QString);

public slots:
    void sync_manually();

private:
    Settings& settings;
    WebDAVClient *davClient;
    QJsonObject response;
    QString note;
    QString note_old;
    bool isSyncing;
    bool sync();
    bool sync(QString);
    void run();

signals:
    void downloadStart();
    void downloadStop();
    void uploadStart();
    void uploadStop();
    void noteChnaged();
};

#endif // NOTE_H
