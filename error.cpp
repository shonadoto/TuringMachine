#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Error)
{
  ui->setupUi(this);

  ui->label->setText(s);
}

Error::~Error()
{
  delete ui;
}

void Error::message(QString ss) {
  ui->label->setText(ss);
  return;
}
