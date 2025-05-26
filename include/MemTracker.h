//
// Created by nadia on 26.05.25.
//

#pragma once
#include <map>
#include <string>
#include <cstdint>
#include <mutex>

class MemTracker {
private:
    MemTracker();

protected:
    std::map<std::string, uint64_t> AllocationMap;

public:
    MemTracker(const MemTracker& obj) = delete;
    void AddAllocation(const std::string& Pool, uint64_t Size);
    void RemoveAllocation(std::string Pool, uint64_t Size);
    static MemTracker* Get() {
        static MemTracker* Instance;
        if (Instance == nullptr) {
            Instance = new MemTracker();
        }
        return Instance;
    }
    static std::map<std::string, uint64_t>& GetAllocationsMap() { return Get()->AllocationMap; }
};

#define TRACK_CONSTRUCTION(Pool, Size) MemTracker::Get()->AddAllocation(Pool, Size)

#define TRACK_DESTRUCTION(Pool, Size) MemTracker::Get()->RemoveAllocation(Pool, Size)