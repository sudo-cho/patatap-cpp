#ifdef __APPLE__
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#endif

class DefaultShape {

public:
  GLuint vbo, vao;

  DefaultShape();
  ~DefaultShape();

  void drawShape();
};
