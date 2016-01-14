#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listEven_doubleClicked(const QModelIndex &index);

    void on_Eliminar_clicked();

    void on_Cancelar_clicked();

    void on_Cobrar_clicked();

    void on_listTicket_clicked(const QModelIndex &index);

    void on_AnadEv_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
