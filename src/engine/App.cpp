#include <SDL.h>
#include "App.h"
#include <stdint.h>
#include <iostream>
#include <stdexcept>

namespace Render {
App::App(const char* title, int w, int h, int x, int y, uint32_t WinFlags, uint32_t RenFlags) {
  
  AppWin = SDL_CreateWindow(title, x, y, w, h, WinFlags);
  
  if (AppWin == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  AppRender = SDL_CreateRenderer(AppWin, -1, RenFlags);

  if (AppRender == nullptr) {
    SDL_DestroyWindow(AppWin);
    throw std::runtime_error(SDL_GetError());
  }
}

App::~App() {
  SDL_DestroyRenderer(AppRender);
  SDL_DestroyWindow(AppWin);
}

SDL_Window* App::getWindow(void) {
  return AppWin;
}

SDL_Renderer* App::getRenderer(void) {
  return AppRender;
}
}
