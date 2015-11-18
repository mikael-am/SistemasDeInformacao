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
    void inserirValor(QString valor);
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_Virgula_clicked();

    void on_pushButton_Subtracao_clicked();
    void on_pushButton_Adicao_clicked();
    void on_pushButton_Multiplicacao_clicked();
    void on_pushButton_Divisao_clicked();

    void trocaSinal(QChar sinal);

    void on_pushButton_Del_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Igual_clicked();

    void on_actionSair_triggered();

    void on_actionExibir_Ocultar_Calculos_Anteriores_changed();

private:
    Ui::MainWindow *ui;
    QChar Sinal;
    bool Limpar = false;
};

#endif // MAINWINDOW_H
