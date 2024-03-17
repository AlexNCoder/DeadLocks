#include "deadlocks.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Deadlocks dlk;
    bool needCheck = true;
    bool verbose = false;

    if (argc > 1)
    {
        if (std::string(argv[1]) == "0")
        {
            needCheck = false;
        }

        if (argc > 2)
        {
            if (std::string(argv[2]) != "0")
            {
                verbose = true;
            }
        }
    }

    dlk.tryMakeDeadLock(needCheck, verbose);
    while(1);
}
