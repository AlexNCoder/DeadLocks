#include "simpleclass.h"
//#include <QThread>
//#include <QDebug>
//#include <QApplication>
#include <thread>

SimpleClass::SimpleClass(std::string text, bool needCheckLock)
    :m_text(text),
      m_needCheckLock(needCheckLock)
{
}

void SimpleClass::f()
{
    if (m_needCheckLock)
    {
        if (!m_mutex.try_lock())
        {
            return;
        }
        m_mutex.unlock();
    }
    m_mutex.lock();
    m_locker.reset(new std::lock_guard<std::mutex>(m_mutex));

//    emit echo(
//                (QStringList()
//                 << m_text
//                 << " was locked from "
//                 << threadName
//                 << "\n")
//                .join(""));
//    qApp->processEvents();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    //    m_mutex.unlock();
}
