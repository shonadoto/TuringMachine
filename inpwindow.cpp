#include "inpwindow.h"
#include "ui_inpwindow.h"
#include "backend.h"
InpWindow::InpWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InpWindow)
{
  ui->setupUi(this);
}

InpWindow::~InpWindow()
{
  delete ui;
}

void InpWindow::on_pushButton_clicked()
{
  QString inp = ui->lineEdit->text();
  for (int i = 0; i < inp.size(); ++i) {
      turing[head_position + i] = "_";
      if (std::find(characters.begin(), characters.end(), inp[i]) != characters.end())
        turing[head_position + i] = "" + inp[i];
    }
  return;
}
