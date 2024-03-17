#!/bin/bash
#strace ./Deadlocks 2>&1 | grep "futex" -A 2 -B 2 > log &
if [ -z "$1"]; then
    echo "Usage:" $'\t'"script" $'\t'"[seconds to sleep] [-d] [-v]"\
    $'\n'$'\t'"-d"$'\t'"simulate deadlock behaviour"\
    $'\n'$'\t'"-v"$'\t'"more output"
    
    exit 0;
fi

echo Start program detached
strace ./Deadlocks $2 $3 2>log &
echo "Script will sleep for " $1 " seconds"
sleep $1
FUTEX_string_start=$(cat log | tail -n1 | grep "FUTEX_WAIT" | wc -l)
echo $FUTEX_string_start

if [ $FUTEX_string_start -eq 1 ]; then
    VAR_modDate_start=$(stat -c '%y' log)
    echo Futex detected
    sleep $1
    FUTEX_string_end=$(cat log | tail -n1 | grep "FUTEX_WAIT" | wc -l)

    if [ $FUTEX_string_start -eq $FUTEX_string_end ]; then
        echo Futex detected
        VAR_modDate_end=$(stat -c '%y' log)
        #echo $VAR_modDate_end
        if [[ "$VAR_modDate_start" == "$VAR_modDate_end" ]]; then
            echo "Failed. Last futex wasn't unlocked after " $1 "seconds and program wasn't active at all"
            exit 1
        fi
    fi
fi

echo Passed
exit 0
