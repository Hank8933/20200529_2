#include <stdio.h>
#include <stdlib.h>

struct color { int red, green, blue; };

struct color make_color(int red, int green, int blue)
{
    struct color c = { red, green, blue };
    c.red   = red   < 0 ? 0 : red   > 255 ? 255 : red;
    c.green = green < 0 ? 0 : green > 255 ? 255 : green;
    c.blue  = blue  < 0 ? 0 : blue  > 255 ? 255 : blue;
    return c;
}

int getRed(struct color c)
{
    return c.red;
}

int equal_color(struct color color1, struct color color2)
{
    if (color1.red   == color2.red   &&
        color1.green == color2.green &&
        color1.blue  == color2.blue)
        return 1;
    else return 0;
}

#define colFun(tag, op)\
struct color tag(struct color c)\
{\
    if (c.red == 0 && c.green == 0 && c.blue == 0)\
        return (struct color) { 3, 3, 3 };\
    c.red   = ((c.red   > 0 && c.red   < 3) ? 3 : c.red  ) op 0.7;\
    c.green = ((c.green > 0 && c.green < 3) ? 3 : c.green) op 0.7;\
    c.blue  = ((c.blue  > 0 && c.blue  < 3) ? 3 : c.blue ) op 0.7;\
    if (c.red   > 255) c.red   = 255;\
    if (c.green > 255) c.green = 255;\
    if (c.blue  > 255) c.blue  = 255;\
    return c;\
}

colFun(brighter, /)

colFun(darker, *)

int main()
{
    struct color c = {0, 3 ,255};
    printf("%d\n", darker(c).blue);
    return 0;
}
