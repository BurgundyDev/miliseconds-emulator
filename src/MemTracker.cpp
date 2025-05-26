//
// Created by nadia on 26.05.25.
//

#include "../include/MemTracker.h"
#include "fmt/format.h"
#include "fmt/printf.h"

MemTracker::MemTracker() {
    AllocationMap = std::map<std::string, uint64_t>();
}

void MemTracker::AddAllocation(const std::string& Pool, const uint64_t Size) {
#ifdef MS_CONFIG_DEBUG
    fmt::printf(fmt::format("Allocating {} bytes to pool {}\n", Size, Pool));
#endif
    if (AllocationMap.contains(Pool)) {
        AllocationMap[Pool] += Size;
    } else
    {
        AllocationMap.insert({Pool, Size});
    }
}

void MemTracker::RemoveAllocation(std::string Pool, uint64_t Size) {
#ifdef MS_CONFIG_DEBUG
    fmt::printf(fmt::format("Deallocating {} bytes to pool {}\n", Size, Pool));
#endif
    if (AllocationMap.contains(Pool)) {
        AllocationMap[Pool] -= Size;
    } else {
        throw fmt::format_error(fmt::format("Something went wrong, {} is not in the map but we attempt to deallocate.\n", Pool));
    }
}
