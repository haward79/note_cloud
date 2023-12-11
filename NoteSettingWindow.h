#ifndef NOTESETTINGWINDOW_H
#define NOTESETTINGWINDOW_H

#include <QWidget>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "Settings.h"

class NoteSettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoteSettingWindow(Settings&, QWidget *parent = nullptr);

private:
    QLabel label_webdav_url;
    QLabel label_webdav_username;
    QLabel label_webdav_password;
    QLabel label_channel;
    QLabel label_note_fontSize;
    QLineEdit textbox_webdav_url;
    QLineEdit textbox_webdav_username;
    QLineEdit textbox_webdav_password;
    QLineEdit textbox_channel;
    QLineEdit textbox_note_fontSize;
    QPushButton button_save;
    QFormLayout* layout_form;
    QVBoxLayout* layout_top;
    Settings& settings;
    void save();

signals:
};

#endif // NOTESETTINGWINDOW_H
