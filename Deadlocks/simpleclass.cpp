#include "simpleclass.h"
#include <QThread>
#include <QDebug>
#include <QApplication>

SimpleClass::SimpleClass(QString text, bool needCheckLock)
    :m_text(text),
      m_needCheckLock(needCheckLock)
{
}

void SimpleClass::f(QString threadName)
{
    if (m_needCheckLock)
    {
        if (!m_mutex.tryLock())
        {
            return;
        }
        m_mutex.unlock();
    }
    m_locker.reset(new QMutexLocker(&m_mutex));

    emit echo(
                (QStringList()
                 << m_text
                 << " was locked from "
                 << threadName
                 << "\n")
                .join(""));
    qApp->processEvents();
    QThread::sleep(3);
    //    m_mutex.unlock();
}
