#ifndef EDITCELLWINDOW_H
#define EDITCELLWINDOW_H

#include <QDialog>

namespace Ui {
  class EditCellWindow;
}

class EditCellWindow : public QDialog
{
  Q_OBJECT

public:
  explicit EditCellWindow(QWidget *parent = nullptr);
  ~EditCellWindow();

private slots:
  void on_okButton_clicked();

private:
  Ui::EditCellWindow *ui;
};

#endif // EDITCELLWINDOW_H
