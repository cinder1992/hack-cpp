#ifndef _RENDERABLE_H
#define _RENDERABLE_H

namespace Render {
class Renderable {
  public:
    virtual void draw() = 0;
    virtual bool isVisible();
  protected:
    bool visibility = true;
};
}
#endif //_RENDERABLE_H
