#include "game.h"
#include "helpers/resource_manager.h"
#include "helpers/shader.h"
#include "shapes/defaultShape.h"

DefaultShape *ds;

Game::Game ()
{

}

Game::~Game () {
  delete ds;
}

void Game::init (Window &win) {
  ResourceManager::LoadShader("../../assets/shaders/vs.glsl", "../assets/shaders/fs.glsl", nullptr, "defaultRender");

  glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(win.m_width),
                                    static_cast<GLfloat>(win.m_height), 0.0f, -1.0f, 1.0f);

  ResourceManager::GetShader("defaultRender").SetMatrix4("projection", projection);

  Shader sh;
  sh = ResourceManager::GetShader("defaultRender");
  ds = new DefaultShape(sh);
}

void Game::update(GLfloat dt) {

}


void Game::processInput(GLfloat dt) {

}

void Game::render () {
  ds->drawShape(glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
