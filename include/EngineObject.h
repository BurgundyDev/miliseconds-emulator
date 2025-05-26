//
// Created by nadia on 26.05.25.
//

#pragma once
#include <string>

class EngineObject {

protected:
    std::string PoolName = "EObject";
    std::string ObjectName = "DefaultObject";

public:
    EngineObject();
    ~EngineObject();
};
