#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{


    ui->setupUi(this);


    prog = nullptr;
    freq = nullptr;
    child = nullptr;


    // hiding/disableing components of window
    ui->listWidget->hide();
    ui->powerLevel->hide();
    ui->treatment->hide();
    ui->off->setEnabled(false);
    ui->ok->setEnabled(false);
    ui->up->setEnabled(false);
    ui->down->setEnabled(false);
    ui->elecOn->setEnabled(false);
    ui->elecOff->setEnabled(false);
    ui->incPower->setEnabled(false);
    ui->decPower->setEnabled(false);
    ui->restore->setEnabled(false);


    //adding options to listwidget
    ui ->listWidget->addItem("PROGRAMS");
    ui ->listWidget->addItem("FREQUENCY");
    ui ->listWidget->addItem("CHILDREN");
    ui ->listWidget->addItem("MED");
    ui->listWidget->setCurrentRow(0);


    //timerObject used in conect fn below, it calls my timeFn() periodically, i set it latter in the program
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerFn()));
}



MainWindow::~MainWindow()
{
    //destructor
    delete ui;
}



void MainWindow::on_down_clicked()
{
    // down button clicked, check listwidget for current row, scroll to the item, then update the current row

    if(ui->listWidget->currentRow() == 0){
        QListWidgetItem *current = ui->listWidget->item(1);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(1);

    }

    else if(ui->listWidget->currentRow() == 1){
        QListWidgetItem *current = ui->listWidget->item(2);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(2);
    }


    else if(ui->listWidget->currentRow() == 2){
        QListWidgetItem *current = ui->listWidget->item(3);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(3);
    }



}


void MainWindow::on_up_clicked()
{
    if(ui->listWidget->currentRow() == 3){
        QListWidgetItem *current = ui->listWidget->item(2);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(2);

    }
    else if(ui->listWidget->currentRow() == 2){
        QListWidgetItem *current = ui->listWidget->item(1);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(1);

    }

    else if(ui->listWidget->currentRow() == 1){
        QListWidgetItem *current = ui->listWidget->item(0);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(0);
    }



}










void MainWindow::on_ok_clicked()
{
// when you select ok, main window hidden, and depending on what you selected, a window is created.

    hide();
    ui->incPower->setDisabled(false);
    ui->decPower->setDisabled(false);

    if(ui->listWidget->currentRow()==0){


        prog = new ProgramsWindow();

        QObject::connect(prog, SIGNAL(buttonPressed()), this, SLOT(changeTextProg()));   // the conect function conects signals to slots, its used here to communicate info between mainWindow and the others
        QObject::connect(prog, SIGNAL(buttonPressed1()), this, SLOT(changeTextProg1()));
        QObject::connect(prog, SIGNAL(buttonPressed2()), this, SLOT(changeTextProg2()));
        QObject::connect(prog, SIGNAL(buttonPressed3()), this, SLOT(changeTextProg3()));
        QObject::connect(prog, SIGNAL(buttonPressed4()), this, SLOT(changeTextProg4()));
        QObject::connect(prog, SIGNAL(buttonPressed5()), this, SLOT(changeTextProg5()));
        QObject::connect(prog, SIGNAL(backPressed()), this, SLOT(show()));
        QObject::connect(prog, SIGNAL(backPressed()), this, SLOT(handleBackButton()));   // backPressed handles the case where a user selects Ok in main, and doesnt pick another option, used in all other windows
        prog->show();

    }
    else if(ui->listWidget->currentRow()==1){


        freq = new FrequencyWindow();

        QObject::connect(freq, SIGNAL(buttonPressed()), this, SLOT(changeTextFreq()));
        QObject::connect(freq, SIGNAL(buttonPressed1()), this, SLOT(changeTextFreq1()));
        QObject::connect(freq, SIGNAL(buttonPressed2()), this, SLOT(changeTextFreq2()));
        QObject::connect(freq, SIGNAL(buttonPressed3()), this, SLOT(changeTextFreq3()));
        QObject::connect(freq, SIGNAL(buttonPressed4()), this, SLOT(changeTextFreq4()));
        QObject::connect(freq, SIGNAL(buttonPressed5()), this, SLOT(changeTextFreq5()));
        QObject::connect(freq, SIGNAL(backPressed()), this, SLOT(show()));
        QObject::connect(freq, SIGNAL(backPressed()), this, SLOT(handleBackButton()));
        freq->show();





    }
    else if(ui->listWidget->currentRow()==2){


        child = new ChildrenWindow();
        QObject::connect(child, SIGNAL(buttonPressed()), this, SLOT(changeTextChild()));
        QObject::connect(child, SIGNAL(buttonPressed1()), this, SLOT(changeTextChild1()));
        QObject::connect(child, SIGNAL(buttonPressed2()), this, SLOT(changeTextChild2()));
        QObject::connect(child, SIGNAL(buttonPressed3()), this, SLOT(changeTextChild3()));
        QObject::connect(child, SIGNAL(buttonPressed4()), this, SLOT(changeTextChild4()));
        QObject::connect(child, SIGNAL(backPressed()), this, SLOT(show()));
        QObject::connect(child, SIGNAL(backPressed()), this, SLOT(handleBackButton()));

        child->show();

    }

    else if(ui->listWidget->currentRow()==3){
        QMessageBox::information(this,"MED","MED OPTION SELECTED");
        ui->treatment->setText("MED");
        ui->powerLevel->setText(QString::number(1));
        ui->incPower->setDisabled(true);
        ui->decPower->setDisabled(true);
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
        show();

    }

}





// these functions are used as slots in the conect fns above
void MainWindow::changeTextProg()
{
    ui->treatment->setText("PROGRAM: ALLERGY");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}



void MainWindow::changeTextProg1()
{
    ui->treatment->setText("PROGRAM: PAIN");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}


void MainWindow::changeTextProg2()
{
    ui->treatment->setText("PROGRAM: INT. PAIN");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}


void MainWindow::changeTextProg3()
{
    ui->treatment->setText("PROGRAM: BLOATING");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}


void MainWindow::changeTextProg4()
{
    ui->treatment->setText("PROGRAM: DYSTONIA");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}


void MainWindow::changeTextProg5()
{
    ui->treatment->setText("PROGRAM: GENERAL");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete prog;
    show();
}






void MainWindow::changeTextFreq()
{
    ui->treatment->setText("FREQUENCY: 1, 0-9.9 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}



void MainWindow::changeTextFreq1()
{
    ui->treatment->setText("FREQUENCY: 10 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}


void MainWindow::changeTextFreq2()
{
    ui->treatment->setText("FREQUENCY: 20 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}


void MainWindow::changeTextFreq3()
{
    ui->treatment->setText("FREQUENCY: 60 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}


void MainWindow::changeTextFreq4()
{
    ui->treatment->setText("FREQUENCY: 77 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}


void MainWindow::changeTextFreq5()
{
    ui->treatment->setText("FREQUENCY: 125 Hz");
    if(ui->powerLevel->text() != "0"){
        ui->elecOn->setDisabled(false);
        ui->elecOff->setDisabled(false);
    }
    delete freq;
    show();
}







// this fn handles the disable button in child, if no child setting was selected prior to pressing it, it does nothing, just
void MainWindow::changeTextChild()
{
     QString txt = ui->treatment->text();


     if(ui->treatment->text() == "MED"){
         ui->incPower->setDisabled(true);
         ui->decPower->setDisabled(true);

     }

     else if(txt == "CHILD: UP TO 1 YEAR" || txt == "CHILD: 1-3 YEARS" || txt == "CHILD: 4-7 YEARS" || txt == "CHILD: 7-12 YEARS"){


         ui->treatment->setText("TREATMENT: NONE");
         ui->powerLevel->setText("0");


         ui->elecOn->setDisabled(true);
         ui->elecOn->setAutoExclusive(false);
         ui->elecOn->setChecked(false);
         ui->elecOn->setAutoExclusive(true);


         ui->elecOff->setDisabled(true);
         ui->elecOff->setAutoExclusive(false);
         ui->elecOff->setChecked(false);
         ui->elecOff->setAutoExclusive(true);
     }
     delete child;
     show();




}



void MainWindow::changeTextChild1()
{
    ui->treatment->setText("CHILD: UP TO 1 YEAR");
    ui->powerLevel->setText("0");
    ui->elecOn->setDisabled(true);
    ui->elecOn->setAutoExclusive(false);
    ui->elecOn->setChecked(false);
    ui->elecOn->setAutoExclusive(true);


    ui->elecOff->setDisabled(true);
    ui->elecOff->setAutoExclusive(false);
    ui->elecOff->setChecked(false);
    ui->elecOff->setAutoExclusive(true);
    delete child;
    show();
}


void MainWindow::changeTextChild2()
{
    ui->treatment->setText("CHILD: 1-3 YEARS");
    ui->powerLevel->setText("0");
    ui->elecOn->setDisabled(true);
    ui->elecOn->setAutoExclusive(false);
    ui->elecOn->setChecked(false);
    ui->elecOn->setAutoExclusive(true);


    ui->elecOff->setDisabled(true);
    ui->elecOff->setAutoExclusive(false);
    ui->elecOff->setChecked(false);
    ui->elecOff->setAutoExclusive(true);
    delete child;
    show();
}


void MainWindow::changeTextChild3()
{
    ui->treatment->setText("CHILD: 4-7 YEARS");
    ui->powerLevel->setText("0");
    ui->elecOn->setDisabled(true);
    ui->elecOn->setAutoExclusive(false);
    ui->elecOn->setChecked(false);
    ui->elecOn->setAutoExclusive(true);


    ui->elecOff->setDisabled(true);
    ui->elecOff->setAutoExclusive(false);
    ui->elecOff->setChecked(false);
    ui->elecOff->setAutoExclusive(true);
    delete child;
    show();
}


void MainWindow::changeTextChild4()
{
    ui->treatment->setText("CHILD: 7-12 YEARS");
    ui->powerLevel->setText("0");
    ui->elecOn->setDisabled(true);
    ui->elecOn->setAutoExclusive(false);
    ui->elecOn->setChecked(false);
    ui->elecOn->setAutoExclusive(true);


    ui->elecOff->setDisabled(true);
    ui->elecOff->setAutoExclusive(false);
    ui->elecOff->setChecked(false);
    ui->elecOff->setAutoExclusive(true);
    delete child;
    show();
}




void MainWindow::handleBackButton(){
    ui->treatment->setText("TREATMENT: NONE");
    ui->powerLevel->setText("0");

    ui->elecOn->setDisabled(true);
    ui->elecOff->setDisabled(true);

}




void MainWindow::on_incPower_clicked()
{
    QString powerLevel = ui->powerLevel->text();
    int powerNum = powerLevel.toInt();

    int maxPow;

    if (ui->treatment->text() == "CHILD: UP TO 1 YEAR")
        maxPow = 2;
    else if(ui->treatment->text() == "CHILD: 1-3 YEARS")
        maxPow = 4;
    else if(ui->treatment->text() == "CHILD: 4-7 YEARS")
        maxPow = 8;
    else if(ui->treatment->text() == "CHILD: 7-12 YEARS")
        maxPow = 10;
    else {
       maxPow = 12;
    }


    if(powerNum < maxPow)
        powerNum+=1;
    powerLevel = QString::number(powerNum);
    ui->powerLevel->setText(powerLevel);



    if(ui->treatment->text() != "TREATMENT: NONE"){
        ui->elecOn->setEnabled(true);
        ui->elecOff->setEnabled(true);
     }






}

void MainWindow::on_decPower_clicked()
{
    QString powerLevel = ui->powerLevel->text();
    int powerNum = powerLevel.toInt();



    if(powerNum > 0)
        powerNum-=1;
    powerLevel = QString::number(powerNum);
    ui->powerLevel->setText(powerLevel);


    if(powerNum == 0){
        ui->elecOn->setDisabled(true);
        ui->elecOn->setAutoExclusive(false);
        ui->elecOn->setChecked(false);
        ui->elecOn->setAutoExclusive(true);


        ui->elecOff->setDisabled(true);
        ui->elecOff->setAutoExclusive(false);
        ui->elecOff->setChecked(false);
        ui->elecOff->setAutoExclusive(true);



    }
}



void MainWindow::on_on_clicked()
{
    ui->off->setEnabled(true);
    ui->on->setEnabled(false);
    ui->down->setEnabled(false);
    ui->powerLevel->setText("0");
    ui->up->setEnabled(true);
    ui->down->setEnabled(true);
    ui->ok->setEnabled(true);
    ui->incPower->setEnabled(true);
    ui->decPower->setEnabled(true);
    ui->restore->setEnabled(true);
    ui->powerLevel->show();
    ui->clock->show();
    ui->treatment->show();

    ui->treatment->setText("TREATMENT: NONE");






}

void MainWindow::on_off_clicked()
{

    QFile file("/home/student/Documents/QtStuff/settings.txt");



    if(!file.open(QFile::WriteOnly  | QFile::Text)){
       QMessageBox::warning(this,"fileNotFound","cant write to file");
    }

    QString text = ui->treatment->text();
    QString text2 = ui->powerLevel->text();

    QTextStream out(&file);
    out << text << endl;
    out << text2;
    file.flush();
    file.close();



    ui->on->setEnabled(true);
    ui->off->setEnabled(false);
    ui->powerLevel->hide();
    ui->treatment->hide();
    ui->up->setEnabled(false);
    ui->down->setEnabled(false);
    ui->ok->setEnabled(false);
    ui->incPower->setEnabled(false);
    ui->decPower->setEnabled(false);
    ui->restore->setEnabled(false);

    ui->listWidget->setCurrentRow(0);

    timer->stop();

    ui->elecOn->setDisabled(true);
    ui->elecOn->setAutoExclusive(false);
    ui->elecOn->setChecked(false);
    ui->elecOn->setAutoExclusive(true);


    ui->elecOff->setDisabled(true);
    ui->elecOff->setAutoExclusive(false);
    ui->elecOff->setChecked(false);
    ui->elecOff->setAutoExclusive(true);
}







void MainWindow::timerFn()
{
    QString currTime = ui->clock->text();
    int currTimeInt = currTime.toInt();

    QString powerLevel = ui->powerLevel->text();
    int powerNum = powerLevel.toInt();


    if(currTimeInt <= powerNum){
        timer->stop();

        QFile file("/home/student/Documents/QtStuff/settings.txt");

        if(!file.open(QFile::WriteOnly  | QFile::Text)){
           QMessageBox::warning(this,"fileNotFound","cant write to file");
        }

        QString text = ui->treatment->text();
        QString text2 = ui->powerLevel->text();

        QTextStream out(&file);
        out << text << endl;
        out << text2;
        file.flush();
        file.close();




        ui->clock->setText(QString::number(0));

        
        ui->elecOn->setAutoExclusive(false);
        ui->elecOn->setChecked(false);
        ui->elecOn->setAutoExclusive(true);
        ui->elecOn->setEnabled(false);
        ui->down->setEnabled(false);
        ui->ok->setEnabled(false);
        ui->up->setEnabled(false);
        ui->off->setEnabled(false);
        ui->decPower->setEnabled(false);
        ui->incPower->setEnabled(false);
        ui->elecOff->setEnabled(false);
        ui->restore->setDisabled(true);

        
        ui->listWidget->hide();
        ui->powerLevel->hide();
        ui->treatment->hide();

        QMessageBox::warning(this, "BatteryLevel", "BatteryLevel == 0 !!!!!");





    }
    else if (ui->elecOn->isChecked()){
        currTimeInt = currTimeInt - powerNum;
        ui->clock->setText(QString::number(currTimeInt));
        }




}








void MainWindow::on_elecOn_clicked()
{
   timer->start(1000);
   ui->ok->setDisabled(true);
}

void MainWindow::on_elecOff_clicked()
{
   timer->stop();
   ui->ok->setDisabled(false);
}



void MainWindow::on_chargeDev_clicked()
{
    if(!ui->off->isEnabled()){
       ui->on->setEnabled(true);


    }

    ui->clock->setText(QString::number(100));


}


void MainWindow::on_restore_clicked()
{
    QFile file("/home/student/Documents/QtStuff/settings.txt");

    if(!file.open(QFile::ReadOnly  | QFile::Text)){
       QMessageBox::warning(this,"fileNotFound","cant write to file");
    }



    QTextStream in(&file);
    QString text = in.readLine();
    QString text2 = in.readLine();
    file.flush();
    file.close();

    ui->treatment->setText(text);
    ui->powerLevel->setText(text2);
    ui->restore->setEnabled(false);



    if(ui->powerLevel->text() != "0" && ui->treatment->text() != "TREATMENT: NONE"){
      ui->elecOn->setEnabled(true);
      ui->elecOff->setEnabled(true);
    }

    if(ui->treatment->text() == "MED"){
        ui->incPower->setEnabled(false);
        ui->decPower->setEnabled(false);
    }





}
