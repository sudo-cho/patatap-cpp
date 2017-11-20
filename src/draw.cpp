#include <GL/glew.h>
#include <GL/gl.h>
#include <glimac/common.hpp>
#include <glimac/glm.hpp>
#include <SDL2/SDL.h>

#include "draw.hpp"

using namespace glimac;

Vertex2DUV::Vertex2DUV(float x, float y, float u, float v)
    : position(x,y), texcoords(u,v)
    {}

ObjectDraw::ObjectDraw(){

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	GLfloat vertices[] = {
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.f, 0.5f
	};

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


  /* VERTEX ARRAY OBJECT */
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE, 2 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void ObjectDraw::drawObject(){
  glBindVertexArray(this->vao);

  glDrawArrays(GL_TRIANGLES,0,3);

  glBindVertexArray(0);
}

glm::mat3 translate(float tx, float ty) {
	glm::mat3 M = glm::mat3(glm::vec3(1,0,0), glm::vec3(0,1,0), glm::vec3(tx,ty,1));
	return M;
}

glm::mat3 scale(float tx, float ty) {
	glm::mat3 M = glm::mat3(glm::vec3(tx,0,0), glm::vec3(0,ty,0), glm::vec3(0,0,1));
	return M;
}

glm::mat3 rotate(float a) {
	glm::mat3 M = glm::mat3(glm::vec3(cos(a),-sin(a),0), glm::vec3(sin(a),cos(a),0), glm::vec3(0,0,1));
	return M;
}
