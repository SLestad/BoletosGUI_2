#include <QString>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QMessageBox>

int szeEvent;
QVector <QString> eventName;
QVector <int> cstEvent;
QVector <int> vndEvent;
QVector <int> dspEvent;
QVector <long> folEvent;


struct FormatDoc{
    int cst[50];
    int vnd[50];
    int dsp[50];
    long fol[50];
    int sze;
};

QVector <int> cstTicket;
QVector <int> lstTicket;

int sumTotal(){
    int K=0;
    for(int i=0;i<cstTicket.size();i++){
        K = K + cstTicket[i];
    }
    return K;
}


void SaveFile(){
     FormatDoc TSR;
     for(int i=0;i<50;i++){
          TSR.cst[i]=10;
          TSR.vnd[i]=0;
          TSR.dsp[i]=0;
          TSR.fol[i]=0;
          TSR.sze=0;
     }

     TSR.sze=eventName.size();
     for(int i=0;i<TSR.sze;i++){
         TSR.cst[i]=cstEvent[i];
         /*TSR.vnd[i]=vndEvent[i];
         TSR.dsp[i]=dspEvent[i];
         TSR.fol[i]=folEvent[i];*/
     }
     QFile OUTBINFILE("BinFile.dat");
     if(OUTBINFILE.open(QIODevice::ReadWrite))
         OUTBINFILE.write(reinterpret_cast<char*>(&TSR), sizeof(TSR));
     OUTBINFILE.close();

     QFile OUTTXTFILE("TxtFile.txt");
     if(OUTTXTFILE.open(QIODevice::WriteOnly | QIODevice::Text)){
         QTextStream stream(&OUTTXTFILE);
         for(int i=0;i<TSR.sze;i++){
            stream << "\n" << eventName[i];
         }
         OUTTXTFILE.flush();
         OUTTXTFILE.close();
     }

}

void OpenFile(){
     FormatDoc RST;

     QFile INBINFILE("BinFile.dat");
     if(INBINFILE.open(QIODevice::ReadWrite))
         INBINFILE.read(reinterpret_cast<char*>(&RST), sizeof(RST));
     INBINFILE.close();
     szeEvent = RST.sze;
     for(int i=0;i<=RST.sze;i++){
         cstEvent.push_back(RST.cst[i]);
         vndEvent.push_back(RST.vnd[i]);
         dspEvent.push_back(RST.dsp[i]);
         folEvent.push_back(RST.fol[i]);
     }

     QFile INTXTFILE("TxtFile.txt");
     if(INTXTFILE.open(QIODevice::ReadOnly | QIODevice::Text)){
         QTextStream stream(&INTXTFILE);
         QString line;
         line = stream.readLine();
         do{
             line = stream.readLine();
             eventName.push_back(line);
         }while(!line.isNull());
         INTXTFILE.close();
     }
}
