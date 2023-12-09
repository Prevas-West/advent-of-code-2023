#!/bin/bash

# Just make it happen!

set -e

BUILD_DAY="$1"

if [ -z "${BUILD_DAY}" ]; then
    make clean
    make all
else
    make "${BUILD_DAY}"
fi

for SRC_DAY in src/day*; do
    DAY=`basename "${SRC_DAY}"`
    echo -n "${DAY}: "
    if [ -f "${SRC_DAY}/input" ]; then
        ( cd ${SRC_DAY} && ../../bin/${DAY} 2>stderr )
    else
        echo "ERROR: ${DAY} is missing the input file!"
    fi
done
