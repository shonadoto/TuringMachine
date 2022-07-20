#ifndef DELETECHARWINDOW_H
#define DELETECHARWINDOW_H

#include <QDialog>

namespace Ui {
  class DeleteCharWindow;
}

class DeleteCharWindow : public QDialog
{
  Q_OBJECT

public:
  explicit DeleteCharWindow(QWidget *parent = nullptr);
  ~DeleteCharWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::DeleteCharWindow *ui;
};

#endif // DELETECHARWINDOW_H
