#ifndef FREQUENCYWINDOW_H
#define FREQUENCYWINDOW_H

#include <QDialog>

namespace Ui {
class FrequencyWindow;
}

class FrequencyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FrequencyWindow(QWidget *parent = nullptr);
    ~FrequencyWindow();



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
    Ui::FrequencyWindow *ui;
};

#endif // FREQUENCYWINDOW_H
