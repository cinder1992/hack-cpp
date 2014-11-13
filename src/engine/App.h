#ifndef _APP_H
#define _APP_H
#include <SDL.h>
#include <stdint.h>
/* App class
 * Description:
 *    This class handles SDL_Window and SDL_Renderer calls, as well as handling events.
 * 
 * FunctionDef:
 *  App:
 *    Takes: Int*4 (Xpos, Ypos, Width, Height), const char* Title, uint32_t Window Flags, uint32_t Render flags
 *  The constructor passes these arguments to SDL_CreateWindow and SDL_CreateRenderer.
 *
 */
namespace Render {
class App {
  public:
    App(int, int, int, int, const char*, uint32_t, uint32_t);
    ~App();
    SDL_Window* getWindow(void);
    SDL_Renderer* getRenderer(void);
    private:
    SDL_Window* AppWin;
    SDL_Renderer* AppRender;
};
}
#endif
