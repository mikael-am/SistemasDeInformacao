#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ITENS INICIALMENTE INVISIVEIS
    ui->label_Operacao2->setVisible(false);
    ui->label_Operacao3->setVisible(false);
    //ITENS INICIALMENTE INVISIVEIS

    //FUNÇÕES
    on_actionExibir_Ocultar_Calculos_Anteriores_changed();
    //FUNÇÕES
}

MainWindow::~MainWindow()
{
    delete ui;
}

//FUNCAO QUE INSERE UM VALOR NO VISOR
void MainWindow::inserirValor(QString valor){
    if(Limpar){
        ui->lineEdit_Visor->clear();
        Limpar = false;
        trocaSinal(NULL);
    }
    ui->lineEdit_Visor->insert(valor);
}

//NUMEROS
void MainWindow::on_pushButton_0_clicked(){
    inserirValor("0");
}

void MainWindow::on_pushButton_1_clicked(){
    inserirValor("1");
}

void MainWindow::on_pushButton_2_clicked(){
    inserirValor("2");
}

void MainWindow::on_pushButton_3_clicked(){
    inserirValor("3");
}

void MainWindow::on_pushButton_4_clicked(){
    inserirValor("4");
}

void MainWindow::on_pushButton_5_clicked(){
    inserirValor("5");
}

void MainWindow::on_pushButton_6_clicked(){
    inserirValor("6");
}

void MainWindow::on_pushButton_7_clicked(){
    inserirValor("7");
}

void MainWindow::on_pushButton_8_clicked(){
    inserirValor("8");
}

void MainWindow::on_pushButton_9_clicked(){
    inserirValor("9");
}

//VIRGULA
void MainWindow::on_pushButton_Virgula_clicked(){
    //ui->lineEdit_Visor->setText(QString("%1").arg(ui->lineEdit_Visor->text().toInt() + 4));
    QString Valor = ui->lineEdit_Visor->text();
    if(Valor.length() > 0){
        if(!Valor.contains(",")){
            inserirValor(",");
        }
    }else{
        inserirValor("0");
        inserirValor(",");
    }
}

//SINAL
void MainWindow::trocaSinal(QChar sinal){
    Sinal = sinal;
    ui->label_Operacao3->setText(Sinal);
    if(!Sinal.isNull()){
        if(ui->lineEdit_Visor->text().length() > 0){
            ui->label_Operacao2->setText(ui->lineEdit_Visor->text());
            if(!ui->label_Operacao2->isVisible()){
                ui->label_Operacao2->setVisible(true);
                ui->label_Operacao3->setVisible(true);
            }
        }
    }else{
        ui->label_Operacao2->setVisible(false);
        ui->label_Operacao3->setVisible(false);
        ui->label_Operacao2->clear();
    }
    ui->lineEdit_Visor->clear();
    Limpar = false;
}

void MainWindow::on_pushButton_Subtracao_clicked(){
    trocaSinal('-');
}

void MainWindow::on_pushButton_Adicao_clicked(){
    trocaSinal('+');
}

void MainWindow::on_pushButton_Multiplicacao_clicked(){
    trocaSinal('*');
}

void MainWindow::on_pushButton_Divisao_clicked(){
    trocaSinal('/');
}

void MainWindow::on_pushButton_Del_clicked(){
    ui->lineEdit_Visor->backspace();
}

void MainWindow::on_pushButton_Clear_clicked(){
    trocaSinal(NULL);
}

void MainWindow::on_pushButton_Igual_clicked(){
    double Valor1 = ui->label_Operacao2->text().replace(QString(","), QString(".")).toDouble();
    double Valor2 = ui->lineEdit_Visor->text().replace(QString(","), QString(".")).toDouble();
    double Resultado = ui->lineEdit_Visor->text().replace(QString(","), QString(".")).toDouble();
    if(Sinal == '+'){
        Resultado = Valor1 + Valor2;
    }else if(Sinal == '-'){
        Resultado = Valor1 - Valor2;
    }else if(Sinal == '*'){
        Resultado = Valor1 * Valor2;
    }else if(Sinal == '/'){
        Resultado = Valor1 / Valor2;
    }

    //Atualizando histórico de cálculos
    ui->textBrowser_CalculosAnteriores->append(
        QString("%1").arg(Valor1).replace(QString("."), QString(",")) + " " + Sinal + " " +
        QString("%1").arg(Valor2).replace(QString("."), QString(",")) + " = " +
        QString("%1").arg(Resultado).replace(QString("."), QString(","))
    );
    //Atualizando histórico de cálculos

    trocaSinal(NULL);
    ui->lineEdit_Visor->setText(QString("%1").arg(Resultado).replace(QString("."), QString(",")));
    Limpar = true;

}

void MainWindow::on_actionSair_triggered(){
    exit(0);
}

void MainWindow::on_actionExibir_Ocultar_Calculos_Anteriores_changed(){
    if(ui->actionExibir_Ocultar_Calculos_Anteriores->isChecked()){
        if(this->geometry().x() > 0 || this->geometry().y() > 0){
            this->setGeometry(this->geometry().x(), this->geometry().y(), 425, 258);
        }else{
            this->setGeometry(200, 150, 425, 258);
        }
    }else{
        if(this->geometry().x() > 0 || this->geometry().y() > 0){
            this->setGeometry(this->geometry().x(), this->geometry().y(), 203, 258);
        }else{
            this->setGeometry(200, 150, 203, 258);
        }
    }
}
