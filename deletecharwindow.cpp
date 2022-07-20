#include "deletecharwindow.h"
#include "ui_deletecharwindow.h"
#include "backend.h"

DeleteCharWindow::DeleteCharWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DeleteCharWindow)
{
  ui->setupUi(this);
  QStringList chars;
  for (int i = 1; i < characters.size(); ++i)
    chars.push_back(characters[i]);
  ui->comboBox->addItems(chars);
}

DeleteCharWindow::~DeleteCharWindow()
{
  delete ui;
}

void DeleteCharWindow::on_pushButton_clicked()
{
  for (auto& c : turing)
    if (c == ui->comboBox->currentText())
      c = "_";
  del_char = std::find(characters.begin(), characters.end(), ui->comboBox->currentText()) - characters.begin();
  return;
}
