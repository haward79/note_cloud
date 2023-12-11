#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QFile>
#include <QUrl>
#include <QString>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

public:
    Settings();
    ~Settings();
    static const QString COMPANY;
    static const QString PRODUCT_NAME;
    static const quint8 TRIGGER_SIZE;
    bool is_loaded();
    bool load();
    bool save();
    bool update(QString, QUrl);
    bool update(QString, QString);
    bool update(QString, quint8);
    QVariant get(QString);

private:
    QUrl webdav_url;
    QString webdav_username;
    QString webdav_password;
    QString channel;
    quint8 note_fontSize;
    bool isLoaded;

signals:
    void onSave();
};

#endif // SETTINGS_H
