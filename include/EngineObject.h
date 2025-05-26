//
// Created by nadia on 26.05.25.
//

#pragma once
#include <cstdint>
#include <string>

class EngineObject {

protected:
    std::string PoolName = "EObject";
    std::string ObjectName = "DefaultObject";
    uint64_t ObjectID = 0;

public:
    EngineObject();
    ~EngineObject();
};
