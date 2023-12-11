#include "Settings.h"

const QString Settings::COMPANY = "Taiwancan";
const QString Settings::PRODUCT_NAME = "note-cloud";
const quint8 Settings::TRIGGER_SIZE = 40;

Settings::Settings()
{
    QSettings settings(Settings::COMPANY, Settings::PRODUCT_NAME);

    qDebug() << "File path of settings: " << settings.fileName().toStdString().c_str();

    if(QFile(settings.fileName()).exists())
    {
        this->load();
        qDebug() << "Setting file exists. Settings loaded.";
    }
    else
    {
        this->webdav_url = QUrl("https://owncloud.local/remote.php/dav/files/USERNAME/FOLDER/");
        this->webdav_username = "USERNAME";
        this->webdav_password = "PASSWORD";
        this->channel = "work";
        this->note_fontSize = 11;
        this->isLoaded = false;

        qDebug() << "Setting file NOT exists. Default settings set but NOT written.";
    }
}

Settings::~Settings() {}

bool Settings::is_loaded()
{
    return this->isLoaded;
}

bool Settings::load()
{
    QSettings settings(Settings::COMPANY, Settings::PRODUCT_NAME);
    QVariant webdav_url = settings.value("webdav_url");
    QVariant webdav_username = settings.value("webdav_username");
    QVariant webdav_password = settings.value("webdav_password");
    QVariant channel = settings.value("channel");
    QVariant note_fontSize = settings.value("note_fontSize");

    if(!webdav_url.isNull())
    {
        this->webdav_url = webdav_url.toUrl();
    }

    if(!webdav_username.isNull())
    {
        this->webdav_username = webdav_username.toString();
    }

    if(!webdav_password.isNull())
    {
        this->webdav_password = webdav_password.toString();
    }

    if(!channel.isNull())
    {
        this->channel = channel.toString();
    }

    if(!note_fontSize.isNull())
    {
        this->note_fontSize = note_fontSize.toUInt();
    }

    // Settings loaded.
    this->isLoaded = true;

    return this->isLoaded;
}

bool Settings::save()
{
    QSettings settings(Settings::COMPANY, Settings::PRODUCT_NAME);

    settings.setValue("webdav_url", this->webdav_url);
    settings.setValue("webdav_username", this->webdav_username);
    settings.setValue("webdav_password", this->webdav_password);
    settings.setValue("channel", this->channel);
    settings.setValue("note_fontSize", this->note_fontSize);

    settings.sync();

    // Settings loaded.
    this->isLoaded = true;

    emit onSave();

    return true;
}

bool Settings::update(QString key, QUrl value)
{
    bool hasUpdate = false;

    if(key == "webdav_url")
    {
        this->webdav_url = value;
        hasUpdate = true;
    }

    return hasUpdate && this->save();
}

bool Settings::update(QString key, QString value)
{
    bool hasUpdate = false;

    if(key == "webdav_username")
    {
        this->webdav_username = value;
        hasUpdate = true;
    }
    else if(key == "webdav_password")
    {
        this->webdav_password = value;
        hasUpdate = true;
    }
    else if(key == "channel")
    {
        this->channel = value;
        hasUpdate = true;
    }

    return hasUpdate && this->save();
}

bool Settings::update(QString key, quint8 value)
{
    bool hasUpdate = false;

    if(key == "note_fontSize")
    {
        this->note_fontSize = value;
        hasUpdate = true;
    }

    return hasUpdate && this->save();
}

QVariant Settings::get(QString key)
{
    if(key == "webdav_url_note")
    {
        QString url = this->webdav_url.toString();

        if(!url.endsWith("/"))
        {
            url += "/";
        }

        url += "note-" + this->channel + ".txt";

        return QVariant(url);
    }
    else if(key == "webdav_url")
    {
        return QVariant(this->webdav_url);
    }
    else if(key == "webdav_username")
    {
        return QVariant(this->webdav_username);
    }
    else if(key == "webdav_password")
    {
        return QVariant(this->webdav_password);
    }
    else if(key == "channel")
    {
        return QVariant(this->channel);
    }
    else if(key == "note_fontSize")
    {
        return QVariant(this->note_fontSize);
    }

    return QVariant();
}
