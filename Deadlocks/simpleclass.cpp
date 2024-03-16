#include "simpleclass.h"
#include <thread>
#include <iostream>

SimpleClass::SimpleClass(bool needCheckLock)
    :m_needCheckLock(needCheckLock)
{
}

void SimpleClass::f(std::string threadName)
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

    std::cout << threadName << "    started";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    m_mutex.unlock();
    std::cout << threadName << "    finished";
}
