#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>

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

    QString filename = QFileDialog::getOpenFileName(this,"Open Image","","Images(*.png *.jpg *.bmp  *.jpeg)");

    ui->lineEdit->setText(filename);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = ui->lineEdit->text();

    if(filename!="")
    {
        QFileInfo fileinfo = QFile(filename);
        QString newFilename = fileinfo.path() + "/" + fileinfo.completeBaseName();

        QImage image = QImage(ui->lineEdit->text());

        if(!image.isNull()){
            int format = ui->comboBox->currentIndex();

            if(format == 0){
                newFilename += ".png";
            }else if(format == 1){
                newFilename += ".jpg";
            }
            else if(format == 2){
                newFilename += ".bmp";
            }
            qDebug() <<newFilename <<format;
                    if(image.save(newFilename,0,-1)){
                QMessageBox::information(this,"Success","Image Converte Successfully");
            } else{
                QMessageBox::information(this,"Failed","Image not Converted");
            }
        }
        else{
            QMessageBox::information(this,"Failed","Failed to Open Image");
        }

    }else{
        QMessageBox::information(this,"Failed","Image not selected");
    }
}
