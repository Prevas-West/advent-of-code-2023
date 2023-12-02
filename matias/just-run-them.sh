#!/bin/bash

# Just make it happen!

set -e

make clean

for SRC_DAY in src/day*; do
    DAY=`basename "${SRC_DAY}"`
    echo make "${DAY}"
    make "${DAY}"
    echo -n "${DAY}: "
    ( cd ${SRC_DAY} && ../../bin/${DAY} 2>stderr )
done
