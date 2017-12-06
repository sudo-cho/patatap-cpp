#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <iostream>
#include <SDL2/SDL.h>

#include "shapes/defaultShape.hpp"

DefaultShape::DefaultShape () {

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	GLfloat vertices[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.f, 0.5f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void DefaultShape::drawShape () {
  glBindVertexArray(this->vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}

DefaultShape::~DefaultShape () {
  glDisableVertexAttribArray(0);
  std::cout << "destructor called" << std::endl;
}
