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

#define TRACK_POOL(Pool) \
    void* operator new(size_t size) \
    { \
        MemTracker::Get()->AddAllocation(#Pool, uint64_t(size)); \
        return ::operator new(size); \
    }; \
    void* operator new[](size_t size) \
    { \
        MemTracker::Get()->AddAllocation(#Pool, uint64_t(size)); \
        return ::operator new[](size); \
    }; \
    void operator delete(void* ptr, size_t size) \
    { \
        MemTracker::Get()->RemoveAllocation(#Pool, uint64_t(size)); \
        ::operator delete(ptr); \
    }; \
    void operator delete[](void* ptr, size_t size) \
    { \
        MemTracker::Get()->RemoveAllocation(#Pool, uint64_t(size)); \
        ::operator delete[](ptr); \
    };

#define TRACK_ALLOCATION(Pool, Size) MemTracker::Get()->AddAllocation(Pool, Size);

#define TRACK_DEALLOCATION(Pool, Size) MemTracker::Get()->RemoveAllocation(Pool, Size);