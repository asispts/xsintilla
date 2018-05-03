#include "XojoGraphics.h"

void graphics_SetForeColor(REALgraphics g, RBColor c)
{
    REALSetPropValueColor(g, "ForeColor", c);
}

void graphics_FillRect(REALgraphics g, RBInteger x, RBInteger y, RBInteger width, RBInteger height)
{
    FillRectFunc fn = (FillRectFunc)REALLoadObjectMethod(
        g, "FillRect(X as Integer, Y as Integer, Width as Integer, Height as Integer)");
    if(fn)
        fn(g, x, y, width, height);
}

void graphics_DrawRect(REALgraphics g, RBInteger x, RBInteger y, RBInteger width, RBInteger height)
{
    DrawRectFunc fn = (DrawRectFunc)REALLoadObjectMethod(
        g, "DrawRect(X as Integer, Y as Integer, Width as Integer, Height as Integer)");
    if(fn)
        fn(g, x, y, width, height);
}
