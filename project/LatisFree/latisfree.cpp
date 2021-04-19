#include <QtWidgets>
#include "latisfree.h"
#include "QMenu"
#include "QMenuBar"
#include "QApplication"

void MainWindow::eventButtonPush(){

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	//Création du projet
	createProject_ = new QPushButton("Créer un projet", this);
	openProject_ = new QPushButton("Ouvrir un projet", this);
	setWindowTitle(tr("LatisPro (GNU GPLv2)"));

	toolBar	= addToolBar(tr("Outils"));
	addToolBar(Qt::TopToolBarArea, toolBar);
	QMenu *file = menuBar()->addMenu("&File");
	QMenu *display = menuBar()->addMenu("&Affichage");
	QMenu *calc = menuBar()->addMenu("&Tableur");
	
	
	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(file);	
	layout->addWidget(display);
	layout->addWidget(calc);
}



//Destruction des variables :)
MainWindow::~MainWindow(){
	delete createProject_;
	delete openProject_;
}
