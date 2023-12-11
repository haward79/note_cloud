#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget{parent}, noteSettingWindow(settings), note(settings), noteEditWindow(note)
{
    this->label_note.setText("Syncing ......");
    this->label_note.setFont(*(new QFont("", this->settings.get("note_fontSize").toUInt())));
    this->label_note.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->label_note.setStyleSheet("padding: 10px; background-color: #fff6d1;");
    this->button_edit.setText("Edit");
    this->button_sync.setText("Sync");
    this->button_settings.setText("Settings");
    this->statusBar.setStyleSheet("border: 1px solid #c5c5c5;");

    this->layout_toolbar = new QHBoxLayout();
    this->layout_toolbar->addStretch();
    this->layout_toolbar->addWidget(&this->button_edit);
    this->layout_toolbar->addWidget(&this->button_sync);
    this->layout_toolbar->addWidget(&this->button_settings);

    this->layout_top = new QVBoxLayout();
    this->layout_top->addLayout(this->layout_toolbar);
    this->layout_top->addWidget(&this->label_note, 1);
    this->layout_top->addWidget(&this->statusBar);

    this->setWindowTitle("View Notes - Note");
    this->setMinimumWidth(500);
    this->setMinimumHeight(600);
    this->setLayout(this->layout_top);
    this->setAttribute(Qt::WA_InputMethodEnabled);

    // Show note sync messages.
    connect(&this->note, &Note::downloadStart, this, &MainWindow::handler_downloadStart);
    connect(&this->note, &Note::downloadStop, this, &MainWindow::handler_downloadStop);
    connect(&this->note, &Note::uploadStart, this, &MainWindow::handler_uploadStart);
    connect(&this->note, &Note::uploadStop, this, &MainWindow::handler_uploadStop);

    // Do note sync routine.
    this->note.start();
    connect(&this->note, &Note::noteChnaged, this, &MainWindow::updateNote);

    // Button trigger.
    connect(&this->button_edit, &QPushButton::clicked, &this->noteEditWindow, &NoteEditWindow::show);
    connect(&this->button_sync, &QPushButton::clicked, &this->note, &Note::sync_manually);
    connect(&this->button_settings, &QPushButton::clicked, &this->noteSettingWindow, &NoteSettingWindow::show);

    // Setting save trigger.
    connect(&this->settings, &Settings::onSave, this, &MainWindow::updateNoteFontSize);
}

MainWindow::~MainWindow() {}

void MainWindow::handler_downloadStart()
{
    this->button_sync.setEnabled(false);
    this->statusBar.showMessage("Downloading note from cloud.");
}

void MainWindow::handler_downloadStop()
{
    this->button_sync.setEnabled(true);
    this->statusBar.showMessage("Downloaded note from cloud.");
}

void MainWindow::handler_uploadStart()
{
    this->statusBar.showMessage("Uploading note to cloud.");
}

void MainWindow::handler_uploadStop()
{
    this->statusBar.showMessage("Uploaded note to cloud.");
}

void MainWindow::updateNote()
{
    this->label_note.setText(this->note.getNote());
}

void MainWindow::updateNoteFontSize()
{
    this->label_note.setFont(*(new QFont("", this->settings.get("note_fontSize").toUInt())));
}
