#include <patatap/shapes/shape.hpp>

namespace patatap {
  Shape::Shape (double tPosX, double tPosY, double tWidth, double tHeight, int tAnimationNumber)
    : xPos(tPosX), yPos(tPosY), width(tWidth), height(tHeight), animationNumber(tAnimationNumber)
  {
    this->InitShape();
  }

  Shape::Shape(double tPosX, double tPosY, double tWidth, int tAnimationNumber)
    : xPos(tPosX), yPos(tPosY), width(tWidth), animationNumber(tAnimationNumber)
  {
    this->InitShape();
  }

  Shape::~Shape () {}

  void Shape::InitShape () {
    this->rect.x = xPos;
    this->rect.y = yPos;
    this->rect.w = width;
    this->rect.h = height;

    initX = rect.x;
    initY = rect.y;
    initW = rect.w;
    initH = rect.h;
  }

  SDL_Rect Shape::GetShape () const {
    return this->rect;
  }

  void Shape::setWidth (const double tWidth) {
    rect.w += tWidth;
  }

  void Shape::setHeight (const double tHeight) {
    rect.h += tHeight;
  }

  void Shape::setX (const double tX) {
    rect.x += tX;
  }

  void Shape::setY (const double tY) {
    rect.y += tY;
  }

  void Shape::InitAnimation (double delta) {
    if (animationStatus != -1 && animationStatus < speed) {
      switch (animationNumber) {
      case 0:
        GrowAndMove(delta);
        break;
      case 1:
        MoveLeft(delta);
        break;
      case 2:
        GrowLeft(delta);
        break;

      }
      animationStatus++;
    }
    else {
      rect.x = initX;
      rect.y = initY;
      rect.w = initW;
      rect.h = initH;

      animationStatus = -1;
    }
  }

  void Shape::ToggleAnimation () {
    animationStatus = 0;
  }

  int Shape::getAnimationStatus () {
    return animationStatus;
  }

  void Shape::GrowAndMove (double delta) {
    if (animationStatus < speed / 2) {
      setWidth(1 + delta * speed);
      setHeight(1 + delta * speed);
      setX(-0.2 + delta * speed);
      setY(-0.2 + delta * speed);
    } else {
      setWidth(-1 + delta * speed);
      setHeight(-1 + delta * speed);
      setX(0.2 + delta * speed);
      setY(0.2 + delta * speed);
    }
  }

  void Shape::MoveLeft (double delta) {
    if (animationStatus < 1) {
      setHeight(50 + delta * speed);
      setWidth(50 + delta * speed);
    }

    if (animationStatus < speed - 15)  {
      setX(-1.5 + delta * speed);
    } else {
      setHeight(-0.5 + delta * speed);
      setWidth(-0.5 + delta * speed);
    }
  }

  void Shape::GrowLeft (double delta) {
    if (animationStatus < 1) {
      setHeight(50 + delta * speed);
    }

    if (animationStatus < speed -1) {
      setWidth(2 + delta * speed);
    }
  }
}
