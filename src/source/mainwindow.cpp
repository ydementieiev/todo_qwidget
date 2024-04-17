#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    connect(ui_->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);

    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::updateStatus()
{
    int complitedCount = 0;
    for (const auto &task : tasks_)
    {
        if (task->isComplited())
        {
            complitedCount++;
        }
    }

    int todoCount = tasks_.size() - complitedCount;
    ui_->statusLabel->setText(QString("Status: %1 todo / %2 completed").arg(todoCount).arg(complitedCount));
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
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);

        tasks_.append(task);
        ui_->tasksLayout->addWidget(task);

        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    tasks_.removeOne(task);
    ui_->tasksLayout->removeWidget(task);
    task->setParent(nullptr);
    delete task;

    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}
