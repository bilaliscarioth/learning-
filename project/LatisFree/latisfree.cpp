#include "latisfree.h"
#include "ui/topbar.cpp"

void MainWindow::eventButtonPush(){

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	//Création du projet
 	//createProject_ = new QPushButton("Créer un projet", this);
	tBar = new topBar(this);	
	toolBar	= addToolBar(tr("Outils"));
	addToolBar(Qt::TopToolBarArea, toolBar);
}



//Destruction des variables :)
MainWindow::~MainWindow(){
	delete createProject_;
	delete openProject_;
}
