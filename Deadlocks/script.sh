#!/bin/bash
#strace ./Deadlocks 2>&1 | grep "futex" -A 2 -B 2 > log &
if [ -z "$1" ]; then
    echo "Usage:" $'\t'"script" $'\t'"[seconds to sleep] [-d] [-vS] [-vP]"\
    $'\n'$'\t'"seconds to sleep"$'\t'"time for reaching deadlock"\
    $'\n'$'\t'"-d"$'\t\t\t'"simulate deadlock behaviour"\
    $'\n'$'\t'"-vS"$'\t\t\t'"more script output"\
    $'\n'$'\t'"-vP"$'\t\t\t'"enable runned program output"
    
    exit 0;
fi

NEEDCHECKLOCKING=1

if [[ "$2" == "-d" || $3 == "-d" || $4 == "-d" ]]; then
    NEEDCHECKLOCKING=0
fi

SCRIPTVERBOSE=0
if [[ "$2" == "-vS" || $3 == "-vS" || $4 == "-vS" ]]; then
    SCRIPTVERBOSE=1
fi

PROGRAMVERBOSE=0
if [[ "$2" == "-vP" || $3 == "-vP" || $4 == "-vP" ]]; then
    PROGRAMVERBOSE=1
fi

if [ $SCRIPTVERBOSE -eq 1 ]; then
    echo Start program detached
fi

strace ./Deadlocks $NEEDCHECKLOCKING $PROGRAMVERBOSE 2>log &
#strace ./Deadlocks false true 2>log
if [ $SCRIPTVERBOSE -eq 1 ]; then
    echo "Script will sleep for " $1 " seconds"
fi
sleep $1
FUTEX_string_start=$(cat log | tail -n1 | grep "FUTEX_WAIT" | wc -l)

if [ $FUTEX_string_start -eq 1 ]; then
    VAR_modDate_start=$(stat -c '%y' log)
    if [ $SCRIPTVERBOSE -eq 1 ]; then
        echo Futex detected
    fi
    sleep $1
    FUTEX_string_end=$(cat log | tail -n1 | grep "FUTEX_WAIT" | wc -l)

    if [ $FUTEX_string_start -eq $FUTEX_string_end ]; then
        if [ $SCRIPTVERBOSE -eq 1 ]; then
            echo Futex detected
        fi
        VAR_modDate_end=$(stat -c '%y' log)
        #echo $VAR_modDate_end
        if [[ "$VAR_modDate_start" == "$VAR_modDate_end" ]]; then
            if [ $SCRIPTVERBOSE -eq 1 ]; then
                echo "Failed. Last futex wasn't unlocked after "$1 "seconds and program wasn't active at all"
            else
                echo Failed
            fi
          
            exit 1
        fi
    fi
fi

echo Passed
exit 0
