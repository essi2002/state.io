#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "engine.h"
#include "AI.h"


void color_rand(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[])
{
    for(int i = 1; i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) - 1 ;i++)
   {
      for(int j = 1; j < ((SCREEN_HEIGHT / (2 * r)) )  - 1  ;j++)
      {
        
                one[0].color_arr[i][j] = 0x66333333;
                one[0].c[i][j] = '0';
              
     }
   }

          
}

void color_rand2(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[])
{
    for(int i = 0; i < ((SCREEN_WIDTH / (2 * r) - 3));i++)
   {
      for(int j = 1; j < ((SCREEN_HEIGHT / (2 * r)) )  - 2 ;j++)
      {
        
                one[0].color_arr[i][j] = 0x66333333;
                one[0].c[i][j] = '0';
              
     }
   }
     for(int i = ((SCREEN_WIDTH / (2 * r) - 3) ) + 1; i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) -1 ;i++)
   {
      for(int j = 1; j < ((SCREEN_HEIGHT / (2 * r)) )  - 1  ;j++)
      {
        
                one[0].color_arr[i][j] = 0x66333333;
                one[0].c[i][j] = '0';
              
     }
   }
          
}


void color_rand3(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[])
{
    for(int i = 1; i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) - 1 ;i++)
   {
      for(int j = 1; j < ((SCREEN_HEIGHT / (2 * r)) )  - 1  ;j++)
      {
        
                one[0].color_arr[i][j] = 0x66333333;
                one[0].c[i][j] = '0';
              
     }
   }

          
}



void draw_polygonon_place(int a,Sint16 x0,Sint16 y0,SDL_Renderer *sdlRenderer,Uint32 color,int lenght)
{
   
 short * array_x = (short *)malloc(a * sizeof(short));
  short * array_y = (short *)malloc(a * sizeof(short));
  boxes(array_x,array_y,x0,y0,lenght,a);
  filledPolygonColor(sdlRenderer,array_x,array_y,a,color);
}




void color_randmemory(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[])
{
    for(int i = 1; i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) - 1 ;i++)
   {
      for(int j = 1; j < ((SCREEN_HEIGHT / (2 * r)) )  - 1  ;j++)
      {
        
                one[0].color_arr[i][j] = 0xccffd62b;
                one[0].c[i][j] = 'B';
              
     }
   }

          
}
