#pragma once

#ifdef __APPLE__
#else
#include <GL/glew.h>
#endif

#include "glm.hpp"

namespace glimac {

struct ShapeVertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

}
