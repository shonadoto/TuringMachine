#ifndef INPWINDOW_H
#define INPWINDOW_H

#include <QDialog>

namespace Ui {
  class InpWindow;
}

class InpWindow : public QDialog
{
  Q_OBJECT

public:
  explicit InpWindow(QWidget *parent = nullptr);
  ~InpWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::InpWindow *ui;
};

#endif // INPWINDOW_H
