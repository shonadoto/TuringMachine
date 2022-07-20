#ifndef DELETECONDWINDOW_H
#define DELETECONDWINDOW_H

#include <QDialog>

namespace Ui {
  class DeleteCondWindow;
}

class DeleteCondWindow : public QDialog
{
  Q_OBJECT

public:
  explicit DeleteCondWindow(QWidget *parent = nullptr);
  ~DeleteCondWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::DeleteCondWindow *ui;
};

#endif // DELETECONDWINDOW_H
