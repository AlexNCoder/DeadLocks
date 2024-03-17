#include "deadlocks.h"

int main(int argc, char *argv[])
{
    Deadlocks w;

    if (argc > 1)
    {
        if (std::string(argv[1]) == "-d")
        {
            w.tryMakeDeadLock(false);
            while(1);
        }
    }

    w.tryMakeDeadLock(true);
    while(1);
}
