#pragma once
#include <cstdint>
#include <string>
#include <EngineObject.h>
#include <fmt/printf.h>

class Mesh : public EngineObject {
public:
    TRACK_POOL(Meshes)

    int Edges[10000000];
};