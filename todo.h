#ifndef TODO_H
#define TODO_H

#include <QWidget>
#include "ui_todo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ToDo; }
QT_END_NAMESPACE

class ToDo : public QWidget
{
    Q_OBJECT

public:
    ToDo(QWidget *parent = nullptr);
    ~ToDo();

private:
    Ui::ToDo *ui;

public:
    void createNewTask(QString taskName, QDate taskDate);

public slots:
    void addTaskSlot();
    void deleteTaskSlot();
signals:
    void addTaskSignal(QString taskName, QDate taskDate);
};
#endif // TODO_H
