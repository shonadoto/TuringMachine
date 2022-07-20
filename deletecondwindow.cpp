#include "deletecondwindow.h"
#include "ui_deletecondwindow.h"
#include "backend.h"
DeleteCondWindow::DeleteCondWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DeleteCondWindow)
{
  ui->setupUi(this);
  ui->comboBox->addItems(QStringList::fromVector(conditions));
}

DeleteCondWindow::~DeleteCondWindow()
{
  delete ui;
}

void DeleteCondWindow::on_pushButton_clicked()
{
  del_row = std::find(conditions.begin(), conditions.end(), ui->comboBox->currentText()) - conditions.begin();
  return;
}
