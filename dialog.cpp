#include "dialog.h"
#include "ui_dialog.h"
#include <QVector>
#include <QString>
#include <QMessageBox>

void crear();

QVector <int> dsp;
QVector <int> cst;
QVector <int> vnd;
QVector <long> fol;
QVector <QString> evnt;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->evtName->setEnabled(false);
    crear();
    for(int i=0;i<evnt.size();i++){
        ui->chsSlct->addItem(evnt[i]);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void crear(){
    for(int i=0; i<=4; i++){
        dsp.push_back((i+1)*10);
        cst.push_back((i+1)*100);
        vnd.push_back(i+1);
        fol.push_back((i+1)*1000);
        evnt.push_back("Evento " + QString::number(i+1));
    }
    evnt.push_back("Add Event");
}

void Dialog::on_chsSlct_activated(int index)
{
    if(ui->chsSlct->currentIndex()==evnt.size()-1){
        ui->evtName->setEnabled(true);
        ui->cstLine->setText(QString::number(0));
        ui->dspLine->setText(QString::number(0));
        ui->vndLine->setText(QString::number(0));
        ui->folLine->setText(QString::number(0));
    }
    else{
        int k = ui->chsSlct->currentIndex();
        ui->evtName->setEnabled(false);
        ui->cstLine->setText(QString::number(cst[k]));
        ui->dspLine->setText(QString::number(dsp[k]));
        ui->vndLine->setText(QString::number(vnd[k]));
        ui->folLine->setText(QString::number(fol[k]));
    }
}

void Dialog::on_aceptarBtn_clicked()
{
    if(ui->chsSlct->currentIndex()==evnt.size()-1){
        evnt[evnt.size()-1]=ui->evtName->text();
        cst.push_back(ui->cstLine->text().toInt());
        dsp.push_back(ui->dspLine->text().toInt());
        vnd.push_back(ui->vndLine->text().toInt());
        fol.push_back(ui->folLine->text().toLong());

        ui->chsSlct->clear();
        for(int i=0; i<evnt.size(); i++){
            ui->chsSlct->addItem(evnt[i]);
        }
        evnt.push_back("Add Event");
        ui->chsSlct->addItem(evnt[evnt.size()-1]);
    }
    else{
        int k = ui->chsSlct->currentIndex();
        cst[k]=ui->cstLine->text().toInt();
        dsp[k]=ui->dspLine->text().toInt();
        vnd[k]=ui->vndLine->text().toInt();
        fol[k]=ui->folLine->text().toLong();
    }
}
