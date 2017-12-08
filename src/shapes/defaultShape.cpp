#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#include <iostream>
#include <SDL2/SDL.h>

#include "shapes/defaultShape.hpp"

DefaultShape::DefaultShape (std::vector<GLfloat> &t_vertices) {

  setVertices(t_vertices);

	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size(), (GLvoid *)vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void DefaultShape::drawShape () {
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}

DefaultShape::~DefaultShape () {
  glDisableVertexAttribArray(0);
  std::cout << "destructor called" << std::endl;
}

GLuint DefaultShape::getVbo () {
  return vbo;
}

GLuint DefaultShape::getVao () {
  return vao;
}

std::vector<GLfloat> &DefaultShape::getVertices () {
  return vertices;
}

void DefaultShape::setVertices (std::vector<GLfloat> & arrayVertices) {
  this->vertices = arrayVertices;
}
