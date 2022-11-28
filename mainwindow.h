#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QButtonGroup>
#include "traverse.h"
#include <QMessageBox>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pickPair();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    string left;
    string right;
    QButtonGroup *block1;
    int count=2;
};
#endif // MAINWINDOW_H
