//
// Created by nadia on 26.05.25.
//
#include "EngineObject.h"

#include "MemTracker.h"

EngineObject::EngineObject() {
    TRACK_CONSTRUCTION(PoolName, sizeof(*this));
}

EngineObject::~EngineObject() {
    TRACK_DESTRUCTION(PoolName, sizeof(*this));
}
