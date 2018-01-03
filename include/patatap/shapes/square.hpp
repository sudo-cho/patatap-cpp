#pragma once

#include <patatap/shapes/shape.hpp>
#include <SDL2/SDL.h>

namespace patatap {
  class Square : public Shape {
  public:
    using Shape::Shape;
    void InitShape() override;
  };
}
