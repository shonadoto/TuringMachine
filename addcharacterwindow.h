#ifndef ADDCHARACTERWINDOW_H
#define ADDCHARACTERWINDOW_H

#include <QDialog>

namespace Ui {
  class AddCharacterWindow;
}

class AddCharacterWindow : public QDialog
{
  Q_OBJECT

public:
  explicit AddCharacterWindow(QWidget *parent = nullptr);
  ~AddCharacterWindow();

private slots:
  void on_okButton_clicked();

private:
  Ui::AddCharacterWindow *ui;
};

#endif // ADDCHARACTERWINDOW_H
