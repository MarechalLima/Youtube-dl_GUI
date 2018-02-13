#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <boost/algorithm/string.hpp>
#include <iostream>

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
	std::string comando;
	std::vector<std::string> list;
	std::string tmp = ui->lineEdit->text ().toStdString ();

	if (ui->mp3->isChecked() == true){
		comando = "youtube-dl -x --audio-format mp3 -o '~/Music/%(title)s.%(ext)s' ";
	}else if (ui->ogg->isChecked() == true){
		comando = "youtube-dl -x --audio-format vorbis -o '~/Music/%(title)s.%(ext)s' ";
	}else if (ui->mp4->isChecked() == true){
		comando = "youtube-dl --recode-video mp4 -o '~/Music/%(title)s.%(ext)s' ";
	}
	boost::split (list, tmp, [](char c){return c == ' ';});
	for (std::string url : list){
		comando+= url;
		comando+= " ";
	}
	std::cout << comando << std::endl;
	ui->pushButton->setEnabled (false);
	ui->statusBar->showMessage (tr("Wait a minute, your download is in progress"));
	system(comando.c_str());
	ui->statusBar->showMessage (tr("Completed"));
	ui->pushButton->setEnabled (true);
}
