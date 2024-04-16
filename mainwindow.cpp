#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connect(ui_->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::addTask()
{
    qDebug() << "Adding new task";
    Task *task = new Task("Untitled task");

    tasks_.append(task);
    ui_->tasksLayout->addWidget(task);
}
