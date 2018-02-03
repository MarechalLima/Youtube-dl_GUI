#include "dialog.hpp"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

Dialog::~Dialog()
{
	delete ui;
}



void Dialog::on_buttonBox_accepted()
{
	std::string command = "youtube-dl -x --audio-format mp3 -o '~/Music/%(title)s.%(ext)s' ";
	std::string list;
	list = ui->listText->toPlainText ().toStdString ();
	std::vector<char> tmp (list.begin (), list.end ());
	tmp.push_back ('\0');
	char *aux = strtok (&tmp[0], "\n");

	while (aux != NULL){
		command+= aux;
		command+= " ";
		aux = strtok (NULL, "\n");

	}
	QMessageBox::information(this, tr("Downloading"), tr("Wait a minute, your download is in progress"));
	system(command.c_str());
	QMessageBox::information(this, tr("Completed"), tr("Your download is done!"));
	exit(0);
}
