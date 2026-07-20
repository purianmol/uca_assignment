#!/bin/bash

FILE="employees.txt"

echo "========== Task 1: Basic Field Extraction =========="
awk -F',' '{print $1, $2}' "$FILE"

echo
echo "========== Task 2: Engineering Employees =========="
awk -F',' '$2=="Engineering"' "$FILE"

echo
echo "========== Task 3: Gross Pay =========="
awk -F',' '{printf "%s gross pay: $%d\n", $1, $3*$4}' "$FILE"

echo
echo "========== Task 4: NR and NF =========="
awk -F',' '{printf "%d (%d fields): %s\n", NR, NF, $0}' "$FILE"

echo
echo "========== Task 5: Total Engineering Payroll =========="
awk -F',' '
BEGIN {
    total = 0
}
$2 == "Engineering" {
    total += $3 * $4
}
END {
    printf "Total Engineering Payroll: $%d\n", total
}
' "$FILE"
