#include "NoteWelcomeWindow.h"

NoteWelcomeWindow::NoteWelcomeWindow(QWidget *parent) : QWidget{parent}
{
    this->image_icon = QPixmap("welcome.png");
    this->label_icon.setPixmap(this->image_icon);
    this->label_icon.setAlignment(Qt::AlignCenter);
    this->label_note.setText("Note Cloud");
    this->label_note.setFont(QFont("Arial", 50));
    this->label_note.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    this->label_copyright.setText("This is a Taiwancan product.\nhttps://www.taiwancan.tw/");
    this->label_copyright.setFont(QFont("Arial", 12));
    this->label_copyright.setAlignment(Qt::AlignCenter);
    this->label_copyright.setStyleSheet("color: #6a6a6a;");

    this->layout2.addWidget(&this->label_icon);
    this->layout2.addWidget(&this->label_note);

    this->layout1.setSpacing(20);
    this->layout1.setContentsMargins(20, 30, 20, 20);
    this->layout1.addLayout(&this->layout2, 1);
    this->layout1.addWidget(&this->label_copyright);

    this->setWindowTitle("Welcome - Note");
    this->setLayout(&this->layout1);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Drawer);
}
