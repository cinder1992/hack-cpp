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
    App(const char* title = "Default Window",
        int w = 800,
        int h = 600,
        int x = SDL_WINDOWPOS_UNDEFINED,
        int y = SDL_WINDOWPOS_UNDEFINED,
        uint32_t WinFlags = SDL_WINDOW_SHOWN,
        uint32_t RenFlags = SDL_RENDERER_ACCELERATED
        );
    ~App();
    SDL_Window* getWindow(void);
    SDL_Renderer* getRenderer(void);
    private:
    SDL_Window* AppWin;
    SDL_Renderer* AppRender;
};
}
#endif
