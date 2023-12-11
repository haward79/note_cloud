#include "NoteEditWindow.h"

NoteEditWindow::NoteEditWindow(Note& note, QWidget *parent) : QWidget{parent}, note(note)
{
    this->textarea_note.setText("");
    this->button_save.setText("Save");

    this->layout_top = new QVBoxLayout();
    this->layout_top->addWidget(&this->textarea_note);
    this->layout_top->addWidget(&this->button_save);

    this->setWindowTitle("Edit Note - Note");
    this->setMinimumWidth(500);
    this->setMinimumHeight(600);
    this->setLayout(this->layout_top);

    connect(&this->button_save, &QPushButton::clicked, this, &NoteEditWindow::updateNote);
}

void NoteEditWindow::updateNote()
{
    this->close();
    this->note.setNote(this->textarea_note.toPlainText());
}

void NoteEditWindow::showEvent(QShowEvent* event)
{
    this->textarea_note.setText(this->note.getNote());
}
