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
#include <time.h>
#include <string.h>
#include "AI.h"
void showimg(SDL_Renderer * sdlRenderer,char * str,int x0,int y0,int w0,int h0)
{
   SDL_Surface * image = IMG_Load(str);
   if(image == NULL)
   {
      printf("%s\n",str);
        fprintf(stderr, "error: image1 not found\n");
        exit(EXIT_FAILURE);
   }
   SDL_Texture * text = SDL_CreateTextureFromSurface(sdlRenderer,image);
   SDL_FreeSurface(image);
   image = NULL;
   SDL_Rect t_rect = {.x = x0,.y = y0,.w = w0,.h = h0};
   SDL_RenderCopy(sdlRenderer,text,NULL,&t_rect);
   SDL_DestroyTexture(text);
}

void showimg2(SDL_Renderer * sdlRenderer,char * str,int x0,int y0,int w0,int h0)
{
   SDL_Surface * image = SDL_LoadBMP(str);
   if(image == NULL)
   {
       printf("%s\n",str);
        fprintf(stderr, "%serror: image 2not found\n",str);
        exit(EXIT_FAILURE);
   }
   SDL_Texture * text = SDL_CreateTextureFromSurface(sdlRenderer,image);
   SDL_FreeSurface(image);
   image = NULL;
   SDL_Rect t_rect = {.x = x0,.y = y0,.w = w0,.h = h0};
   SDL_RenderCopy(sdlRenderer,text,NULL,&t_rect);
   SDL_DestroyTexture(text);
}

void potionsion(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct potion potions[],struct region num[20][20])
{
      srand(time(0));
      switch(rand() % 16)
      {
         case 0:
         if(potions[0].is_push == false)
         {
            potions[0].is_push = true;
           int i_c = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2 - 2) ;
           int j_c = rand() % (SCREEN_HEIGHT / (2 * r) - 2) ;
           potions[0].pos_x = (num[i_c][j_c].x_pos - 60) + rand() % 100;
           potions[0].pos_y = (num[i_c][j_c].y_pos - 60) + rand() % 100;
          strcpy(potions[0].str,"sarbaz3.bmp");
         }
         break;
         
         case 2:
         if(potions[1].is_push == false)
         {
               potions[1].is_push = true;
           int i_c = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2 - 2) + 1;
           int j_c = rand() % (SCREEN_HEIGHT / (2 * r) - 2) + 1;
           potions[1].pos_x = (num[i_c][j_c].x_pos - 60) + rand() % 100;
           potions[1].pos_y = (num[i_c][j_c].y_pos - 60) + rand() % 100;
           strcpy(potions[1].str,"sarbaz2.bmp");
         }
         break;

         case 4:
         if(potions[2].is_push == false)
         {
                potions[2].is_push = true;
           int i_c = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2 - 2) + 1;
           int j_c = rand() % (SCREEN_HEIGHT / (2 * r) -  2) + 1;
           potions[2].pos_x = (num[i_c][j_c].x_pos - 60) + rand() % 100;
           potions[2].pos_y = (num[i_c][j_c].y_pos - 60) + rand() % 100;
           strcpy(potions[2].str,"sarbaz1.bmp");
         }
         break;


         case 6:
         if(potions[3].is_push == false)
         {
               potions[3].is_push = true;
           int i_c = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2 - 2) + 1;
           int j_c = rand() % (SCREEN_HEIGHT / (2 * r) -2 ) + 1;
           potions[3].pos_x = (num[i_c][j_c].x_pos - 60) + rand() % 100;
           potions[3].pos_y = (num[i_c][j_c].y_pos - 60) + rand() % 100;
           strcpy(potions[3].str,"sarbaz4.bmp");
         }
         break;


      }
}
 
void checkPOT(struct potion potions[],SDL_Renderer * sdlRenderer)
{
  for(int i = 0; i < 4;i++)
  {
     if(potions[i].is_push == true && potions[i].time == 0)
     {
        showimg2(sdlRenderer,potions[i].str,potions[i].pos_x,potions[i].pos_y,30,30);

     }
     else if(potions[i].is_push == true && potions[i].time >  0)
     {
         showimg2(sdlRenderer,potions[i].str,potions[i].pos_x,potions[i].pos_y,42,42);
     }
  }
}


void sarbaz1(struct region num[20][20],int i,int j,struct potion potions[],int s)
{
   if(potions[s].time == 0)
   {
    // num[i][j].radius = 16;
      for(int l = 0; l <= 2;l++)
      {
      num[i][j].vx[l] *= 2;
      num[i][j].vy[l] *= 2;
      }
   }
   potions[s].time++;
}

void sarbaz2(struct region num[20][20],int i,int j,struct potion potions[],int s,struct color_militaries one[])
{
 if(potions[s].time == 0)
   {
    //  num[i][j].radius = 16;
       for(int a = 0; a < 7; a++)
       {
          for(int b = 0 ; b < 7 ;b++)
          {
                if(a != i && b != j && one[0].c[a][b] != one[0].c[i][j])
                {
                    for(int l = 0; l <= 2;l++)
                     {
                          num[a][b].copy_vx[l] = num[a][b].vx[l];
                          num[a][b].copy_vy[l] = num[a][b].vy[l];
                          num[a][b].vx[l] = 0;
                          num[a][b].vy[l] = 0;
                          
                     }
                   
                }
          }
       }
   }
    potions[s].time++;
}

void release_sarbaz2(struct region num[20][20],int i,int j,struct potion potions[],int s,struct color_militaries one[])
{
 for(int a = 0; a < 7; a++)
       {
          for(int b = 0 ; b < 7 ;b++)
          {
                if(a != i && b != j && one[0].c[a][b] != one[0].c[i][j])
                {
                    for(int l = 0; l <= 2;l++)
                     {
                        
                         
                          num[a][b].vx[l] =  num[a][b].copy_vx[l];
                          num[a][b].vy[l] = num[a][b].copy_vy[l];
                          
                     }
                   
                }
          }
       }
}


void sarbazkhoneh1(struct region num[20][20],int i,int j,struct potion potions[],int s)
{
  if(potions[s].time == 0)
  {
     
     num[i][j].increase = true;
    
  }
  potions[s].time++;
}




void sarbazkhoneh2(struct region num[20][20],int i,int j,struct potion potions[],int s)
{
if(potions[s].time == 0)
{
   //num[i][j].radius = 16;
   num[i][j].fac_inc = 2;
}
potions[s].time++;
}


void go_for_potoion(struct potion potions[],struct region num[20][20],struct color_militaries one[])
{
                      for(int i = 0; i < 10;i++)
                      {
                         for(int j = 0; j < 10;j++)
                         {
                              if(one[0].index_potion[i][j] == 1)
                              {
                                 int s = one[0].number_ofpotion[i][j];
                                 switch(s)
                                 {
                                    case 0:
                                    if(potions[s].time <= 5)
                                    {
                                         sarbaz1(num,i,j,potions,s);

                                    }
                                    else
                                    {
                                          potions[s].is_push = false;
                                          potions[s].time = 0;
                                          num[i][j].radius = 10;
                                          //num[i][j].factor = 1;
                                          one[0].index_potion[i][j] = 0;
                                         for(int l = 0;s <= l;s++)
                                        {
                                            num[i][j].vx[l] = num[i][j].vx[l] / 2;
                                            num[i][j].vy[l] = num[i][j].vy[l] / 2;
                                        }
                                    }
                                    break;

                                    case 1:
                                        
                                          if(potions[s].time <= 5)
                                         {
                                             sarbaz2(num,i,j,potions,s,one);
                                         }
                                          else
                                          {
                                              potions[s].is_push = false;
                                               potions[s].time = 0;
                                             num[i][j].radius = 10;
                                              one[0].index_potion[i][j] = 0;
                                             release_sarbaz2(num,i,j,potions,s,one);
                                           }
                                    break;

                                    case 2:
                                               if(potions[s].time <= 5)
                                               {
                                                      sarbazkhoneh1(num,i,j,potions,s);
                                               }
                                              else
                                              {
                                       //          num[i][j].factor = 1;
                                                 potions[s].time = 0;
                                                 potions[s].is_push = false;
                                                 num[i][j].increase = false;
                                                 one[0].index_potion[i][j] = 0;
                                                 num[i][j].radius = 10;
                                              }
                                    break;


                                    case 3:
                             if(potions[s].time <= 5)
                              {
                             sarbazkhoneh2(num,i,j,potions,s);
                              }
                              else
                              {
                                 potions[s].time = 0;
                                 potions[s].is_push = false;
                                 //num[i][j].factor = 1;
                                 num[i][j].fac_inc = 1;
                                 one[0].index_potion[i][j] = 0;
                                 num[i][j].radius = 10;
                              }
                                    break;
                                 }
                              }
                         }
                      }
}


void to_check_on_potion(struct potion potions[],struct region num[20][20],struct color_militaries one[])
{
    for(int s = 0; s < 4;s++)
    {
     if(potions[s].is_push == true)
     {
         for(int i = 0; i < 20;i++)
         {
            for(int j = 0; j < 20;j++)
            {
               for(int l = 0; l <= 2;l++)
               {
                  if(num[i][j].is_attack[l] == true || num[i][j].is_move[l] == true)
                   {
                      for(int p = 0; p < num[i][j].minus[l];p++)
                      {
                         if(one[0].index_potion[i][j] == 0  && ((num[i][j].x_soldier[l][p] - potions[s].pos_x - 15) * (num[i][j].x_soldier[l][p] - potions[s].pos_x - 15) + (num[i][j].y_soldier[l][p] - potions[s].pos_y - 15) * (num[i][j].y_soldier[l][p] - potions[s].pos_y - 15) <= 110))
                         {
                               for(int copy_i = 0; copy_i < 20;copy_i++)
                               {
                                  for(int copy_j = 0; copy_j < 20;copy_j++)
                                  {
                                     if(one[0].c[copy_i][copy_j] == one[0].c[i][j])
                                     {
                                        one[0].index_potion[copy_i][copy_j] = 1;
                                        one[0].number_ofpotion[copy_i][copy_j] = s;
                                        num[copy_i][copy_j].radius = 16;
                                     }

                                  }
                               }
                               return;
                         }
                      }
                   }
               }
            }
         }

     }
  }
}


                         