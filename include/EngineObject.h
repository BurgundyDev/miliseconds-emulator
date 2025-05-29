//
// Created by nadia on 26.05.25.
//

#pragma once
#include <cstdint>
#include <string>
#include <fmt/printf.h>
#include <MemTracker.h>

class EngineObject {

protected:
    std::string ObjectName = "DefaultObject";
    uint64_t ObjectID = 0;

public:
    EngineObject();
    ~EngineObject();


    TRACK_POOL(EObject)
};
