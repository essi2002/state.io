#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "engine.h"
#include <stdbool.h>
#include "AI.h"
void boxes(short * array_x,short * array_y,Sint16 x0,Sint16 y0,int r,int a)
{
  
  float theta = 0;
  for(int i = 0; i < a;i++)
  {
    array_x[i] = x0 + r * cos(theta);
    array_y[i] = y0 - r * sin(theta);
    theta +=  2 * M_PI / a;
  }
}

void draw_line(short * array_x,short * array_y,SDL_Renderer *sdlRenderer)
{
  for(int i = 0; i < 5;i++)
  {
    SDL_RenderDrawLine(sdlRenderer,array_x[i],array_y[i],array_x[i + 1],array_y[i + 1]);
  }
  SDL_RenderDrawLine(sdlRenderer,array_x[5],array_y[5],array_x[0],array_y[0]);
}

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text) 
{
    TTF_Font *font = TTF_OpenFont("Lato-Light.ttf", 14);
  if (font == NULL) 
    {
        fprintf(stderr, "error: font3 not found\n");
        exit(EXIT_FAILURE);
    }
     SDL_Rect rect;
   

    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {0, 0, 0, 255};

    
    surface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect.x = x;
    rect.y = y;
    rect.w = text_width;
    rect.h = text_height;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}


void get_text_and_rect2(SDL_Renderer *renderer, int x, int y, char *text) 
{
    TTF_Font *font = TTF_OpenFont("Roboto-BoldItalic.ttf", 20);
  if (font == NULL) 
    {
        fprintf(stderr, "error: font3 not found\n");
        exit(EXIT_FAILURE);
    }
     SDL_Rect rect;
   

    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {10, 10, 10, 255};

    
    surface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect.x = x;
    rect.y = y;
    rect.w = text_width;
    rect.h = text_height;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}


void drawn_hexagonal(short * array_x,short * array_y,int r,Sint16 x0,Sint16 y0,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer *sdlRenderer,struct color_militaries  one[2],struct region num[20][20])
{
  
  Sint16 pess = x0;
  
  for(int i = 0; i < SCREEN_WIDTH / (2 * r) - 3 ;i++)
  {
      Sint16 copy = y0;
      
      for(int j = 0; j < SCREEN_HEIGHT / (2 * r)  ;j++)
      {
        
           switch(one[0].c[i][j])
           {
             case 'G':
            boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xff00ffff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
            
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
              
              draw_line(array_x,array_y,sdlRenderer);   
              draw_line(array_x,array_y,sdlRenderer);
             break;
             case 'B':
             boxes(array_x,array_y,pess,copy,r,6);
             filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
             filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xccff3434);
             SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
             sprintf(num[i][j].str,"%d",num[i][j].soldiers);
             get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
        
             draw_line(array_x,array_y,sdlRenderer);  
             draw_line(array_x,array_y,sdlRenderer);
              break;

             case 'P':
             boxes(array_x,array_y,pess,copy,r,6);
             filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
             draw_polygonon_place(3,pess,copy,sdlRenderer,0xffff5555,num[i][j].radius);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
            
             get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
             
              draw_line(array_x,array_y,sdlRenderer);  
              draw_line(array_x,array_y,sdlRenderer);

              break;

             case 'R' :
              boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xffffffff);
              filledCircleColor(sdlRenderer,pess +5,copy,num[i][j].radius / 2,0xaaec6fff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
             get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
              
              draw_line(array_x,array_y,sdlRenderer);  
              draw_line(array_x,array_y,sdlRenderer);
              break;

              case '0':
              boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,12,0xffffffff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
             
              draw_line(array_x,array_y,sdlRenderer);  
              draw_line(array_x,array_y,sdlRenderer);
              break;
           }
              
             copy += 2 * r * cos(M_PI / 6);
            


      }
     pess += 3 * r;
     
  }


  pess = x0 + 3 * r / 2;
  for(int i = SCREEN_WIDTH / (2 * r) - 3; i < ((SCREEN_WIDTH / (2 * r) - 3)* 2)  ;i++)
  {
      Sint16 copy = y0 + r * cos(M_PI / 6);
      
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
        
          switch(one[0].c[i][j])
           {
             case 'G':
             boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xff00ffff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);      
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
              
              draw_line(array_x,array_y,sdlRenderer);   
              draw_line(array_x,array_y,sdlRenderer);
             
             break;
             case 'B':
              boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xccff3434);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
            
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
             
              draw_line(array_x,array_y,sdlRenderer);   
              draw_line(array_x,array_y,sdlRenderer);
              break;

             case 'P':
             boxes(array_x,array_y,pess,copy,r,6);
             filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
             draw_polygonon_place(3,pess,copy,sdlRenderer,0xffff5555,num[i][j].radius);
             SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
             sprintf(num[i][j].str,"%d",num[i][j].soldiers);
             
             get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
             
             draw_line(array_x,array_y,sdlRenderer);  
             draw_line(array_x,array_y,sdlRenderer);
             break;

             case 'R' :
              boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,num[i][j].radius,0xffffffff);
              filledCircleColor(sdlRenderer,pess +5,copy,num[i][j].radius / 2,0xaaec6fff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
             
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
              
              draw_line(array_x,array_y,sdlRenderer);  
              draw_line(array_x,array_y,sdlRenderer);
              break;

              case '0':
              boxes(array_x,array_y,pess,copy,r,6);
              filledPolygonColor(sdlRenderer,array_x,array_y,6,one[0].color_arr[i][j]);
              filledCircleColor(sdlRenderer,pess,copy,12,0xffffffff);
              SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
              sprintf(num[i][j].str,"%d",num[i][j].soldiers);
              get_text_and_rect(sdlRenderer,pess,copy + 15,num[i][j].str);
              
              draw_line(array_x,array_y,sdlRenderer);  
              draw_line(array_x,array_y,sdlRenderer);
              break;
           }
          
          copy += 2 * r * cos(M_PI / 6);
         
      }
     pess += 3 * r;
     
  }
}