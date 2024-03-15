#include "deadlocks.h"
#include "ui_deadlocks.h"
//#include <QThread>
//#include <QDebug>

Deadlocks::Deadlocks(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Deadlocks)
{
    m_ui->setupUi(this);
}

Deadlocks::~Deadlocks()
{
    delete m_ui;
}

void Deadlocks::tryMakeDeadLock(bool needCheckLocking)
{
    SimpleClass objA("objA", needCheckLocking), objB("objB", needCheckLocking);

    connect(&objA, &SimpleClass::echo,
            this, &Deadlocks::slotEcho);
    connect(&objB, &SimpleClass::echo,
            this, &Deadlocks::slotEcho);

    Runner th1Runner(objA, objB, "thread 1");
    Runner th2Runner(objA, objB, "thread 2", false);


    th1Runner.start();
    th2Runner.start();

    th1Runner.wait();
    th2Runner.wait();

//    m_ui->outLb->setText(m_ui->outLb->text() + "\nAll threads were finished!\n");
    qDebug() << "\nAll threads were finished!\n";
}

void Deadlocks::on_pushButton_clicked()
{
    tryMakeDeadLock(!m_ui->deadLockModeBx->isChecked());
}

void Deadlocks::slotEcho(QString msg)
{
    m_ui->outLb->setText(m_ui->outLb->text() + msg);
}

void Deadlocks::on_clrOutputBtn_clicked()
{
    m_ui->outLb->clear();
}
