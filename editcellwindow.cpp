#include "editcellwindow.h"
#include "ui_editcellwindow.h"
#include "backend.h"

EditCellWindow::EditCellWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::EditCellWindow)
{
  ui->setupUi(this);
  ui->charBox->addItems(QStringList::fromVector(characters));
  ui->conBox->addItems(QStringList::fromVector(conditions));
}

EditCellWindow::~EditCellWindow()
{
  delete ui;
}

void EditCellWindow::on_okButton_clicked()
{
  edited[0] = ui->charBox->currentText();
  edited[1] = ui->moveBox->currentText();
  edited[2] = ui->conBox->currentText();
  return;
}
