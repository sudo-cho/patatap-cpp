#pragma once

#include <patatap/shapes/shape.hpp>
#include <SDL2/SDL.h>

namespace patatap {
  class Quad : public Shape {
  public:
    using Shape::Shape;
    // Quad(double tPosX, double tPosY, double tWidth, int tAnimationNumber);

    void InitShape() override;
  };
}
