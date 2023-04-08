#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ImageDataset_clicked()
{


}

void MainWindow::on_LabelFile_clicked()
{


}

void MainWindow::on_Video_clicked()
{
    // split the frames by given fps
    // later: key frame segmentation

}
