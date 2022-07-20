#include "backend.h"
#include "QList"
#include "QString"
#include "QVector"
#include <algorithm>

QVector<QString> characters = {"_"};
QVector<QString> conditions = {"q0"};
QVector<QVector<QVector<QString>>> commTable = {{{"", "", "!"}}};

QVector<QString> edited = {"", "", ""};
QString new_char = "";
int del_char = 0, del_row = 0;

QVector<QString> turing(1000000, "_");
int head_position = 500000, cur_char = 0, cur_cond = 0;

bool stop = false;
int speed = 0;
QVector<int> speeds ={2000, 1000, 500, 250, 125, 0};

void editCell(int i, int j, QVector<QString> comms) {
  commTable[i][j] = comms;
  return;
}

void addCol(QString character) {
  characters.push_back(character);

  for (int i = 0; i < commTable.size(); ++i) {
      QVector<QString> col_item(3, QString(""));
      commTable[i].push_back(col_item);
    }


  return;
}

void addRow() {
  QString cond =   "q";
  cond  = cond + QString::number(commTable.size());
  conditions.push_back(cond);
  QVector<QVector<QString>> row(characters.size(), QVector<QString>(3, QString("")));
  commTable.push_back(row);
  return;
}

void deleteRow(int row_number) {
  commTable.erase(commTable.begin() + row_number);
  conditions.pop_back();
  return;
}

void deleteCol(int col_number) {
  characters.erase(characters.begin() + col_number);
  for (int i = 0; i < commTable.size(); ++i) {
      commTable[i].erase(commTable[i].begin() + col_number);
    }
  return;
}

void step() {
  bool all_empty = true;
  if (commTable[cur_cond][cur_char][0] != "") {
      turing[head_position] = commTable[cur_cond][cur_char][0];
      all_empty = false;
    }
  if (commTable[cur_cond][cur_char][1] != "") {
      if (commTable[cur_cond][cur_char][1] == "←")
        head_position--;
      else
        head_position++;
      all_empty = false;
    }
  if (commTable[cur_cond][cur_char][2] != "") {
      if (commTable[cur_cond][cur_char][2] == "!") {
          stop = true;
        } else {
          cur_cond = std::find(conditions.begin(), conditions.end(), commTable[cur_cond][cur_char][2]) - conditions.begin();
        }
      all_empty = false;
    }
  if (all_empty) {
      stop = true;
    }
  return;
}
