#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "programswindow.h"
#include "frequencywindow.h"
#include "childrenwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




public slots:
    void timerFn();


    void changeTextProg();
    void changeTextProg1();
    void changeTextProg2();
    void changeTextProg3();
    void changeTextProg4();
    void changeTextProg5();


    void changeTextFreq();
    void changeTextFreq1();
    void changeTextFreq2();
    void changeTextFreq3();
    void changeTextFreq4();
    void changeTextFreq5();

    void changeTextChild();
    void changeTextChild1();
    void changeTextChild2();
    void changeTextChild3();
    void changeTextChild4();

    void handleBackButton();




private slots:

    void on_down_clicked();
    void on_up_clicked();
    void on_ok_clicked();
    void on_incPower_clicked();
    void on_decPower_clicked();
    void on_on_clicked();
    void on_off_clicked();
    void on_elecOn_clicked();
    void on_elecOff_clicked();
    void on_chargeDev_clicked();


    void on_restore_clicked();

private:

    Ui::MainWindow *ui;
    QTimer *timer;
    ProgramsWindow *prog;
    FrequencyWindow *freq;
    ChildrenWindow  *child;
};

#endif // MAINWINDOW_H
