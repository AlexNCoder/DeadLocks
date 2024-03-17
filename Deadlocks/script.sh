#!/bin/bash
#strace ./Deadlocks 2>&1 | grep "futex" -A 2 -B 2 > log &
echo Start program
strace ./Deadlocks $2 2>log &
echo "Sleep for " $1 " seconds"
sleep $1
VAR=$(cat log | tail -n2 | grep "futex" | wc -l)
if [ $VAR -eq 1 ]; then
    echo Failed. Maybe program is deadlocked
    exit 1
fi
echo Passed
exit 0
