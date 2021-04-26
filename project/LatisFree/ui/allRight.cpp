allRightWidget::allRightWidget(QWidget *child) : QWidget(child) {
	// Parameter field
	// [Sync graph and tableur]
	// 
	topRight = new QGridLayout();
	QPushButton *test = new QPushButton(tr(":left:"));
	QPushButton *test_ = new QPushButton(tr(":left:"));
	QPushButton *test2 = new QPushButton(tr(":left:"));

	topRight->addWidget(test, 0,0);	
	topRight->addWidget(test_, 0,1);
	topRight->addWidget(test2, 0,2);

	// Input/Output of Hardware
	//
	middleTopRight = new QGridLayout();
	QPushButton *test3 = new QPushButton(tr("EA0"));
	QPushButton *test4 = new QPushButton(tr("EA1"));
	QPushButton *test5 = new QPushButton(tr("EA2"));

	middleTopRight->addWidget(test3, 0,0);	
	middleTopRight->addWidget(test4, 1,0);
	middleTopRight->addWidget(test5, 2,0);

	connect(middleTopRight, null, this, null);
}
