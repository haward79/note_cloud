#include "NoteSettingWindow.h"

NoteSettingWindow::NoteSettingWindow(Settings& settings, QWidget *parent) : QWidget{parent}, settings(settings)
{
    this->label_webdav_url.setText("WebDAV Url");
    this->label_webdav_username.setText("WebDAV Username");
    this->label_webdav_password.setText("WebDAV Password");
    this->label_channel.setText("Channel Name");
    this->label_note_fontSize.setText("Font Size for Note");
    this->textbox_webdav_url.setText(this->settings.get("webdav_url").toString());
    this->textbox_webdav_username.setText(this->settings.get("webdav_username").toString());
    this->textbox_webdav_password.setText(this->settings.get("webdav_password").toString());
    this->textbox_channel.setText(this->settings.get("channel").toString());
    this->textbox_note_fontSize.setText(this->settings.get("note_fontSize").toString());
    this->button_save.setText("Save");

    this->layout_form = new QFormLayout();
    this->layout_form->addRow(&this->label_webdav_url, &this->textbox_webdav_url);
    this->layout_form->addRow(&this->label_webdav_username, &this->textbox_webdav_username);
    this->layout_form->addRow(&this->label_webdav_password, &this->textbox_webdav_password);
    this->layout_form->addRow(&this->label_channel, &this->textbox_channel);
    this->layout_form->addRow(&this->label_note_fontSize, &this->textbox_note_fontSize);

    this->layout_top = new QVBoxLayout();
    this->layout_top->addLayout(this->layout_form);
    this->layout_top->addWidget(&this->button_save);

    this->setWindowTitle("Settings - Note");
    this->setFixedSize(600, 200);
    this->setLayout(this->layout_top);

    connect(&this->button_save, &QPushButton::released, this, &NoteSettingWindow::save);
}

void NoteSettingWindow::save()
{
    bool isValid;

    this->textbox_note_fontSize.text().toUInt(&isValid);

    if(isValid)
    {
        this->settings.update("webdav_url", QUrl(this->textbox_webdav_url.text()));
        this->settings.update("webdav_username", this->textbox_webdav_username.text());
        this->settings.update("webdav_password", this->textbox_webdav_password.text());
        this->settings.update("channel", this->textbox_channel.text());
        this->settings.update("note_fontSize", this->textbox_note_fontSize.text().toUInt());

        QMessageBox::information(this, "Settings Saved", "Settings are saved to the disk and this program just reload the new settings.");

        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Invalid Input", "Font size must be a positive number.");
    }
}
