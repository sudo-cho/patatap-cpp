#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <string>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>

#include "typemonster.hpp"
#include "monster.hpp"
#include "level.hpp"
#include "game.hpp"
#include "draw.hpp"
#include "player.hpp"
#include "camera.hpp"

using namespace std;
using namespace glimac;

#ifdef _WIN32
#include <windows.h>
int CALLBACK WinMain(
                     _In_ HINSTANCE hInstance,
                     _In_ HINSTANCE hPrevInstance,
                     _In_ LPSTR     lpCmdLine,
                     _In_ int       nCmdShow
                     )
#else
int main(int argc, char *argv[])
#endif
{
	// initialization
	Game game;

	Level level((string)"assets/level1.dml");

	glEnable(GL_DEPTH_TEST);

  Program program;

  GLuint locationMVPMatrix = 0, locationMVMatrix = 0, locationNormalMatrix = 0;
  GLint uTexture = 0;

  game.initProgram(&program, &locationMVPMatrix, &locationMVMatrix, &locationNormalMatrix, &uTexture);

  Camera camera(glm::vec2(level.begin.position.x, level.begin.position.y), 1);

  // Sphere sphere(1, 32, 16);
  // SphereDraw objectSphere(&sphere);

  //WallDraw wall1;
  PathDraw path;

	bool _continue = true;
	while(_continue){
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				_continue = false; // Leave the loop after this iteration
			}
		}

	camera.cameraMove(level);

    /* game draw objects*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*
	glm::mat4 MVMat = glm::translate (glm::mat4(1.f), glm::vec3(0.f,-1.f,-2.f));
	MVMat = glm::rotate(MVMat, 90.f, glm::vec3(1, 0, 0));

    wall1.drawWall(locationMVPMatrix, locationMVMatrix, locationNormalMatrix, MVMat);*/

    path.drawPath(locationMVPMatrix, locationMVMatrix, locationNormalMatrix, level, camera, uTexture);

    SDL_Delay(1000/60);
		SDL_GL_SwapWindow(game.window);
	}

  game.~Game();
  return 0;
}
