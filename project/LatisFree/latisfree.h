#include "QtWidgets/QWidget"

namespace Ui {
	class LatisFree;
}

class LatisFree : public QWidget{
	Q_OBJECT
	public:
		explicit LatisFree(QWidget *parent= 0);
		~LatisFree();
	private slots:
		void newDocument();
};
