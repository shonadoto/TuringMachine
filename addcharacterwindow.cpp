#include "addcharacterwindow.h"
#include "ui_addcharacterwindow.h"
#include "backend.h"

AddCharacterWindow::AddCharacterWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddCharacterWindow)
{
  ui->setupUi(this);
}

AddCharacterWindow::~AddCharacterWindow()
{
  delete ui;
}

void AddCharacterWindow::on_okButton_clicked()
{
    QString ch = ui->charText->text();
    new_char = ch;
    return;
}
