allRightWidget::allRightWidget(QWidget *child) : QWidget(child) {
	topRight = new QGridLayout();

	QPushButton *test = new QPushButton(tr(":left:"));
	QPushButton *test_ = new QPushButton(tr(":left:"));
	QPushButton *test2 = new QPushButton(tr(":left:"));

	topRight->addWidget(test, 0,0);	
	topRight->addWidget(test_, 0,1);
	topRight->addWidget(test2, 0,2);

}
