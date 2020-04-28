#ifndef PROGRAMSWINDOW_H
#define PROGRAMSWINDOW_H

#include <QDialog>

namespace Ui {
class ProgramsWindow;
}

class ProgramsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProgramsWindow(QWidget *parent = nullptr);
    ~ProgramsWindow();





signals:
     void buttonPressed();
     void buttonPressed1();
     void buttonPressed2();
     void buttonPressed3();
     void buttonPressed4();
     void buttonPressed5();

     void backPressed();






private slots:


    void on_programUp_clicked();
    void on_programOk_clicked();
    void on_programDown_clicked();
    void on_back_pressed();

private:
    Ui::ProgramsWindow *ui;
};

#endif // PROGRAMSWINDOW_H
