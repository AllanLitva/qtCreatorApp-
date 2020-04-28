#ifndef CHILDRENWINDOW_H
#define CHILDRENWINDOW_H

#include <QDialog>

namespace Ui {
class ChildrenWindow;
}

class ChildrenWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChildrenWindow(QWidget *parent = nullptr);
    ~ChildrenWindow();


signals:
     void buttonPressed();
     void buttonPressed1();
     void buttonPressed2();
     void buttonPressed3();
     void buttonPressed4();
     void buttonPressed5();
     void backPressed();




private slots:
    void on_up_clicked();
    void on_ok_clicked();
    void on_down_clicked();
    void on_back_pressed();


private:
    Ui::ChildrenWindow *ui;
};

#endif // CHILDRENWINDOW_H
