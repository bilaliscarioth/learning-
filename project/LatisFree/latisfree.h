#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"
#include "QWidget"
#include "QHBoxLayout"
#include "QtGui"

class QPushButton;
class QTextBrowser;

namespace UI {
	class MainWindow;
}

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		void eventButtonPush();
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();
	private:
		QToolBar  *toolBar;
		QPushButton *createProject_;
		QPushButton *openProject_;
};

#endif
