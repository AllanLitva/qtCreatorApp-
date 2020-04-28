#include "programswindow.h"
#include "ui_programswindow.h"
#include <QMessageBox>

ProgramsWindow::ProgramsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgramsWindow)
{
    ui->setupUi(this);
    ui ->listWidget->addItem("ALLERGY");
    ui ->listWidget->addItem("PAIN");
    ui ->listWidget->addItem("INT. PAIN");
    ui ->listWidget->addItem("BLOATING");
    ui ->listWidget->addItem("DYSTONIA");
    ui ->listWidget->addItem("GENERAL");

    ui->listWidget->setCurrentRow(0);
}

ProgramsWindow::~ProgramsWindow()
{
    delete ui;
}

void ProgramsWindow::on_programUp_clicked()
{



    if(ui->listWidget->currentRow() == 5){
        QListWidgetItem *current = ui->listWidget->item(4);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(4);
    }
    else if(ui->listWidget->currentRow() == 4){
        QListWidgetItem *current = ui->listWidget->item(3);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(3);
    }


    else if(ui->listWidget->currentRow() == 3){
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

void ProgramsWindow::on_programDown_clicked()
{
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

    else if(ui->listWidget->currentRow() == 3){
        QListWidgetItem *current = ui->listWidget->item(4);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(4);
    }

    else if(ui->listWidget->currentRow() == 4){
        QListWidgetItem *current = ui->listWidget->item(5);
        ui->listWidget->scrollToItem(current);
        ui->listWidget->setCurrentRow(5);
    }


}

void ProgramsWindow::on_back_pressed()
{
    emit backPressed();
    close();

}



void ProgramsWindow::on_programOk_clicked(){

    if(ui->listWidget->currentRow()==0){

        QMessageBox::information(this,"ALERGY","Place electrodes on chest for alergy treatment.");
        emit buttonPressed();

    }
    else if (ui->listWidget->currentRow()==1) {

        QMessageBox::information(this,"PAIN","Place electrodes on neck for pain treatment.");
        emit buttonPressed1();
    }
    else if (ui->listWidget->currentRow()==2) {

        QMessageBox::information(this,"INT. PAIN","Place electrodes on temples for Int. Pain treatment.");
        emit buttonPressed2();
    }

    else if (ui->listWidget->currentRow()==3) {

        QMessageBox::information(this,"BLOATINGY","Place electrodes on stomach for bloating treatment.");
        emit buttonPressed3();
    }

    else if (ui->listWidget->currentRow()==4) {

        QMessageBox::information(this,"DYSTONIA","Place electrodes on legs for dystonia treatment.");
        emit buttonPressed4();
    }

    else if (ui->listWidget->currentRow()==5) {

        QMessageBox::information(this,"GENERAL","Place electrodes in any area for general treatment.");
        emit buttonPressed5();
    }



}
