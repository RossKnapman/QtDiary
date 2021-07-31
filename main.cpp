#include "qtdiary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDiary w;
    w.show();
    return a.exec();
}
