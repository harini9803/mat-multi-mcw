#!/bin/bash

# CSV file to store the results
OUTPUT_FILE="Results/time_report.csv"

# Header for the CSV file
echo "UnitTest,LoopOrder,TimeTaken(ms),Status" > $OUTPUT_FILE

# Compile the driver program
gcc driver.c -o driver -O2
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# Loop through each unit test directory
for UNIT_DIR in Unit_test/unit_*; do
    if [ -d "$UNIT_DIR" ]; then
        UNIT_NAME=$(basename "$UNIT_DIR")
        echo "Running tests for: $UNIT_NAME"

        # Loop orders to test
        LOOP_ORDERS=("ijk" "ikj" "jik" "jki" "kij" "kji")

        # Test each loop order
        for LOOP_ORDER in "${LOOP_ORDERS[@]}"; do
            echo "Testing loop order: $LOOP_ORDER"

            # Get the start time
            START_TIME=$(date +%s%3N)

            # Run the driver program with the current test directory and loop order
            ./driver "$UNIT_DIR" "$LOOP_ORDER"
            STATUS=$?

            # Get the end time
            END_TIME=$(date +%s%3N)

            # Calculate the time taken
            TIME_TAKEN=$((END_TIME - START_TIME))

            # Determine test result status
            if [ $STATUS -eq 0 ]; then
                TEST_STATUS="Success"
            else
                TEST_STATUS="Failure"
            fi

            # Append results to the CSV file
            echo "$UNIT_NAME,$LOOP_ORDER,$TIME_TAKEN,$TEST_STATUS" >> $OUTPUT_FILE
        done
    fi
done

echo "All tests completed. Results saved in $OUTPUT_FILE."
