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
#include "AI.h"

void moveforprotect(struct region num[20][20],struct color_militaries one[],char a)
{
  for(int i = 0;i < 10;i++)
   {
    for(int j = 10; j < 10;j++)
    {
        if(one[0].c[i][j] == a)
       {
           for(int s = 0 ; s<= 2;s++) 
           {
           if(num[i][j].is_attack[s] == true || num[i][j].is_move[s] == true)
           {
               for(int copy_i = 0; copy_i < 10;copy_i++)
               {
                   for(int copy_j = 0; copy_j < 10;copy_j++)
                   {
                       if(copy_i != num[i][j].i[s] && copy_j != num[i][j].j[s])
                       {
                           if(one[0].c[copy_i][copy_j] == one[0].c[num[i][j].i[s]][num[i][j].j[s]] &&one[0].c[copy_i][copy_j] != 'B')
                           {
                                 for(int s1= 0;s1 <= 2;s1++)
                                    {
                                         if(num[copy_i][copy_j].is_move[s1] == false &&  num[copy_i][copy_j].is_attack[s1] == false)
                                         {
                                              num[copy_i][copy_j].is_move[s1] = true;
                                               num[copy_i][copy_j].is_attack[s1] = true;
                                               num[copy_i][copy_j].i[s1] = i;
                                               num[copy_i][copy_j].j[s1] = j;
                                               set_move(num,copy_i,i,copy_j,j,s1);
                                              rate_seting(num,copy_i,i,copy_j,j,s1);
                                              num[copy_i][copy_j].is_torecieve[s1] = num[copy_i][copy_j].copy_soldier;
                                               num[copy_i][copy_j].copy_istorecieve[s1] = num[copy_i][copy_j].copy_soldier;
                                              num[copy_i][copy_j].copy_soldier = 0;
                                              switch(one[0].c[copy_i][copy_j])
                                              {
                                                  case 'B':
                                                  num[copy_i][copy_j].color[s1] = 0xeeff3434;
                                                  break;
                                                  case 'G':
                                                 num[copy_i][copy_j].color[s1] = 0xff00ff00;
                                                  break;
                                                  case 'P':
                                                  num[copy_i][copy_j].color[s1] = 0xffff6666;
                                                  break;
                                                  case 'R':
                                                  num[copy_i][copy_j].color[s1] = 0xff6666ff;
                                                  break;
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
   }
}
void AI_GAME_P(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
   bool exit_p = false;

   for(int i = 0; i < 10;i++)
   {
       for(int j = 0; j < 10;j++)
       {
           if(one[0].c[i][j] == 'P')
           {
               exit_p = true;

               break;
           }
       }
       if(exit_p == true)
       {
           break;
       }

   }
   srand(time(0));
   int ans = 0;
if(exit_p == true)
{
   int posx = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);

   int posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   while(one[0].c[posx][posy] != 'P')
   {
        posx =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   }
   int posx2;
   int posy2;
   int random = rand() % 25;
   if(random > 8)
   {
         ans = 0;
         posx2 = rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
         posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'B' && ans < 50)
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
   }

   }
   else if(random >=4 && random <= 8)
   {
       ans = 0;
            posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != '0'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }

   }
   else if(random >= 2 && random <= 3)
   {
         ans = 0;
            posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'G'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }
   else
   {
            ans = 0;
            posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'R'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }




   while(one[0].c[posx2][posy2] == 'm')
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
   }




   for(int s = 0; s<= 2;s++)
   {
       if(num[posx][posy].is_attack[s] == false && num[posx][posy].is_move[s] == false)
       { 
                                             num[posx][posy].is_move[s] = true;
                                               num[posx][posy].is_attack[s] = true;
                                               num[posx][posy].i[s] = posx2;
                                               num[posx][posy].j[s] = posy2;
                                               set_move(num,posx,posx2,posy,posy2,s);
                                              rate_seting(num,posx,posx2,posy,posy2,s);
                                              num[posx][posy].is_torecieve[s] = num[posx][posy].copy_soldier;
                                               num[posx][posy].copy_istorecieve[s] = num[posx][posy].copy_soldier;
                                              num[posx][posy].copy_soldier = 0;
                                              switch(one[0].c[posx][posy])
                                              {
                                                  case 'B':
                                                  num[posx][posy].color[s] = 0xeeff3434;
                                                  break;
                                                  case 'G':
                                                  num[posx][posy].color[s] = 0xff00ff00;
                                                  break;
                                                  case 'P':
                                                  num[posx][posy].color[s] = 0xffff6666;
                                                  break;
                                                  case 'R':
                                                  num[posx][posy].color[s] = 0xff6666ff;
                                                  break;
                                              }
                                              
                                              break;
                                         }
       }
   }
     


   }
void AI_GAME_G(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
     bool exit_p = false;

   for(int i = 0; i < 10;i++)
   {
       for(int j = 0; j < 10;j++)
       {
           if(one[0].c[i][j] == 'G')
           {
               exit_p = true;
               break;
           }
       }
   }
   srand(time(0));
   int ans = 0;
if(exit_p == true)
{
   int posx =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);

   int posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   while(one[0].c[posx][posy] != 'G')
   {
        posx =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   }
   int posx2;
   int posy2;
   int random = rand() % 25;
   if(random > 7)
   {
       ans = 0;
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'B' && ans < 50)
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  =  rand() % ((SCREEN_HEIGHT / (2 * r)));
        ans++;
   }

   }
   else if(random >=4 && random <= 8)
   {
       ans = 0;
            posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != '0'&& ans < 50)
         {
        posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }

   }
   else if(random >= 2 && random <= 3)
   {
         ans = 0;
            posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 = rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'P'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }
   else
   {
            ans = 0;
            posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'R'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }




   while(one[0].c[posx2][posy2] == 'm')
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
   }




   for(int s = 0; s<= 2;s++)
   {
       if(num[posx][posy].is_attack[s] == false && num[posx][posy].is_move[s] == false)
       { 
                                             num[posx][posy].is_move[s] = true;
                                               num[posx][posy].is_attack[s] = true;
                                               num[posx][posy].i[s] = posx2;
                                               num[posx][posy].j[s] = posy2;
                                               set_move(num,posx,posx2,posy,posy2,s);
                                              rate_seting(num,posx,posx2,posy,posy2,s);
                                              num[posx][posy].is_torecieve[s] = num[posx][posy].copy_soldier;
                                               num[posx][posy].copy_istorecieve[s] = num[posx][posy].copy_soldier;
                                              num[posx][posy].copy_soldier = 0;
                                              switch(one[0].c[posx][posy])
                                              {
                                                  case 'B':
                                                  num[posx][posy].color[s] = 0xeeff3434;
                                                  break;
                                                  case 'G':
                                                  num[posx][posy].color[s] = 0xff00ff00;
                                                  break;
                                                  case 'P':
                                                  num[posx][posy].color[s] = 0xffff6666;
                                                  break;
                                                  case 'R':
                                                  num[posx][posy].color[s] = 0xff6666ff;
                                                  break;
                                              }
                                              
                                              break;
                                         }
       }
   }
     


}
void AI_GAME_R(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
 bool exit_p = false;

   for(int i = 0; i < 10;i++)
   {
       for(int j = 0; j < 10;j++)
       {
           if(one[0].c[i][j] == 'R')
           {
               exit_p = true;
               break;
           }
       }
   }
   srand(time(0));
   int ans = 0;
if(exit_p == true)
{
   int posx = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);

   int posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   while(one[0].c[posx][posy] != 'R')
   {
        posx =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy =  rand() % ((SCREEN_HEIGHT / (2 * r)));
   }
   int posx2;
   int posy2;
   int random = rand() % 25;
   if(random > 8)
   {
       ans = 0;
        posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 = rand() %  ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'B' && ans < 50)
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
   }

   }
   else if(random >=4 && random <= 8)
   {
       ans = 0;
            posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != '0'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }

   }
   else if(random >= 2 && random <= 3)
   {
         ans = 0;
            posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'G'&& ans < 50)
         {
        posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  =  rand() % ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }
   else
   {
            ans = 0;
            posx2 = rand() %  ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2 =  rand() % ((SCREEN_HEIGHT / (2 * r)));
         while(one[0].c[posx2][posy2] != 'P'&& ans < 50)
         {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() % ((SCREEN_HEIGHT / (2 * r)));
        ans++;
         }
   }




   while(one[0].c[posx2][posy2] == 'm')
   {
        posx2 =  rand() % ((SCREEN_WIDTH / (2 * r) - 3)* 2);
        posy2  = rand() %  ((SCREEN_HEIGHT / (2 * r)));
   }




   for(int s = 0; s<= 2;s++)
   {
       if(num[posx][posy].is_attack[s] == false && num[posx][posy].is_move[s] == false)
       { 
                                             num[posx][posy].is_move[s] = true;
                                               num[posx][posy].is_attack[s] = true;
                                               num[posx][posy].i[s] = posx2;
                                               num[posx][posy].j[s] = posy2;
                                               set_move(num,posx,posx2,posy,posy2,s);
                                              rate_seting(num,posx,posx2,posy,posy2,s);
                                              num[posx][posy].is_torecieve[s] = num[posx][posy].copy_soldier;
                                               num[posx][posy].copy_istorecieve[s] = num[posx][posy].copy_soldier;
                                              num[posx][posy].copy_soldier = 0;
                                              switch(one[0].c[posx][posy])
                                              {
                                                  case 'B':
                                                  num[posx][posy].color[s] = 0xeeff3434;
                                                  break;
                                                  case 'G':
                                                  num[posx][posy].color[s] = 0xff00ff00;
                                                  break;
                                                  case 'P':
                                                  num[posx][posy].color[s] = 0xffff6666;
                                                  break;
                                                  case 'R':
                                                  num[posx][posy].color[s] = 0xff6666ff;
                                                  break;
                                              }
                                              
                                              break;
                                         }
       }
   }
     

 
}

void check_win(int winning[],struct color_militaries one[],struct region num[20][20])
{
    winning[0] = 0;
    winning[1] = 0;
    winning[2] = 0;
    winning[3] = 0;
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 10;j++)
        {
           switch(one[0].c[i][j])
           {
               case 'B': 
               winning[0]++;
               break;
               case 'P':
               winning[1]++;
               break;
               case 'R':
               winning[2]++;
               break;
               case 'G':
               winning[3]++;
               break;
           }
        }
    }
    printf("%d %d %d %d\n",winning[0],winning[1],winning[2],winning[3]);
}
int go_forscore(int winning[],struct region num[20][20],struct color_militaries one[])
{
  if(winning[0] == 0)
  {
      
    
   
      return -1;
     
  }
  else if(winning[1] ==0 && winning[2] ==0 &&  winning[3] ==0 && winning[0] > 0)
  {
   
     
 
      return 1;

    
  }
  return 0;
}