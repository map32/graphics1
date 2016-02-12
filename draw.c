#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw2(int always0, int conditional0, int always1, int flip, int dalways, int dconditional, int talways, int tconditional, screen s, color c){
  int D = talways+tconditional;
  int always = always0;
  int conditional = conditional0;
  if (!flip){
    while(always!=always1){
      plot(s,c,always,conditional);
      if (D>0){
	conditional += dconditional;
	D += tconditional;
      }
      always += dalways;
      D += talways;
    }
  } else {
    while(always!=always1){
      plot(s,c,conditional,always);
      if (D>0){
	conditional += dconditional;
	D += tconditional;
      }
      always += dalways;
      D += talways;
    }
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx,dy;
  int A = x1-x0;
  int B = -(y1-y0);
  if (B>0){ //5-8 octants flipped into 1-4
    int t = y1;
    y1 = y0;
    y0 = t;
    B = -B;
  }
  if (B<A && B<-A){ // 2,3
    if (A>=0){ // 2
      draw2(y0,x0,y1,1,1,1,2*B,A,s,c);
    } else { // 3
      draw2(y0,x0,y1,1,1,-1,2*B,A,s,c);
    }
  } else { //1,4
    if (A>=0){ // 1
      draw2(x0,y0,x1,0,1,1,2*A,B,s,c);
    } else { // 4
      draw2(y0,x0,y1,0,-1,1,2*A,B,s,c);
    }
  }
}
