#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "backend.h"
#include "editcellwindow.h"
#include "addcharacterwindow.h"
#include "deletecharwindow.h"
#include "deletecondwindow.h"
#include "inpwindow.h"
#include "QTimer"
#include "error.h"
#include "QDebug"
int col_cnt = 19;

QTimer *timer;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  timer = new QTimer(this);
  ui->inpButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->addCharButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->addCondButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->delCharButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->delCondButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");

  ui->playButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->stopButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x1Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x2Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x3Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x4Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x5Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->decButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->incButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->eraseButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->clearButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->maxButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");;

  QPixmap bkgnd("C:/Users/vanko/Documents/prakTuring/anime.jpg");
  bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
  QPalette palette;
  palette.setBrush(QPalette::Background, bkgnd);
  this->setPalette(palette);
  ui->lineTable->setColumnCount(col_cnt);
  ui->lineTable->setRowCount(1);
  ui->lineTable->verticalHeader()->hide();
  ui->lineTable->horizontalHeader()->hide();
  for (int i = 0; i < col_cnt; ++i) {
      ui->lineTable->setColumnWidth(i,25);
    }

  ui->lineTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  update_table();
}


MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::update_table() {
  QStringList line;
  for (int i = head_position - col_cnt/2; i <= head_position + col_cnt/2; ++i) {
      ui->lineTable->setItem(0,i - head_position + col_cnt / 2, new QTableWidgetItem(turing[i]));
    }
  ui->lineTable->item(0, col_cnt / 2)->setBackground(QBrush(QColor(98,213,208, 255)));
  ui->lineTable->setHorizontalHeaderLabels(line);
  ui->commandsTable->setEditTriggers(0);
  ui->commandsTable->setRowCount(conditions.size());
  ui->commandsTable->setColumnCount(characters.size());
  ui->commandsTable->setHorizontalHeaderLabels(QStringList::fromVector(characters));
  ui->commandsTable->setVerticalHeaderLabels(QStringList::fromVector(conditions));
  for (int i = 0; i < commTable.size(); ++i) {
      for (int j = 0; j < commTable[i].size(); ++j) {
          ui->commandsTable->setItem(i, j, new QTableWidgetItem(commTable[i][j][0] + commTable[i][j][1] + commTable[i][j][2]));
        }
    }

  ui->commandsTable->item(cur_cond, cur_char)->setBackground(QBrush(QColor(98,213,208, 255)));
  return;
}

void MainWindow::error(QString s) {
  Error w;
  w.setModal(true);
  w.message(s);
  w.setWindowTitle("Error!");
  w.exec();
}

void MainWindow::update_speeds() {
  ui->x1Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x2Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x3Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x4Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");
  ui->x5Button->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");

  ui->maxButton->setStyleSheet("QPushButton{background-color: rgba(98,213,208, 200);}");

  if (speed >= 0)
    ui->x1Button->setStyleSheet("QPushButton{background-color: rgba(213,170,0, 200);}");
  if (speed >= 1)
    ui->x2Button->setStyleSheet("QPushButton{background-color: rgba(213,170,0, 200);}");
  if (speed >= 2)
    ui->x3Button->setStyleSheet("QPushButton{background-color: rgba(213,170,0, 200);}");
  if (speed >= 3)
    ui->x4Button->setStyleSheet("QPushButton{background-color: rgba(213,170,0, 200);}");
  if (speed >= 4)
    ui->x5Button->setStyleSheet("QPushButton{background-color: rgba(213,85,0, 200);}");
  if (speed >= 5)
    ui->maxButton->setStyleSheet("QPushButton{background-color: rgba(255,30,30, 200);}");
}

void MainWindow::step_slot() {

  if (stop) {
      on_off_buttons(1);
      timer->stop();
      return;
    }

  ui->commandsTable->item(cur_cond, cur_char)->setBackground(QBrush(QColor(255,255,255, 255)));
  cur_char = std::find(characters.begin(), characters.end(), turing[head_position])-characters.begin();
  update_table();
  step();
}

bool MainWindow::check() {
  bool ok = true;
  for (int i = 0; i < conditions.size(); ++i) {
      for (int j = 0; j < characters.size(); ++j) {
          if (std::find(characters.begin(), characters.end(), commTable[i][j][0]) == characters.end() && commTable[i][j][0] != "" ||
              std::find(conditions.begin(), conditions.end(), commTable[i][j][2]) == conditions.end() && commTable[i][j][2] != "!" && commTable[i][j][2] != "") {
            ok = false;
            }
        }
    }
  return ok;
}

void MainWindow::on_commandsTable_cellDoubleClicked(int row, int column)
{
  EditCellWindow w;
  w.setModal(true);
  w.setWindowTitle("Edit cell");
  w.exec();
  commTable[row][column] = edited;
  update_table();
}

void MainWindow::on_addCharButton_clicked()
{
  AddCharacterWindow w;
  w.setModal(true);
  w.setWindowTitle("Add character");
  w.exec();
  if (new_char.size() != 1) {
      error("Not char!");
      return;
    }
  if (std::find(characters.begin(), characters.end(), new_char) != characters.end()) {
      error("Char already exists");
      return;
    }
  addCol(new_char);
  update_table();
}

void MainWindow::on_addCondButton_clicked()
{
  addRow();
  update_table();
}

void MainWindow::on_delCharButton_clicked()
{
  if (characters.size() == 1) {
      error("Can't delete _");
      return;
    }

  DeleteCharWindow w;
  w.setModal(true);
  w.setWindowTitle("Delete character");
  w.exec();
  deleteCol(del_char);
  update_table();
}



void MainWindow::on_delCondButton_clicked()
{
  if (conditions.size() == 1) {
      error("Can't delete q0");
      return;
    }
  DeleteCondWindow w;
  w.setModal(true);
  w.setWindowTitle("Delete condition");
  w.exec();
  deleteRow(del_row);
  update_table();
}

void MainWindow::on_inpButton_clicked()
{
  InpWindow w;
  w.setModal(true);
  w.setWindowTitle("Input string");
  w.exec();
  update_table();
}

void MainWindow::on_off_buttons(bool on_off) {
  ui->inpButton->setEnabled(on_off);
  ui->addCharButton->setEnabled(on_off);
  ui->addCondButton->setEnabled(on_off);
  ui->delCharButton->setEnabled(on_off);
  ui->delCondButton->setEnabled(on_off);
  ui->eraseButton->setEnabled(on_off);
  ui->clearButton->setEnabled(on_off);
}



void MainWindow::on_playButton_clicked()
{
  if (!check()) {
      error("Using undeclared chars or conditions");
      return;
    }
  stop = false;
  on_off_buttons(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(step_slot()));
  update_speeds();
  timer->start(speeds[speed]);
  return;
}

void MainWindow::on_stopButton_clicked()
{
  timer->stop();
  on_off_buttons(1);
  return;
}

void MainWindow::on_decButton_clicked()
{
  timer->stop();
  if (speed > 0)
    --speed;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_incButton_clicked()
{
  timer->stop();
  if (speed < 4)
    ++speed;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_x1Button_clicked()
{
  timer->stop();
  speed = 0;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_x2Button_clicked()
{
  timer->stop();
  speed = 1;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_x3Button_clicked()
{
  timer->stop();
  speed = 2;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_x4Button_clicked()
{
  timer->stop();
  speed = 3;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_x5Button_clicked()
{
  timer->stop();
  speed = 4;
  update_speeds();
  timer->start(speeds[speed]);
}

void MainWindow::on_eraseButton_clicked()
{
  std::fill(turing.begin(), turing.end(), "_");
  cur_cond = 0;
  update_table();
}

void MainWindow::on_clearButton_clicked()
{
    for (int i = 0; i< conditions.size(); ++i) {
        for (int j = 0; j < characters.size(); ++j) {
            commTable[i][j] = {"", "", ""};
          }
      }
    update_table();
}

void MainWindow::on_maxButton_clicked()
{
    timer->stop();
    speed = 5;
    update_speeds();
    timer->start(speeds[speed]);
}
