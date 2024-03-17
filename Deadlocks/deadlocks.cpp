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
    SimpleClass objA("objA"), objB("objB");

    Runner th1Runner(objA, objB, "thread 1", true, needCheckLocking);
    Runner th2Runner(objA, objB, "thread 2", false, needCheckLocking);

    std::thread t1(&Runner::run, &th1Runner);
    std::thread t2(&Runner::run, &th2Runner);
    t1.join();
    t2.join();

    std::cout << "\nAll threads were finished!\n";
}
