#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "display.h"

class Graphics: public Display {
public:
  Graphics(Game &game);
  ~Graphics();
  
};

#endif
