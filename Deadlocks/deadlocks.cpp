#include "deadlocks.h"
#include "ui_deadlocks.h"
#include <iostream>
#include <thread>

Deadlocks::Deadlocks()
{
}

Deadlocks::~Deadlocks()
{
}

void Deadlocks::tryMakeDeadLock(bool needCheckLocking)
{
    SimpleClass objA("objA", needCheckLocking), objB("objB", needCheckLocking);

    Runner th1Runner(objA, objB, "thread 1");
    Runner th2Runner(objA, objB, "thread 2", false);

    std::thread t1(&Runner::run, &th1Runner);
    std::thread t2(&Runner::run, &th2Runner);
    t1.join();
    t2.join();

    std::cout << "\nAll threads were finished!\n";
}
