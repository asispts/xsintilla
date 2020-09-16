#ifndef XOJO_GRAPHIC_H
#define XOJO_GRAPHIC_H

#include "rb_plugin.h"

// Graphics properties
void graphics_SetForeColor(REALgraphics, RBColor);

// Graphics functions definition
typedef void (*FillRectFunc)(REALgraphics, RBInteger, RBInteger, RBInteger, RBInteger);
typedef void (*DrawRectFunc)(REALgraphics, RBInteger, RBInteger, RBInteger, RBInteger);

// Graphics functions
void graphics_FillRect(REALgraphics, RBInteger, RBInteger, RBInteger, RBInteger);
void graphics_DrawRect(REALgraphics, RBInteger, RBInteger, RBInteger, RBInteger);

#endif  // XOJO_GRAPHIC_H
