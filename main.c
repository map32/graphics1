#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);


  //octant 1
  //draw_line( 0, 0, YRES-75, XRES-1,s,c);
  //draw_line( 0, 0,100, 50, s, c);
  //octant 2
  //draw_line(0,0,YRES-1,XRES-75,s,c);
  //draw_line( 0, 0, 50, 100, s, c); 
  //octant 8
  //draw_line( 0, YRES-1, XRES-1, 75, s, c);
  //draw_line(250,250,499,200,s,c);
  //draw_line( 0, YRES-1, XRES-1, 75, s, c);
  //octant 7
  //draw_line( 0, YRES-1, XRES - 75, 0, s, c);

  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  //draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  //octant 6
  //draw_line( XRES - 1, YRES -1, 75, 0, s, c);
  //octant 4
  //draw_line( XRES - 1, 0, 0, YRES - 75, s, c);
  //octant 3
  //draw_line( XRES - 1, 0, 75, YRES - 1, s, c);
  
  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  //draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  //draw_line( 0, YRES - 1, XRES - 1, 0, s, c);

  //horizontal, vertical line
  //draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  //draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);

  randomy(s);
  
  c.red = 255;
  c.blue = 180;
  c.green = 105;
  radiance(70,100,90,400,s,c);
  radiance(100,250,190,270,s,c);
  radiance(200,270,220,100,s,c);
  c.red = 255;
  c.blue = 203;
  c.green = 193;
  radiance(280,100,300,350,s,c);
  radiance(280,380,300,400,s,c);
  c.red = 255;
  c.blue = 147;
  c.green = 20;
  radiance(340,100,360,120,s,c);
  radiance(340,140,360,400,s,c);
  //radiance(300,400,100,100,s,c);
  
  display(s);
  save_extension(s, "lines.png");
}  
