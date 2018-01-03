#pragma once

#include <iostream>
#include <SDL2/SDL.h>

namespace patatap {
  class Shape {
  public:
    Shape(double tPosX, double tPosY, double tWidth, double tHeight, int tNumber);
    Shape(double tPosX, double tPosY, double tWidth, int tNumber);

    virtual ~Shape() = 0;

    virtual void InitShape();
    SDL_Rect GetShape() const;

    void setWidth(const double tWidth);
    void setHeight(const double tHeight);
    void setX (const double tX);
    void setY (const double tY);

    int getAnimationStatus();
    void InitAnimation(double delta);
    void ToggleAnimation();

    // All animations are naive procedures, they are neither randomly generated
    // neither coded in a beautiful way
    void GrowAndMove(double delta);
    void MoveLeft(double delta);
    void GrowLeft (double delta);

    template<typename Type> Type operator+(const Type &nShape) {return Type(xPos, yPos, width + nShape.width, height + nShape.height, animationNumber);}

  protected:
    SDL_Rect rect;
    double xPos, yPos, width, height;
    double initX, initY, initW, initH, speed{150};
    int animationNumber, animationStatus = -1;
  };
}
