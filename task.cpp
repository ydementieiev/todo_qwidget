#include "task.h"
#include "ui_task.h"

Task::Task(const QString &name, QWidget *parent)
    : QWidget(parent), ui_(new Ui::Task)
{
    ui_->setupUi(this);
    setName(name);
}

Task::~Task()
{
    delete ui_;
}

void Task::setName(const QString &name)
{
    ui_->checkBox->setText(name);
}

QString Task::name()
{
    return ui_->checkBox->text();
}

bool Task::isComplited() const
{
    return ui_->checkBox->isChecked();
}
