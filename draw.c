#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw2(int always0, int conditional0, int always1, int flip, int dalways, int dconditional, int talways, int tconditional, screen s, color c){
  int D = talways+tconditional/2;
  //printf("%d %d %d",talways,tconditional,D);
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
    plot(s,c,always,conditional);
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
    plot(s,c,conditional,always);
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx,dy;
  int A = 2*(y1-y0);
  int B = 2*(-(x1-x0));
  //printf("d\n");
  if (A<0){ //5-8 octants flipped into 1-4
    int t = x1;
    x1 = x0;
    x0 = t;
    t = y1;
    y1 = y0;
    y0 = t;
    //printf("%d %d %d %d\n",x0,x1,y0,y1);
    B = -B;
    A = -A;
  }
  if (A>B && A>-B){ // 2,3
    if (B<0){ // 2
      //printf("2");
      //draw2(x0,y0,x1,0,1,1,A,B,s,c);
      draw2(y0,x0,y1,1,1,1,B,A,s,c);
    } else { // 3
      //printf("3");
      draw2(y0,x0,y1,1,1,-1,-B,A,s,c);
    }
  } else { //1,4
    if (B<0){ // 1
      //printf("1\n");
      draw2(x0,y0,x1,0,1,1,A,B,s,c);
    } else { // 4
      //printf("4\n");
      draw2(x0,y0,x1,0,-1,1,A,-B,s,c);
    }
  }
}

void rectangle(int x0, int y0, int x1, int y1, screen s, color c){
  draw_line(x0,y0,x1,y0,s,c);
  draw_line(x1,y0,x1,y1,s,c);
  draw_line(x1,y1,x0,y1,s,c);
  draw_line(x0,y1,x0,y0,s,c);
}

void radiance(int x0, int y0, int x1, int y1, screen s, color c){
  int q = 0; // 0:normal 1:yflip 2:xflip 3:xyflip
  if (x0<x1){
    if (y0<y1){
    } else {
      q = 1;
    }
  } else {
    if (y0<y1){
      q = 2;
    } else {
      q = 3;
    }
  }
  int i=0;
  for(i;i<8;i++){
    if (q>0){
      y0 += 1;
      y1 -= 1;
    } else {
      y0 -= 1;
      y1 += 1;
    }
    if (q>1){
      x0 += 1;
      x1 -= 1;
    } else {
      x0 -= 1;
      x1 += 1;
    }
    c.red = c.red*4/5;
    c.blue = c.blue*4/5;
    c.green = c.green*4/5;
    rectangle(x0,y0,x1,y1,s,c);
  }
}

void randomy(screen s){
  color c;
  srand(time(NULL));
  int x;
  int y;
  c.red = rand()%256;
  c.green = rand()%256;
  c.blue = rand()%256;
  int i = 0;
  for(i;i<50;i++){
    x = rand()%XRES;
    y = rand()%YRES;
    c.red = rand()%256;
    c.green = rand()%256;
    c.blue = rand()%256;
    radiance(x,y,x+20,y+20,s,c);
  }
  
}
