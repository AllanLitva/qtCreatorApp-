#include "frequencywindow.h"
#include "ui_frequencywindow.h"
#include <QMessageBox>


FrequencyWindow::FrequencyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrequencyWindow)
{
    ui->setupUi(this);
    ui ->listWidget->addItem("1.0-9.9 HZ");
    ui ->listWidget->addItem("10 HZ");
    ui ->listWidget->addItem("20 HZ");
    ui ->listWidget->addItem("60 HZ");
    ui ->listWidget->addItem("77 HZ");
    ui ->listWidget->addItem("125 HZ");

    ui->listWidget->setCurrentRow(0);
}

FrequencyWindow::~FrequencyWindow()
{
    delete ui;
}

void FrequencyWindow::on_up_clicked()
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

void FrequencyWindow::on_down_clicked()
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





void FrequencyWindow::on_ok_clicked(){

    QMessageBox::information(this,"FREQUENCY","Apply electrodes to any treatment zone.");

   
    if(ui->listWidget->currentRow()==0){
        emit buttonPressed();
    }
    else if (ui->listWidget->currentRow()==1) {
        emit buttonPressed1();
    }
    else if (ui->listWidget->currentRow()==2) {
        emit buttonPressed2();
    }

    else if (ui->listWidget->currentRow()==3) {
        emit buttonPressed3();
    }

    else if (ui->listWidget->currentRow()==4) {
        emit buttonPressed4();
    }

    else if (ui->listWidget->currentRow()==5) {
        emit buttonPressed5();
    }



}









void FrequencyWindow::on_back_pressed()
{
    emit backPressed();
    close();

}

























