#include "b.h"
#include <QThread>

B::B()
{
}

void B::f()
{
    QMutexLocker lock(&m_mutex);
    QThread::sleep(10);
}
