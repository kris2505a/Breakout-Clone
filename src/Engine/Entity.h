#pragma once
#include "Components/Transform.h"

class Entity {
public:
	virtual const Transform& getTransform() const = 0;
};