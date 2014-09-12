#include <iostream>
#include <stdexcept>
#ifdef WIN32
#include <windows.h>
#endif // WIN32
#include <SDL.h>
#include "App.h"

int main(int argc, char* argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Failure to initialise SDL: " << SDL_GetError() << std::endl;
    return 1;
  }
  App* MainApp;
  try {
    MainApp = new App(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, "Hello, World!", SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED);
  }
  catch(const std::exception& ex) {
    std::cerr << "FATAL ERROR!:" << ex.what() << std::endl;
    return 1;
  }
  SDL_Delay(2000);
  delete MainApp;
  SDL_Quit();
  return 0;
}
