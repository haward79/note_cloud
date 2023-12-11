#include "Note.h"

Note::Note(Settings& settings) : settings(settings)
{
    this->note = "";
    this->note_old = "";
    this->isSyncing = false;
}

QString Note::getNote()
{
    return this->note;
}

bool Note::setNote(QString note)
{
    return this->sync(note);
}

bool Note::sync()
{
    emit downloadStart();

    this->davClient = new WebDAVClient();
    this->davClient->setUsername(this->settings.get("webdav_username").toString());
    this->davClient->setPassword(this->settings.get("webdav_password").toString());
    this->response = this->davClient->downloadFile(QUrl(this->settings.get("webdav_url_note").toString()));

    if(this->response["status"].toBool())
    {
        this->note_old = this->note;
        this->note = this->response["data"].toString();

        if(this->note != this->note_old)
        {
            emit noteChnaged();
        }

        emit downloadStop();
        return true;
    }
    else
    {
        qDebug() << "Note sync failed due to: " << this->response["data"].toString();
    }

    emit downloadStop();
    return false;
}

bool Note::sync(QString note)
{
    emit uploadStart();
    this->isSyncing = true;
    this->davClient = new WebDAVClient();
    this->davClient->setUsername(this->settings.get("webdav_username").toString());
    this->davClient->setPassword(this->settings.get("webdav_password").toString());
    this->response = this->davClient->uploadFile(QUrl(this->settings.get("webdav_url_note").toString()), note);
    this->isSyncing = false;
    emit uploadStop();

    return this->response["status"].toBool() && this->sync();
}

void Note::sync_manually()
{
    if(this->sync())
    {
        QMessageBox::information(nullptr, "Note Synced", "Note has been synced successfully.");
    }
    else
    {
        QMessageBox::warning(nullptr, "Note NOT Sync", "Note is unable to been synced.");
    }
}

void Note::run()
{
    while(true)
    {
        if(!this->isSyncing)
        {
            sync();
        }

        Sleep::sleep(60);
    }
}
