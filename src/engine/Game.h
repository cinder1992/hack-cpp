#ifndef _GAME_H
#define _GAME_H
#include <vector>
#include <SDL.h>

typedef struct {
  int ID[8];
  int Stat;
} gNode;

class _baseEnt {
  private:
    _baseEnt* parent;
    std::vector<_baseEnt*>* children;
    gNode* nodeInfo;
  public:
    _baseEnt();
    ~_baseEnt();

    virtual bool onTick(double);     //Run every time a tick occurs, sends the tick to it's children
    virtual bool onEvent(SDL_Event*);//Run every time an event occurs
};
#endif //_GAME_H
