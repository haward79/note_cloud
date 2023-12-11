#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AboutWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);

private:
    QLabel label_icon_old;
    QLabel label_icon_new;
    QLabel label_name;
    QLabel label_copyright;
    QLabel label_intro;
    QHBoxLayout *layout_icons;
    QVBoxLayout *layout_top;

signals:
};

#endif // ABOUTWINDOW_H
