#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rwfile.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Eliminar->setEnabled(false);
    ui->nmeLine->setEnabled(false);
    ui->cstLine->setEnabled(false);
    ui->folLine->setEnabled(false);
    ui->dspLine->setEnabled(false);
    ui->Resumen->setEnabled(false);

    if (QFile("BinFile.dat").exists()){
    if (QFile("TxtFile.txt").exists()){
        OpenFile();
        for(int j=0;j<=szeEvent;j++){
            ui->listEven->addItem(eventName[j]);
        }
    }else szeEvent=0;
    }else szeEvent=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listEven_doubleClicked(const QModelIndex &index)
{
    ui->listTicket->addItem(ui->listEven->currentItem()->text());
    ui->listCst->addItem(" $ " + QString::number(cstEvent[ui->listEven->currentRow()]));
    cstTicket.push_back(cstEvent[ui->listEven->currentRow()]);
    lstTicket.push_back(ui->listEven->currentRow());

    ui->lcdTotal->display(sumTotal());
}

void MainWindow::on_Eliminar_clicked()
{
    if(sumTotal()!=0){
        cstTicket.remove(ui->listTicket->currentRow());
        lstTicket.remove(ui->listTicket->currentRow());
        delete ui->listCst->item(ui->listTicket->currentRow());
        delete ui->listTicket->currentItem();

        ui->lcdTotal->display(sumTotal());
        if(sumTotal()==0) ui->Eliminar->setEnabled(false);

    }
    else{
        ui->Eliminar->setEnabled(false);
    }
}

int h=2;
void MainWindow::on_Cancelar_clicked()
{
    ui->listTicket->clear();
    ui->listCst->clear();
    cstTicket.clear();
    lstTicket.clear();
    ui->lcdTotal->display(sumTotal());
}

void MainWindow::on_Cobrar_clicked()
{
    SaveFile();
    if(sumTotal()!=0)ui->Resumen->setEnabled(true);
    else;
}

void MainWindow::on_listTicket_clicked(const QModelIndex &index)
{
    ui->Eliminar->setEnabled(true);
}

void MainWindow::on_AnadEv_clicked()
{
    int H=h%2;
    if(H==0){
        ui->Cobrar->setEnabled(false);
        ui->Eliminar->setEnabled(false);
        ui->listCst->setEnabled(false);
        ui->listEven->setEnabled(false);
        ui->listTicket->setEnabled(false);
        ui->nmeLine->setEnabled(true);
        ui->cstLine->setEnabled(true);
        ui->folLine->setEnabled(true);
        ui->dspLine->setEnabled(true);
        ui->AnadEv->setText("Aceptar");
        h++;
    }
    else{
        eventName.push_back(ui->nmeLine->text());
        cstEvent.push_back(ui->cstLine->text().toInt());
        dspEvent.push_back(ui->dspLine->text().toInt());
        folEvent.push_back(ui->folLine->text().toLong());

        SaveFile();
        ui->listEven->addItem(ui->nmeLine->text());
        ui->nmeLine->clear();
        ui->cstLine->clear();
        ui->dspLine->clear();
        ui->folLine->clear();

        ui->Cobrar->setEnabled(true);
        ui->Eliminar->setEnabled(true);
        ui->listCst->setEnabled(true);
        ui->listEven->setEnabled(true);
        ui->listTicket->setEnabled(true);
        ui->nmeLine->setEnabled(false);
        ui->cstLine->setEnabled(false);
        ui->folLine->setEnabled(false);
        ui->dspLine->setEnabled(false);
        ui->AnadEv->setText("Añadir Evento");

        h++;
    }
}
