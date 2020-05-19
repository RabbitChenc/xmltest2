#include "mainwindow.h"
#include <QApplication>
#include "./Proj/hfview_facade_attrs.h"
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    HFviewFacadeAttrs v;
    v.fileNAme = argv[1];
    qDebug() << v.fileNAme <<endl;
    v.readXml();
    w.show();

    return a.exec();
}
