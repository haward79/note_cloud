#ifndef NOTEEDITWINDOW_H
#define NOTEEDITWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "Note.h"

class NoteEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoteEditWindow(Note&, QWidget *parent = nullptr);

private:
    Note& note;
    QTextEdit textarea_note;
    QPushButton button_save;
    QVBoxLayout *layout_top;
    void updateNote();
    void showEvent(QShowEvent*);

signals:
};

#endif // NOTEEDITWINDOW_H
