#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glimac/common.hpp>

using namespace glimac;

struct Vertex2DUV{
  glm::vec2 position, texcoords;
  Vertex2DUV(float x, float y, float u, float v);
};

class ObjectDraw{
public:
  GLuint vbo, vao;

  ObjectDraw();

  void drawObject();
};

class WallDraw{
public:
  GLuint vbo, vao;
  glm::mat4 ProjMatrix, MVPMatrix, MVMatrix, NormalMatrix;
  static GLuint tex;
  static GLuint texP;
  static size_t refcount;

  WallDraw();
  ~WallDraw();

  void drawWall(GLuint, GLuint, GLuint, glm::mat4, GLint);
  void drawPathWall(GLuint, GLuint, GLuint, glm::mat4, GLint);

};
