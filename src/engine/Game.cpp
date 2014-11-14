#include <iostream>
#include <SDL.h>
#include "Game.h"

bool _baseEnt::onTick(double dt) {
  for(std::vector<_baseEnt*>::iterator it = children->begin(); it != children->end(); ++it) {
    if((*it)->onTick(dt) != true) return false;
  }
  return true;
}

bool _baseEnt::onEvent(SDL_Event* e) {
  for(std::vector<_baseEnt*>::iterator it = children->begin(); it != children->end(); ++it) {
    if((*it)->onEvent(e) != true) return false;
  }
  return true;
}
