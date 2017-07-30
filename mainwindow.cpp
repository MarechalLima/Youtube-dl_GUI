#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QMessageBox>

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

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    std::string comando;

    if(ui->mp3->isChecked() == true){
        comando = "youtube-dl -x --audio-format mp3 -o '~/Music/%(title)s.%(ext)s' " + ui->lineEdit->text().toStdString();
        QMessageBox::information(this, tr("Downloading"), tr("Wait a minute, your download is in progress"));
        system(comando.c_str());
        QMessageBox::information(this, tr("Completed"), tr("Your download is done!"));
        exit(0);
    }else if(ui->ogg->isChecked() == true){
        comando = "youtube-dl -x --audio-format vorbis -o '~/Music/%(title)s.%(ext)s' " + ui->lineEdit->text().toStdString();
        QMessageBox::information(this, tr("Downloading"), tr("Wait a minute, your download is in progress"));
        system(comando.c_str());
        QMessageBox::information(this, tr("Completed"), tr("Your download is done!"));
        exit(0);
    }else if(ui->mp4->isChecked() == true){
        comando = "youtube-dl --recode-video mp4 -o '~/Music/%(title)s.%(ext)s' " + ui->lineEdit->text().toStdString();
        QMessageBox::information(this, tr("Downloading"), tr("Wait a minute, your download is in progress"));
        system(comando.c_str());
        QMessageBox::information(this, tr("Completed"), tr("Your download is done!"));
        exit(0);
    }
}
