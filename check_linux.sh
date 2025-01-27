#!/bin/bash

# Renk tanımlamaları
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
CYAN=$(tput setaf 6)
RESET=$(tput sgr0)

# Test sonucu yazdırma fonksiyonu
function run_test {
    local description=$1
    local command=$2
    local expected=$3
    local output=$($command)
    if [[ "$output" == "$expected" ]]; then
        echo -e "${GREEN}PASSED${RESET}: $description"
    else
        echo -e "${RED}FAILED${RESET}: $description"
        echo -e "  ${YELLOW}Expected${RESET}: $expected"
        echo -e "  ${YELLOW}Got${RESET}: $output"
    fi
}

echo -e "${CYAN}Testing push_swap and checker_linux...${RESET}"

# Test 1: push_swap programı sorted bir liste için hiçbir şey döndürmemeli
run_test "push_swap sorted list: './push_swap 42'" "./push_swap 42" ""
run_test "push_swap sorted list: './push_swap 0 1 2 3'" "./push_swap 0 1 2 3" ""
run_test "push_swap sorted list: './push_swap 0 1 2 3 4 5 6 7 8 9'" "./push_swap 0 1 2 3 4 5 6 7 8 9" ""

# Test 2: push_swap ve checker_linux kombinasyonu (valid inputs)
run_test "push_swap + checker_linux valid test: '2 1 0'" "./push_swap $ARG | ./checker_linux $ARG" "OK"
run_test "push_swap + checker_linux valid test: '1 5 2 4 3'" "ARG='1 5 2 4 3'; ./push_swap $ARG | ./checker_linux $ARG" "OK"

# Test 3: Rastgele 5 değer
echo -e "${CYAN}Test: 5 random values${RESET}"
ARG=$(shuf -i 1-100 -n 5 | xargs)
output=$(./push_swap $ARG | ./checker_linux $ARG)
if [[ "$output" == "OK" ]]; then
    echo -e "${GREEN}PASSED${RESET}: push_swap + checker_linux random 5 values"
else
    echo -e "${RED}FAILED${RESET}: push_swap + checker_linux random 5 values (ARG=$ARG)"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

# Test 4: Rastgele 100 değer ve talimat sayısı kontrolü
echo -e "${CYAN}Test: 100 random values${RESET}"
ARG=$(shuf -i 1-200 -n 100 | xargs)
instructions=$(./push_swap $ARG | wc -l)
output=$(./push_swap $ARG | ./checker_linux $ARG)
if [[ "$output" == "OK" && $instructions -lt 1300 ]]; then
    echo -e "${GREEN}PASSED${RESET}: push_swap + checker_linux random 100 values (Instructions: $instructions)"
else
    echo -e "${RED}FAILED${RESET}: push_swap + checker_linux random 100 values (ARG=$ARG)"
    echo -e "  ${YELLOW}Got${RESET}: $output, ${YELLOW}Instructions${RESET}: $instructions"
fi

# Test 5: Rastgele 500 değer ve talimat sayısı kontrolü
echo -e "${CYAN}Test: 500 random values${RESET}"
ARG=$(shuf -i 1-2000 -n 500 | xargs)
instructions=$(./push_swap $ARG | wc -l)
output=$(./push_swap $ARG | ./checker_linux $ARG)
if [[ "$output" == "OK" && $instructions -lt 11500 ]]; then
    echo -e "${GREEN}PASSED${RESET}: push_swap + checker_linux random 500 values (Instructions: $instructions)"
else
    echo -e "${RED}FAILED${RESET}: push_swap + checker_linux random 500 values (ARG=$ARG)"
    echo -e "  ${YELLOW}Got${RESET}: $output, ${YELLOW}Instructions${RESET}: $instructions"
fi

echo -e "${CYAN}Testing checker program...${RESET}"

# Test 1: Non-numeric parameters
run_test "checker error: non-numeric parameters" "./checker a b c" "Error"

# Test 2: Duplicate numeric parameters
run_test "checker error: duplicate numeric parameters" "./checker 1 2 2" "Error"

# Test 3: Numeric parameter > MAXINT
run_test "checker error: numeric > MAXINT" "./checker 1 2147483648" "Error"

# Test 4: No parameters (should not display anything)
output=$(./checker)
if [[ -z "$output" ]]; then
    echo -e "${GREEN}PASSED${RESET}: checker error with no parameters"
else
    echo -e "${RED}FAILED${RESET}: checker error with no parameters"
    echo -e "  ${YELLOW}Expected${RESET}: (nothing)"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

# Test 5: Invalid action during instruction phase
echo -e "${CYAN}Test: invalid action during instruction phase${RESET}"
output=$(echo "invalid_action" | ./checker 1 2 3)
if [[ "$output" == "Error" ]]; then
    echo -e "${GREEN}PASSED${RESET}: Invalid action detected"
else
    echo -e "${RED}FAILED${RESET}: Invalid action detected"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

# Test 6: Action with extra spaces
echo -e "${CYAN}Test: action with spaces${RESET}"
output=$(echo "  pb  " | ./checker 1 2 3)
if [[ "$output" == "Error" ]]; then
    echo -e "${GREEN}PASSED${RESET}: Action with extra spaces detected"
else
    echo -e "${RED}FAILED${RESET}: Action with extra spaces detected"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

# Test 7: False test - invalid sorting instructions
echo -e "${CYAN}False test: invalid sorting instructions${RESET}"
output=$(echo -e "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5)
if [[ "$output" == "KO" ]]; then
    echo -e "${GREEN}PASSED${RESET}: checker invalid instructions"
else
    echo -e "${RED}FAILED${RESET}: checker invalid instructions"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

# Test 8: Valid instructions for sorted list
echo -e "${CYAN}Right test: valid sorting instructions${RESET}"
output=$(echo -e "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2)
if [[ "$output" == "OK" ]]; then
    echo -e "${GREEN}PASSED${RESET}: checker valid instructions"
else
    echo -e "${RED}FAILED${RESET}: checker valid instructions"
    echo -e "  ${YELLOW}Got${RESET}: $output"
fi

echo -e "${CYAN}All tests completed.${RESET}"
