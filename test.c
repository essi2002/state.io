#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include "engine.h"
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "AI.h"



const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
Sint16 x_0 = 100;
Sint16 y_0 = 60;
int r = 60;


int main()
{
  
   if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
      {
           printf("%s",SDL_GetError());
           return 0;
      }
      char ptr[35];
      strcpy(ptr," ");
     struct name_order class[50];
      struct color_militaries one[1];
      struct region num[20][20];
      struct potion potions[4];
     

       for(int l = 0; l < 20;l++)
      {
           for(int s = 0; s < 20;s++)
           {
                one[0].c[l][s] = 'm';
           }
      }
      TTF_Init();
      SDL_Window * sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
      SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
      username(ptr,sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
     char new_username[35];
      memcpy(new_username,&ptr[1],strlen(ptr) - 1);
      ptr[strlen(ptr)] = '\0';
     
      int ind_of_menu =  show_menu(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
      printf("%d\n",ind_of_menu);
     switch(ind_of_menu)
     {
          case 2:
          leaderboard(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
          break;
          case 1:
          upload_game(num,one,potions);
          new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
          
          break;
          case 0:
          switch(map_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT))
          {
               case 0:
               switch(show_maps_in(sdlRenderer))
               {
                    case 0:
                    already_make_map1(one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                           potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
    
                    break;
                    case 1:
                    already_make_map2(one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                           potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
    
                    break;
                    case 2:
                    already_make_map3(one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                           potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
   
                    break;
               }
               
               break;
               case 1:
               switch(show_save_randomampe(sdlRenderer))
               {
                    case 0:
                    random_map(one,SCREEN_WIDTH,SCREEN_HEIGHT,r,true);
                           potions[0].is_push = false;
                           potions[0].time = 0;
                           potions[1].is_push = false;
                           potions[1].time = 0;
                           potions[2].is_push = false;
                           potions[2].time = 0;
                           potions[3].is_push = false;
                           potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
    leaderboard(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                    break;
                    case -1:
                    random_map(one,SCREEN_WIDTH,SCREEN_HEIGHT,r,true);
                           potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
    leaderboard(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                    break;
               }
               
               break;
               case 2:
               saved_random_map(one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                      potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
    
               break;
               case 3:
               memory_mangement(one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
               potions[0].is_push = false;
                potions[0].time = 0;
                potions[1].is_push = false;
                potions[1].time = 0;
                potions[2].is_push = false;
                potions[2].time = 0;
                potions[3].is_push = false;
                potions[3].time = 0;
      
    
    for(int i = 0; i < 20;i++)
    {
      for(int j = 0 ; j < 20 ;j++)
      {
     switch(one[0].c[i][j])
     {
          case 'G':
          num[i][j].radius = 10;
          break;
          case 'R':
          num[i][j].radius = 10;
          break;
          case 'P':
          num[i][j].radius = 10;
          break;

          case 'B':
          num[i][j].radius = 10;
          break;
          case '0':
           num[i][j].radius = 10;
          break;

     }
        num[i][j].soldiers = 50;
       
        one[0].index_potion[i][j] = 0;
        num[i][j].increase = false;
        num[i][j].factor = 1;
        num[i][j].fac_inc = 1;
        for(int l = 0; l <= 2;l++)
       {
        num[i][j].vx[l] = 0;
        num[i][j].vy[l] = 0;
         num[i][j].minus[l] = 4;
        num[i][j].is_move[l]= false;
        num[i][j].is_attack[l] = false;
        for(int s = 0; s < 400;s++)
        {
             num[i][j].soldier[l][s] = true;
             num[i][j].isto_plus[l][s] = true;
             num[i][j].is_continue[l][s] = true;
             
        }
        
       }
      }
    }
    new_game(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0,one,class,num,potions,new_username);
  
               break;
         
    
          }
           
          break;
          
     }
     
  TTF_Quit();
  SDL_DestroyWindow(sdlWindow);
  SDL_Quit();
  
  return 0;
}