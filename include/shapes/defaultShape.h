#ifndef DEFAULTSHAPE_H
#define DEFAULTSHAPE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "helpers/shader.h"

#include <vector>

class DefaultShape {
public:
  DefaultShape(Shader &shader);
  ~DefaultShape();

  GLuint getVbo ();
  GLuint getVao ();
  std::vector<GLfloat> & getVertices ();

  void initShape();
  void drawShape(glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color);

private:
  GLuint vbo, vao;
  Shader shader;
  std::vector<GLfloat> vertices ;

  void setVertices (std::vector<GLfloat> & arrayVertices);
};

#endif
