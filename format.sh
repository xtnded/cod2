#!/bin/bash
find . \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) -exec clang-format -i {} +
