#include "simpleclass.h"
#include <thread>
#include <iostream>

SimpleClass::SimpleClass(std::string objName, bool verbose)
    :m_objName(objName),
      m_verbose(verbose)
{
}

void SimpleClass::f()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void SimpleClass::lock(std::string threadName)
{
    m_mutex.lock();
    //    m_locker.reset(new std::lock_guard<std::mutex>(m_mutex));
    if (m_verbose)
    {
        std::cout
                << m_objName << " was locked from "
                << threadName << std::endl;
    }
}

bool SimpleClass::tryLock(std::string threadName)
{
    auto b = m_mutex.try_lock();
    if (b)
    {
        if (m_verbose)
        {
            std::cout
                    << m_objName << " was locked from "
                    << threadName << std::endl;
        }

        return true;
    }

    if (m_verbose)
    {
        std::cout
                << m_objName << " can't be locked from "
                << threadName << std::endl;
    }

    return false;
}

void SimpleClass::unLock(std::string threadName)
{
    m_mutex.unlock();

    if (m_verbose)
    {
        std::cout
                << m_objName << " was unlocked from "
                << threadName << std::endl;
    }
}
