#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui
{
    class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString &name, QWidget *parent = nullptr);
    ~Task();

    void setName(const QString &name);
    QString name();

    bool isComplited() const;

private:
    Ui::Task *ui_;
};

#endif // TASK_H
