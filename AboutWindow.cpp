#include "AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) : QWidget{parent}
{
    this->label_icon_old.setPixmap(QPixmap("welcome.png").scaledToHeight(70));
    this->label_icon_new.setPixmap(QPixmap("icon.png").scaledToHeight(70));
    this->label_name.setText("Note (Cloud Edition)\nThis is a Taiwancan product.\nhttps://www.taiwancan.tw/");
    this->label_name.setAlignment(Qt::AlignCenter);
    this->label_copyright.setText("These two icons are designed and owned by Taiwancan.\nCopyrights are reserved by Taiwancan for the two icons.");
    this->label_copyright.setAlignment(Qt::AlignCenter);
    this->label_intro.setText("This is a simple note taking software on desktop with cloud sync feature. We hope there is some day for us to push this application on the smart phone platform! Please check more information on our office website.");
    this->label_intro.setWordWrap(true);
    this->label_intro.setAlignment(Qt::AlignCenter);

    this->layout_icons = new QHBoxLayout();
    this->layout_icons->addStretch();
    this->layout_icons->addWidget(&this->label_icon_old);
    this->layout_icons->addWidget(&this->label_icon_new);
    this->layout_icons->addStretch();

    this->layout_top = new QVBoxLayout();
    this->layout_top->setSpacing(30);
    this->layout_top->setContentsMargins(30, 50, 30, 40);
    this->layout_top->addLayout(this->layout_icons);
    this->layout_top->addWidget(&this->label_copyright);
    this->layout_top->addWidget(&this->label_name);
    this->layout_top->addWidget(&this->label_intro);
    this->layout_top->addStretch();

    this->setLayout(this->layout_top);
    this->setWindowTitle("About - Note");
}
