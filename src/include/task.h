#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QInputDialog>

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

public slots:
    void rename();

signals:
    void removed(Task *task);
    void statusChanged(Task *task);

private slots:
    void checked(bool checked);

private:
    Ui::Task *ui_;
};

#endif // TASK_H
