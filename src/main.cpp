#include <iostream>
#include <stdexcept>
#ifdef WIN32
#include <windows.h>
#endif // WIN32
#include <SDL.h>
#include "engine/Render/App.h"

int main(int argc, char* argv[]) {
  using namespace Render;
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Failure to initialise SDL: " << SDL_GetError() << std::endl;
    return 1;
  }
  App* MainApp;
  try {
    MainApp = new App("Hello, World!", 1024, 768);
  }
  catch(const std::exception& ex) {
    std::cerr << "FATAL ERROR!:" << ex.what() << std::endl;
    return 1;
  }
  SDL_RendererInfo* info = new SDL_RendererInfo;
  if (SDL_GetRendererInfo(MainApp->getRenderer(), info) != 0) {
    std::cerr << "Failure to get render info!: " << SDL_GetError() << std::endl;
    delete info;
    delete MainApp;
    return 1;
  }
  std::cout << "Renderer: " << info->name << std::endl;
  std::cout << "Flags: " << info->flags << std::endl;
  std::cout << "Max Width: " << info->max_texture_width << std::endl;
  std::cout << "Max height: " << info->max_texture_height << std::endl;
  SDL_Delay(2000);
  delete info;
  delete MainApp;
  SDL_Quit();
  return 0;
}
