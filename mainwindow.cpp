#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>

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
    bool ok = false;
    QString name = QInputDialog::getText(this, tr("Add task"), tr("Task name"), QLineEdit::Normal, tr("Untitled task"), &ok);
    if (ok && !name.isEmpty())
    {

        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);

        tasks_.append(task);
        ui_->tasksLayout->addWidget(task);
    }
}

void MainWindow::removeTask(Task *task)
{
    tasks_.removeOne(task);
    ui_->tasksLayout->removeWidget(task);
    task->setParent(nullptr);
    delete task;
}
