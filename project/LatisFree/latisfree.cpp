#include "latisfree.h"
#include "QtWidgets/QApplication"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	LatisFree lfree;
	lfree.show();

	return a.exec();
}
