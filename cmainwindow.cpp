#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include "cdirectories.h"
#include "cgameapplication.h"

#include <QDebug>


cMainWindow::cMainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::cMainWindow)
{
	cGameApplication::getInstance()->run();
	cGameApplication::cleanUp();

	ui->setupUi(this);
}

cMainWindow::~cMainWindow()
{
	cDirectories::cleanUp();

	delete ui;
}

