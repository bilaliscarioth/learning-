#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
	QT dependencies
*/
#include "QtWidgets"
#include "QHBoxLayout"
#include "QtGui"
#include "QMenu"
#include "QMenuBar"
#include "QApplication"
#include <QtWidgets>
#include "QMainWindow"
#include "QWidget"
/*
	UI 
*/


class QPushButton;
class QTextBrowser;

namespace UI {
	class MainWindow;
	class topBar;
	class allRightWidget;
	class allLeftWidget;
}

class allRightWidget : public QWidget {
	Q_OBJECT
	public:
		allRightWidget(QWidget *child);
		QGridLayout *topRight;
		QGridLayout *middleTopRight;
		QGridLayout *bottomRight;
		QGridLayout *bottomTopRight;
};

class allLeftWidget : public QWidget {
	Q_OBJECT
	public: 
		allLeftWidget(QWidget *child);
	private:
		QWidget *tableur;
		QWidget *graph;
};

class topBar : public QHBoxLayout {
	Q_OBJECT
	public:
		topBar(QWidget *child);
	private:
		QMenu *files;
		QMenu *traitments;
		QMenu *edit;
		QMenu *tools;
		QMenu *execute;
		QMenu *windows;
		QMenu *help;
};

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		void eventButtonPush();
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();
	private:
		QToolBar *toolBar;
		QPushButton *createProject_;
		QPushButton *openProject_;
		topBar *tBar;
		allRightWidget *rBar;
		allLeftWidget *lBar;
};

#endif
