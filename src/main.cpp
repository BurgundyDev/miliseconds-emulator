#include <iostream>
#include <vector>

#include "EngineObject.h"
#include "MemTracker.h"
#include "fmt/printf.h"


int main() {
    auto TestObject = new EngineObject();
    std::map<std::string, uint64_t>& allocations = MemTracker::GetAllocationsMap();
    for (auto& [key, value] : allocations) {
        fmt::printf(fmt::format("Key: {}, Value: {}\n", key, value));
    }
    delete TestObject;
    return 0;
}
