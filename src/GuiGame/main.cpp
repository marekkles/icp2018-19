#include <QApplication>
#include <QPushButton>

#include "GameTab.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 GameTab singleTab;

 singleTab.show();

 return app.exec();
}
