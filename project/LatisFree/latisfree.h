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
}

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
};

#endif
