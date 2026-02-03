#!/bin/bash

set -e

for test in tests/test_*.c; do
    name=$(basename "$test" .c)
    structure=${name#test_}

    echo "=== Building $name ==="
    
    gcc -g -O0 \
        -std=c2x -Wall -Wextra -pedantic \
        -I include \
        -I tests/unity \
        src/"$structure".c \
        tests/unity/unity.c \
        "$test" \
        -o "$name"

    echo "=== Running $name ==="
    
    "./$name"

    echo "=== Running memory leak check ==="

    valgrind \
        --leak-check=full \
        --show-leak-kinds=all \
        --error-exitcode=1 \
        ./"$name"
done
