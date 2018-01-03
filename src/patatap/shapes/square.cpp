#include <patatap/shapes/square.hpp>

namespace patatap {
  // Square::Square(double tPosX, double tPosY, double tWidth, double tHeight, int tAnimationNumber)
  //   : Shape(double tPosX, double tPosY, double tWidth, double tHeight, int tAnimationNumber)
  // {}

  void Square::InitShape () {

    Shape::InitShape();

    this->rect.h = width;
    initH = rect.h;
  }
}
