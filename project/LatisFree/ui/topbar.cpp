topBar::topBar(QWidget *child) : QHBoxLayout(child){
	QMenuBar *bar = new QMenuBar();
	files = new QMenu("Fichiers");
	traitments  = new QMenu("Traitements");
	edit  = new QMenu("Édition");
	tools = new QMenu("Outils");
	execute = new QMenu("Exécuter");
	windows = new QMenu("Fenêtres");

	bar->addMenu(files);	
	bar->addMenu(traitments);	
	bar->addMenu(edit);	
	bar->addMenu(tools);	
	bar->addMenu(execute);	
	bar->addMenu(windows);	

	child->layout()->setMenuBar(bar);
};
