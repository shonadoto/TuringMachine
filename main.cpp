#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QImage(QString::fromUtf8(":/anime.jpg"));
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Turing machine simulator");
  w.show();
  return a.exec();
}
