#include "runner.h"

Runner::Runner(
        SimpleClass &objA,
        SimpleClass &objB,
        std::string threadName,
        bool abLckOrder,
        bool needCheckLock)
    :m_objA(objA),
      m_objB(objB),
      m_abLckOrder(abLckOrder),
      m_threadName(threadName),
      m_needCheckLock(needCheckLock)
{
}

void Runner::run()
{
    if (m_abLckOrder)
    {
        thAB();
    }
    else
    {
        thBA();
    }
}

void Runner::thAB()
{
    if (m_needCheckLock)
    {
        if (m_objA.tryLock(m_threadName))
        {
            m_objA.f();
            m_objA.unLock(m_threadName);
        }

        if (m_objB.tryLock(m_threadName))
        {
            m_objB.f();
            m_objB.unLock(m_threadName);
        }

        return;
    }

    m_objA.lock(m_threadName);
    m_objA.f();
    m_objB.lock(m_threadName);
    m_objA.unLock(m_threadName);

    m_objB.f();
    m_objB.unLock(m_threadName);
}

void Runner::thBA()
{
    if (m_needCheckLock)
    {
        if (m_objB.tryLock(m_threadName))
        {
            m_objB.f();
            m_objB.unLock(m_threadName);
        }

        if (m_objA.tryLock(m_threadName))
        {
            m_objA.f();
            m_objA.unLock(m_threadName);
        }

        return;
    }

    m_objB.lock(m_threadName);
    m_objB.f();
    m_objA.lock(m_threadName);
    m_objB.unLock(m_threadName);

    m_objA.f();
    m_objA.unLock(m_threadName);
}
