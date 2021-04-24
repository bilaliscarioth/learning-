#include "latisfree.h"
#include "ui/topbar.cpp"
#include "ui/allRight.cpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	//Création du projet
 	//createProject_ = new QPushButton("Créer un projet", this);
	tBar = new topBar(this);	
	rBar = new allRightWidget(this);
	toolBar	= addToolBar(tr("Outils"));
	addToolBar(Qt::TopToolBarArea, toolBar);


	setCentralWidget(new QWidget);
	centralWidget()->setLayout(rBar->topRight);
}



//Destruction des variables :)
MainWindow::~MainWindow(){
	delete createProject_;
	delete openProject_;
}
