#include "task.h"
#include "ui_task.h"

Task::Task(const QString &name, QWidget *parent)
    : QWidget(parent), ui_(new Ui::Task)
{
    ui_->setupUi(this);
    setName(name);
    connect(ui_->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui_->removeButton, &QPushButton::clicked, [this, name]
            {
                qDebug() << "Trying to remove" << name;
                emit removed(this);
            });
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

void Task::rename()
{
    bool ok = false;
    QString value = QInputDialog::getText(this, tr("Edit task"), tr("Task name"), QLineEdit::Normal, this->name(), &ok);
    if (ok && !value.isEmpty())
    {
        setName(value);
    }
}
