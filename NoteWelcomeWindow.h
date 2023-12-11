#ifndef NOTEWELCOMEWINDOW_H
#define NOTEWELCOMEWINDOW_H

#include <QWidget>
#include <QThread>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

class NoteWelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWelcomeWindow(QWidget *parent = nullptr);

private:
    QVBoxLayout layout1;
    QHBoxLayout layout2;
    QPixmap image_icon;
    QLabel label_icon;
    QLabel label_note;
    QLabel label_copyright;

signals:
};

#endif // NOTEWELCOMEWINDOW_H
