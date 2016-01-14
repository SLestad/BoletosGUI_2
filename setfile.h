/*
//QVector <double> consecutivos;
//QVector <int> vendidos;
//QVector <int> disponibles;
QVector <QString> NombEvento;

//struct FormatDoc {
     int evn;
     int vnd[26];
     int dis[26];
     double fol[26];
//};


     void VentaEvento(int evento){
          int venta;
          string nombre;

          datoscompra(nombre, venta);

          if(venta+vendidos[evento]<=disponibles[evento]){
               consecutivos[evento]+=venta;
               vendidos[evento]+=venta;

               string NEvento=NombEvento[evento];
               double conse=consecutivos[evento];
               scrcomprobante(NEvento,nombre, venta, conse);
               PrintBoleto(NEvento, nombre, venta, conse);

          }
          else{
               cout<<"\n\nLo sentimos, no hay suficientes localidades para esta venta\n\n"<<endl;
               system("pause");
          }
     }

     void SaveFile(){
          FormatDoc TSR;
          TSR.evn=disponibles.size();

          for(int i=0;i<26;i++){
               TSR.vnd[i]=0;
               TSR.dis[i]=0;
               TSR.fol[i]=0;
          }

          system("attrib -h StrFile.txt /L"); system("cls");
          ofstream OUTTXTFILE("StrFile.txt");
          for(int k=0;k<disponibles.size();k++){
               OUTTXTFILE<<endl<<NombEvento[k];
               TSR.vnd[k]=vendidos[k];
               TSR.dis[k]=disponibles[k];
               TSR.fol[k]=consecutivos[k];
          }
          OUTTXTFILE.close();
          system("attrib +h StrFile.txt /L");

          system("attrib -h BinFile.dat /L"); system("cls");
          ofstream OUTFILE("BinFile.dat", ios::out | ios::binary);
          OUTFILE.write(reinterpret_cast<char *>(&TSR), sizeof(FormatDoc));
          OUTFILE.close();
          system("attrib +h BinFile.dat /L");
     }

     void GetFile(){
          int ACS = access("StrFile.txt",0);
          int ACB = access("BinFile.dat",0);
          if(ACS==0){ if(ACB==0){
               FormatDoc RST;
               ifstream INFILE("BinFile.dat", ios::in | ios::binary);
               INFILE.read(reinterpret_cast<char *>(&RST), sizeof(FormatDoc));
               INFILE.close();

               int i=-1;
               char txtline[80];

               ifstream INTXTFILE;
               INTXTFILE.open("StrFile.txt");
               INTXTFILE.getline(txtline,80,'\n');
               for(int i=0;i<RST.evn;i++){
                    INTXTFILE.getline(txtline,80,'\n');
                    string str(txtline);
                    NombEvento.push_back(str);
                    disponibles.push_back(RST.dis[i]);
                    vendidos.push_back(RST.vnd[i]);
                    consecutivos.push_back(RST.fol[i]);
               }
               INTXTFILE.close();
          }else; }else;
     }
};
*/
