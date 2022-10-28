#include "todo.h"
#include "ui_todo.h"

ToDo::ToDo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToDo)
{
    ui->setupUi(this);
    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(addTaskSlot()));

    ui->AddTaskLine->setText("I want to...");
    ui->AddDate->setDate(QDate::currentDate());

}

ToDo::~ToDo()
{
    delete ui;
}

void ToDo::addTaskSlot(){

    QString taskName = ui->AddTaskLine->text();
    QDate taskDate = ui->AddDate->date();

    createNewTask(taskName,taskDate);
}

void ToDo::deleteTaskSlot(){

    QPushButton* button = (QPushButton*)sender();

    QVariant var = button->property("Current Task");
    QFrame* taskBox = qvariant_cast<QFrame*>(var);
    taskBox->deleteLater();
    delete taskBox;

}

void ToDo::createNewTask(QString taskName, QDate taskDate){

    QVBoxLayout* mainVLayout = qobject_cast<QVBoxLayout*>(ui->ScrollAreaWidgetContents->layout());;
    QFrame* horizontal = new QFrame();
    QHBoxLayout * hLayout = new QHBoxLayout(horizontal);
    horizontal->setLayout(hLayout);
    QFrame* vertical = new QFrame();
    QVBoxLayout * vLayout = new QVBoxLayout(vertical);
    vertical->setLayout(vLayout);

    QLabel* task = new QLabel(taskName);
    vLayout->addWidget(task);
    QLabel* date = new QLabel(taskDate.toString());
    vLayout->addWidget(date);

    hLayout->insertWidget(0,vertical);
    QSpacerItem * hspacer = new QSpacerItem(100,100,QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    hLayout->insertSpacerItem(1,hspacer);
    QPushButton* deleteButton = new QPushButton("Delete Task");
    hLayout->insertWidget(2,deleteButton);

    deleteButton->setProperty("Current Task", QVariant(QVariant::fromValue<QFrame*>(horizontal)));

    mainVLayout->insertWidget(mainVLayout->count()-1, horizontal);

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteTaskSlot()));

}

