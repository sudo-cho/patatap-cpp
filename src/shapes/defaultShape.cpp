#include "shapes/defaultShape.h"

DefaultShape::DefaultShape (Shader &shader) {
  this->shader = shader;
  this->initShape();
}

void DefaultShape::initShape () {
  std::vector<GLfloat> t_vertices = {
    -0.25f, -0.25f, 0.f,
    0.25f, -0.25f, 0.f,
    0.25f, 0.25f, 0.f
  };

  setVertices(t_vertices);

  glGenBuffers(1, &vbo);
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), (GLvoid *)vertices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DefaultShape::drawShape (glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color) {
  this->shader.Use();

  glm::mat4 model;
  model = glm::translate(model, glm::vec3(position, 0.0f));
  model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
  model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
  model = glm::scale(model, glm::vec3(size, 1.0f));

  this->shader.SetMatrix4("model", model);
  this->shader.SetVector3f("spriteColor", color);

  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}

DefaultShape::~DefaultShape () {
  glDeleteVertexArrays(1, &this->vao);
  glDisableVertexAttribArray(0);
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
  vertices = arrayVertices;
}
