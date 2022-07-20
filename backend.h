#ifndef BACKEND_H
#define BACKEND_H

#endif // BACKEND_H

#include "QList"
#include "QString"
#include "QVector"
#include <windows.h>

extern QVector<QString> characters;
extern QVector<QString> conditions;
extern QVector<QVector<QVector<QString>>> commTable;
extern QVector<QString> edited;
extern QString new_char;
extern int del_char, del_row;
extern QVector<QString> turing;
extern int head_position;
extern bool stop;
extern int speed, cur_char, cur_cond;
extern QVector<int> speeds;


void editCell(int i, int j, QVector<QString> comms);

void addRow();

void addCol(QString character);

void deleteRow(int row_number);

void deleteCol(int col_number);

void step();
