#!/bin/bash

OUTPUT_FILE="Results/time_report.csv"
echo "UnitTest,LoopOrder,TimeTaken(ms),Status" > $OUTPUT_FILE

LOOP_ORDERS=("ijk" "ikj" "jik" "jki" "kij" "kji")

gcc driver.c -o driver -O2
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

for TEST_DIR in Unit_test/unit_* Negative_test/unit_*; do
    if [ -d "$TEST_DIR" ]; then
        for LOOP_ORDER in "${LOOP_ORDERS[@]}"; do
            echo "Running test: $TEST_DIR with loop order: $LOOP_ORDER"

            START_TIME=$(date +%s%3N)
            ./driver "$LOOP_ORDER" "$TEST_DIR"
            STATUS=$?
            END_TIME=$(date +%s%3N)

            TIME_TAKEN=$((END_TIME - START_TIME))
            UNIT_NAME=$(basename "$TEST_DIR")
            if [ $STATUS -eq 0 ]; then
                TEST_STATUS="Success"
            else
                TEST_STATUS="Failure"
            fi

            echo "$UNIT_NAME,$LOOP_ORDER,$TIME_TAKEN,$TEST_STATUS" >> $OUTPUT_FILE
        done
    fi
done

echo "All tests completed. Results saved in $OUTPUT_FILE."
