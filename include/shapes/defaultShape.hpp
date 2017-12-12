#include <vector>

class DefaultShape {

private:
  GLuint vbo, vao;
  std::vector<GLfloat> vertices ;

  void setVertices (std::vector<GLfloat> & arrayVertices);

public:
  DefaultShape(std::vector<GLfloat> & t_vertices);
  ~DefaultShape();

  GLuint getVbo ();
  GLuint getVao ();
  std::vector<GLfloat> & getVertices ();

  void drawShape();
};
