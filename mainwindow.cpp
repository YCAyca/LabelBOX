#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <filesystem>
#include <image.h>
#include <fstream>
#include <QMessageBox>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    connect(ui->ImageDataset, SIGNAL(triggered(bool)), this, SLOT(ImageDatasetclicked()));
    connect(ui->Video, SIGNAL(triggered(bool)), this, SLOT(Videoclicked()));
}

void MainWindow::ImageDatasetclicked()
{
    QString folderName;
    QFileDialog dialog(this);

    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setOption(QFileDialog::ShowDirsOnly);
    dialog.setFileMode(QFileDialog::Directory);
    if (dialog.exec())
            folderName = dialog.selectedFiles()[0];

    string foldername = folderName.toStdString();
    string class_file_path = foldername + "classes.txt";

    vector<Image> images;

    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    for (const auto & filepath : recursive_directory_iterator(foldername)){
        string filepath_ = filepath.path().string();
        cout << filepath_ << endl;
        if(filepath_.substr(filepath_.find_last_of(".") + 1) == "txt")
            continue;
        Image img(filepath_);
        images.push_back(img);
    }

    ifstream class_file(class_file_path);

    vector<string> classes;

    if (class_file.is_open()){
        while(class_file){
            std::string line;
            std::getline (class_file, line);
            classes.push_back(line);
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Please select class.txt file");
        msgBox.exec();
        return;
    }

}


void MainWindow::Videoclicked()
{
    QString fileName;
    QFileDialog dialog(this);

    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);

    if (dialog.exec())
            fileName = dialog.selectedFiles()[0];

    // split the frames by given fps
    // later: key frame segmentation

}
