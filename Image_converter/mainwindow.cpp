#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Brows Button

    QString filename = QFileDialog::getOpenFileName(this,"Open Image","","Images(*.png *.jpg *.bmp *.jpeg)");

    ui->lineEdit->setText(filename);
}
