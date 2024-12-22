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
            AVG_CALCULATION=0.0;
            SUCCESS_COUNT=0

            # Run the unit tests 5 times and calculate the average time taken
            for i in {1..5}; do
                echo "Testing loop order: $LOOP_ORDER"

                # Get the start time
              DRIVER_OUTPUT=$(./driver "$UNIT_DIR" "$LOOP_ORDER")

                # Extract the time taken (double) from the output using grep and awk
                TIME_TAKEN=$(echo "$DRIVER_OUTPUT" | grep -oP '(?<=Time taken \(ms\): )[\d.]+')


                # Determine test result status
                 if [[ -z "$TIME_TAKEN" || $(awk "BEGIN {print ($TIME_TAKEN < 0)}") -eq 1 ]]; then
                    TEST_STATUS="Failure"
                    AVG_CALCULATION=0.0
                    break
                else
                    TEST_STATUS="Success"
                    SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
                    AVG_CALCULATION=$(awk "BEGIN {print ($AVG_CALCULATION + $TIME_TAKEN)}")
                fi
            done
            if [[ "$SUCCESS_COUNT" -gt 0 ]]; then
                AVG_CALCULATION=$(awk "BEGIN {print ($AVG_CALCULATION / $SUCCESS_COUNT)}")
            else
                AVG_CALCULATION=0.0
            fi
            echo "$UNIT_NAME,$LOOP_ORDER,$AVG_CALCULATION,$TEST_STATUS" >> $OUTPUT_FILE
        done
    fi
done

echo "All tests completed. Results saved in $OUTPUT_FILE."
