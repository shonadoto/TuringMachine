#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void update_table();

  void on_commandsTable_cellDoubleClicked(int row, int column);

  void on_addCharButton_clicked();

  void on_addCondButton_clicked();

  void on_delCharButton_clicked();

  void on_delCondButton_clicked();

  void on_inpButton_clicked();

  void on_playButton_clicked();

  void step_slot();


  void on_stopButton_clicked();

  void on_decButton_clicked();

  void on_incButton_clicked();

  void on_x1Button_clicked();

  void on_x2Button_clicked();

  void on_x3Button_clicked();

  void on_x4Button_clicked();

  void on_x5Button_clicked();

  void update_speeds();

  void on_eraseButton_clicked();

  void on_off_buttons(bool on_off);

  bool check();

  void error(QString s);
  void on_clearButton_clicked();

  void on_maxButton_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
