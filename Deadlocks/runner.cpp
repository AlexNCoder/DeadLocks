#include "runner.h"
#include <QThread>

Runner::Runner(SimpleClass &objA,
        SimpleClass &objB,
        QString threadName,
        bool abLckOrder)
    :m_objA(objA),
      m_objB(objB),
      m_abLckOrder(abLckOrder),
      m_threadName(threadName)
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
    m_objA.f(m_threadName);
    m_objB.f(m_threadName);
}

void Runner::thBA()
{
    m_objB.f(m_threadName);
    m_objA.f(m_threadName);
}
