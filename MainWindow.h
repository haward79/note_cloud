#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStatusBar>
#include <QVBoxLayout>
#include "Settings.h"
#include "NoteEditWindow.h"
#include "NoteSettingWindow.h"
#include "Note.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Settings settings;
    NoteSettingWindow noteSettingWindow;
    Note note;
    NoteEditWindow noteEditWindow;
    QLabel label_note;
    QPushButton button_edit;
    QPushButton button_sync;
    QPushButton button_settings;
    QStatusBar statusBar;
    QVBoxLayout *layout_top;
    QHBoxLayout *layout_toolbar;

private slots:
    void handler_downloadStart();
    void handler_downloadStop();
    void handler_uploadStart();
    void handler_uploadStop();
    void updateNote();
    void updateNoteFontSize();
};
#endif // MAINWINDOW_H
