#include <iostream>

#include "fmt/printf.h"


int main() {
    fmt::printf(fmt::format("Test {}", 42));

    return 0;
}
