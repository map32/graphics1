#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void plot2(int flip, screen s, color c, int always, int conditional){
  if (!flip){
    plot(s,c,always,conditional);
  } else {
    plot(s,c,conditional,always);
  }
}

void draw2(int always0, int conditional0, int always1, int flip, int dalways, int dconditional, int talways, int tconditional, screen s, color c){
  int D = talways+tconditional/2;
  printf("%d %d %d",talways,tconditional,D);
  int always = always0;
  int conditional = conditional0;
  if(!flip){
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
      if (D<0){
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
  int A = 2*(y1-y0);
  int B = 2*(-(x1-x0));
  printf("d");
  if (A<0){ //5-8 octants flipped into 1-4
    int t = y1;
    y1 = y0;
    y0 = t;
    t = x1;
    x1 = x0;
    x0 = t;
    printf("%d %d",x0,x1);
    A = -A;
    B = -B;
  }
  if (A>B && A>-B){ // 2,3
    if (B<0){ // 2
      printf("2");
      //draw2(x0,y0,x1,0,1,1,A,B,s,c);
      draw2(y0,x0,y1,1,1,1,B,A,s,c);
    } else { // 3
      printf("3");
      draw2(y0,x0,y1,1,1,-1,B,A,s,c);
    }
  } else { //1,4
    if (B<0){ // 1
      plot(s,c,100,200);
      printf("1\n");
      draw2(x0,y0,x1,0,1,1,A,B,s,c);
    } else { // 4
      printf("4f");
      draw2(x0,y0,x1,0,-1,1,A,B,s,c);
    }
  }
}
