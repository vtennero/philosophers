

#!/bin/bash

# Path to the file containing test commands
TEST_COMMANDS_FILE="test_commands.txt"

# Initialize counters
total_tests=0
passed_tests=0
segfaults=0
timeouts=0
other_errors=0

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Read each line from the file
while IFS= read -r line
do
  output=$(timeout 30s $line 2>&1)
  exit_status=$?

  ((total_tests++))

  if [ $exit_status -eq 124 ]; then
    ((timeouts++))
    echo -n "⏱️ "
  elif [ $exit_status -eq 139 ]; then
    ((segfaults++))
    echo -n "🔥"
  else
    last_line=$(echo "$output" | tail -n 1)
    if [[ $last_line == *"died"* ]]; then
      ((passed_tests++))
      # Ensure the green dot is reset after each use
      echo -ne "${GREEN}✓${NC}"
    else
      ((other_errors++))
      # Ensure the red cross is reset after each use
      echo -ne "${RED}✘${NC}"
    fi
  fi
done < "$TEST_COMMANDS_FILE"

# Display the results
echo "" # Move to a new line
echo "Results: ✅ $passed_tests/$total_tests, 🔥 $segfaults, ⏱️ $timeouts."
