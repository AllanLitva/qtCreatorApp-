#include "childrenwindow.h"
#include "ui_childrenwindow.h"

ChildrenWindow::ChildrenWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChildrenWindow)
{
    ui->setupUi(this);
    ui ->listWidget->addItem("DISABLE");
    ui ->listWidget->addItem("UP TO 1 YEAR");
    ui ->listWidget->addItem("1-3 YEARS");
    ui ->listWidget->addItem("4-7 YEARS");
    ui ->listWidget->addItem("7-12 YEARS");


    ui->listWidget->setCurrentRow(0);
}

ChildrenWindow::~ChildrenWindow()
{
    delete ui;
}

void ChildrenWindow::on_up_clicked()
{


    if(ui->listWidget->currentRow() == 4){
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

void ChildrenWindow::on_down_clicked()
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

}




void ChildrenWindow::on_ok_clicked(){

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


void ChildrenWindow::on_back_pressed()
{
    emit backPressed();
    close();

}

