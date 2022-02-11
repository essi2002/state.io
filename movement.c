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
void checkout(int  * mouse_x,int  * mouse_y,int u,struct region num[20][20],int * ind,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
    *ind = 0;
    for(int i = 0; i < ((SCREEN_WIDTH / (2 * r) - 3)) * 2 ;i++)
    {
       
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
    
         if((num[i][j].x_pos  - *mouse_x  >= -u && num[i][j].x_pos - * mouse_x <= u) && (num[i][j].y_pos  - *mouse_y  >= -u && num[i][j].y_pos - * mouse_y <= u))
         {
            *mouse_x = i;
             *mouse_y = j;
             *ind = 1;
             return;
         }

  
      }
    }
}
void number_of_each_region(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x0,Sint16 y0)
{
    Sint16 pess = x0;
   for(int i = 0; i < ((SCREEN_WIDTH / (2 * r) - 3)) ;i++)
   {
       Sint16 copy = y0;
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
        
            switch(one[0].c[i][j])
            {
               case 'G':
               if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;
             case 'B':
             
               if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case 'P':
                if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case 'R' :
            if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case '0':
                  if(num[i][j].soldiers < 50)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
             num[i][j].x_pos = pess;
             num[i][j].y_pos = copy;
             num[i][j].c = one[0].c[i][j];
             break;
             default:
                  num[i][j].soldiers = -1;
             num[i][j].x_pos = -100;
             num[i][j].y_pos = -100;
             num[i][j].c = one[0].c[i][j];
              break;
            }
              copy += 2 * r * cos(M_PI / 6);
     }
     pess += 3 * r;
   }
    pess = x0 + 3 * r / 2;
   for(int i = ((SCREEN_WIDTH / (2 * r) - 3)); i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) ;i++)
   {
       Sint16 copy = y0 + r * cos(M_PI / 6);
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
        
            switch(one[0].c[i][j])
            {
              case 'G':
            
                if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
              break;
             case 'B':
             
                if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case 'P':
                if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case 'R' :
                if(num[i][j].soldiers < 150)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
          for(int s = 0; s <=2;s++)
          {
             if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == false)
             {
               num[i][j].minus[s] = 4;
                for(int l = 0; l < 400;l++)
                {
                  num[i][j].soldier[s][l] = true;
                  num[i][j].is_continue[s][l] = true;
                  num[i][j].isto_plus[s][l] = true;
                   num[i][j].x_soldier[s][l] = pess;
                  num[i][j].y_soldier[s][l] = copy;
               }
             }
          }
             break;

             case '0':
                 if(num[i][j].soldiers < 50)
             {
            num[i][j].soldiers+= num[i][j].fac_inc;
             num[i][j].copy_soldier += num[i][j].fac_inc;
             }
             num[i][j].x_pos = pess;
             num[i][j].y_pos = copy;
             break;
             default:
                  num[i][j].soldiers = -1;
             num[i][j].x_pos = -100;
             num[i][j].y_pos = -100;
             num[i][j].c = one[0].c[i][j];
              break;
            }
               copy += 2 * r * cos(M_PI / 6);
     }
      pess += 3 * r;
   }


}
void set_move(struct region num[20][20],int mouse_xfirst,int mouse_xsecond,int mouse_yfirst,int mouse_ysecond,int s)
{ 
        int dx = num[mouse_xsecond][mouse_ysecond].x_pos - num[mouse_xfirst][mouse_yfirst].x_pos;
        int dy = num[mouse_xsecond][mouse_ysecond].y_pos - num[mouse_xfirst][mouse_yfirst].y_pos;
       // printf("%d %d\n",dx,dy);
            if(dx == 0)
            {
              
                  if(dy < 0)
                    {
             
                        int vx = 6;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx / 2;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx / 2;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3: 
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= 2 * vx;
                                  break;
                          }
                       }

                    }
                    else if(dy > 0)
                    {
                          int vx = -6;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx / 2;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx / 2;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3: 
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= 2 * vx;
                                  break;
                          }
                       }
                         
                    }
            }
             else if(dx < 0)
               {
                    if(dy < 0)
                    {
                        int vx = -5;
                        int vy = -5 * dy/dx;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 0;
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy;
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 0;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -=vy;
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx;
                                  break;
                          }
                       }

                    }
                    else if(dy == 0)
                    {
                       int vy = 6;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                   num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy / 2;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -= vy / 2;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  break;
                                case 3: 
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -= 2 * vy;
                                  break;
                          }
                       }
                    }
                    else
                    {
                        int vx = -5;
                        int vy = vx * dy / dx;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 0;
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy;
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 0;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -=vy;
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx;
                                  break;
                          }
                       }

                    }
               }
               else if(dx > 0)
               {
                    if(dy < 0)
                    {
                          int vx = 5;
                        int vy = 5 * dy / dx;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 0;
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy;
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 0;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -=vy;
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx;
                                  break;
                          }
                       }

                    }
                    else if(dy == 0)
                    {
                      int vy = 6;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                   num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy / 2;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -= vy / 2;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  break;
                                case 3: 
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -= 2 * vy;
                                  break;
                          }
                       }

                    }
                    else
                    {
                        int vx = 5;
                        int vy = 5 * dy / dx;
                            for(int i = 0; i < 400;i++)
                          {
                          switch(i % 4)
                          {
                                case 0:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 0;
                                   num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += vx;
                                  break;
                                case 1:
                                num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += vy;
                                num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 0;
                                  break;
                                case 2:
                                 num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] -=vy;
                                 num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += 2 *vx;
                                  break;
                                case 3:
                                  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += 2 *vy;
                                  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] -= vx;
                                  break;
                          }
                       }

                    }
               }
        
   
}
void rate_seting(struct region num[20][20],int mouse_xfirst,int mouse_xsecond,int mouse_yfirst,int mouse_ysecond,int s)
{
   int dx = num[mouse_xsecond][mouse_ysecond].x_pos - num[mouse_xfirst][mouse_yfirst].x_pos;
   int dy = num[mouse_xsecond][mouse_ysecond].y_pos - num[mouse_xfirst][mouse_yfirst].y_pos;
   num[mouse_xfirst][mouse_yfirst].vx[s] = 7;
   num[mouse_xfirst][mouse_yfirst].vy[s] = 7;
   if(dx == 0)
   {
       num[mouse_xfirst][mouse_yfirst].vx[s] = 0;
       if(dy > 0)
       {
               num[mouse_xfirst][mouse_yfirst].vy[s] = 7;
       }
       else
       {
               num[mouse_xfirst][mouse_yfirst].vy[s] = -7;
       }

   }
   else if(dy == 0)
   {
       num[mouse_xfirst][mouse_yfirst].vy[s] = 0;
       if(dx > 0)
       {
            num[mouse_xfirst][mouse_yfirst].vx[s]= 7;
       }
       else
       {
               num[mouse_xfirst][mouse_yfirst].vx[s] = -7;
       }
   }
   else
   {
      if(dx > 0)
      {
                  num[mouse_xfirst][mouse_yfirst].vx[s] = 7;
                  num[mouse_xfirst][mouse_yfirst].vy[s] = num[mouse_xfirst][mouse_yfirst].vx[s] * dy / dx;


      }
      else
      {
                  num[mouse_xfirst][mouse_yfirst].vx[s] = -7;
                  num[mouse_xfirst][mouse_yfirst].vy[s] = num[mouse_xfirst][mouse_yfirst].vx[s] * dy / dx ;
      }
   }
}
void attackto(struct region num[20][20],struct color_militaries one[1],SDL_Renderer *sdlRenderer,int mouse_xfirst,int mouse_yfirst,int s)
{
   
   for(int i = 0; i < num[mouse_xfirst][mouse_yfirst].minus[s];i++)
   {
     if(num[mouse_xfirst][mouse_yfirst].is_continue[s][i] == true)
     {
        if(num[mouse_xfirst][mouse_yfirst].soldier[s][i] == true)
        {

           num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] += num[mouse_xfirst][mouse_yfirst].vx[s];
           num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] += num[mouse_xfirst][mouse_yfirst].vy[s];
        }
           if(num[mouse_xfirst][mouse_yfirst].isto_plus[s][i] == true && (num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].x_pos  -  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i]>= -22 && num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].x_pos  -  num[mouse_xfirst][mouse_yfirst].x_soldier[s][i] <= 22)  && (num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].y_pos  -  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i]>= -22 && num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].y_pos  -  num[mouse_xfirst][mouse_yfirst].y_soldier[s][i] <= 22) )
           {
             num[mouse_xfirst][mouse_yfirst].isto_plus[s][i] = false;
             num[mouse_xfirst][mouse_yfirst].soldier[s][i] = false;
              
                      if(num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers > 0 && one[0].c[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]] != one[0].c[mouse_xfirst][mouse_yfirst])
                      {
                        if(num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].increase == false)
                        {
                        
                            num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers -= num[mouse_xfirst][mouse_yfirst].factor;
                        }
                        else
                        {
                          num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers  += num[mouse_xfirst][mouse_yfirst].factor;
                        }
                      }
                      else if(num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers == 0 && one[0].c[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]] != one[0].c[mouse_xfirst][mouse_yfirst])
                      {
                            
                            one[0].c[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]] = one[0].c[mouse_xfirst][mouse_yfirst];
                             one[0].color_arr[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]] = one[0].color_arr[mouse_xfirst][mouse_yfirst];
                            printf("%c\n",one[0].c[mouse_xfirst][mouse_yfirst]);
                            
                      }
                      else if(num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers > 0 && one[0].c[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]] == one[0].c[mouse_xfirst][mouse_yfirst])
                      {
                       num[num[mouse_xfirst][mouse_yfirst].i[s]][num[mouse_xfirst][mouse_yfirst].j[s]].soldiers += num[mouse_xfirst][mouse_yfirst].factor;
                      }
                      num[mouse_xfirst][mouse_yfirst].copy_istorecieve[s]--;
                      if(num[mouse_xfirst][mouse_yfirst].copy_istorecieve[s] == 0)
                      {
                        num[mouse_xfirst][mouse_yfirst].is_attack[s] = false;
                      }

           }
           else
           {
              filledCircleColor(sdlRenderer,num[mouse_xfirst][mouse_yfirst].x_soldier[s][i], num[mouse_xfirst][mouse_yfirst].y_soldier[s][i],3,num[mouse_xfirst][mouse_yfirst].color[s]);
           }
     }
}



}

void attackfrom(struct region num[20][20],int mouse_xfirst,int mouse_yfirst,int s)
{
        if(num[mouse_xfirst][mouse_yfirst].is_torecieve[s] >= 4)
           {
           num[mouse_xfirst][mouse_yfirst].is_torecieve[s] -= 4;
           num[mouse_xfirst][mouse_yfirst].minus[s] += 4;
           num[mouse_xfirst][mouse_yfirst].soldiers -=4;
           }
           else
           {
             num[mouse_xfirst][mouse_yfirst].minus[s] += num[mouse_xfirst][mouse_yfirst].is_torecieve[s] % 4;
             num[mouse_xfirst][mouse_yfirst].soldiers -= num[mouse_xfirst][mouse_yfirst].is_torecieve[s];
            num[mouse_xfirst][mouse_yfirst].is_torecieve[s] = 0;
             num[mouse_xfirst][mouse_yfirst].is_move[s] = false;
           }
}

void move_militaries(struct color_militaries one[],struct region num[20][20],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer *sdlRenderer,int r)
{
  for(int i = 0; i < ((SCREEN_WIDTH / (2 * r) - 3)) * 2 ;i++)
  {
      
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
        for(int s = 0; s <= 2;s++)
        {
        switch(one[0].c[i][j])
        {
         
          case 'G':
            if(num[i][j].is_move[s] == true && num[i][j].is_attack[s] == true)
             {
               
                  attackto(num,one,sdlRenderer,i,j,s);
                  attackfrom(num,i,j,s);
             }
             else if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == true)
             {
                  attackto(num,one,sdlRenderer,i,j,s);
             }
          break;
            case 'B':
             if(num[i][j].is_move[s] == true && num[i][j].is_attack[s] == true)
             {
               
                  attackto(num,one,sdlRenderer,i,j,s);
                  attackfrom(num,i,j,s);
             }
             else if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == true)
             {
                  attackto(num,one,sdlRenderer,i,j,s);
             }
            break;
            case 'P':
            if(num[i][j].is_move[s] == true && num[i][j].is_attack[s] == true)
             {
               
                  attackto(num,one,sdlRenderer,i,j,s);
                  attackfrom(num,i,j,s);
             }
             else if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == true)
             {
                  attackto(num,one,sdlRenderer,i,j,s);
             }
            break;
            case 'R':
            if(num[i][j].is_move[s] == true && num[i][j].is_attack[s] == true)
             {
               
                  attackto(num,one,sdlRenderer,i,j,s);
                  attackfrom(num,i,j,s);
             }
             else if(num[i][j].is_move[s] == false && num[i][j].is_attack[s] == true)
             {
                  attackto(num,one,sdlRenderer,i,j,s);
             }
            break;
        }
      }
      }
  }
     

}

void first_appear(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x0,Sint16 y0)
{
     Sint16 pess = x0;
   for(int i = 0; i < SCREEN_WIDTH / (2 * r) - 3 ;i++)
   {
       Sint16 copy = y0;
      for(int j = 0; j < SCREEN_HEIGHT / (2 * r);j++)
      {
       printf("ass %c %d %d\n",one[0].c[i][j],i,j);
            switch(one[0].c[i][j])
            {
            case 'G':
                num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0; s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case 'B':
               num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0 ;s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case 'P':
              num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0 ;s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case 'R' :
               num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0 ;s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case '0':
             num[i][j].x_pos = pess;
             num[i][j].y_pos = copy;
             break;
           
            }
              copy += 2 * r * cos(M_PI / 6);
     }
     pess += 3 * r;
   }
    pess = x0 + 3 * r / 2;
   for(int i = ((SCREEN_WIDTH / (2 * r) - 3)); i < ((SCREEN_WIDTH / (2 * r) - 3) * 2) ;i++)
   {
       Sint16 copy = y0 + r * cos(M_PI / 6);
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
      printf("ass %c %d %d\n",one[0].c[i][j],i,j);
            switch(one[0].c[i][j])
            {
            case 'G':
           
              num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0 ;s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
            break;
            case 'B':
            num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0; s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case 'P':
                num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0; s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case 'R' :
                num[i][j].soldiers = 50;
            num[i][j].copy_soldier = 50;
            num[i][j].x_pos = pess;
            num[i][j].y_pos = copy;
            for(int s = 0 ;s <= 2;s++)
            {

                
            for(int l = 0; l < 400;l++)
            {
              num[i][j].x_soldier[s][l] = pess;
              num[i][j].y_soldier[s][l] = copy;
            }
            }
             break;

             case '0':
             num[i][j].x_pos = pess;
             num[i][j].y_pos = copy;
             break;
            
            }
               copy += 2 * r * cos(M_PI / 6);
     }
      pess += 3 * r;
   }
}
void collision(struct color_militaries one[],struct region num[20][20],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
   for(int i = 0; i < ((SCREEN_WIDTH / (2 * r) - 3)) * 2 ;i++)
  {
      
      for(int j = 0; j < ((SCREEN_HEIGHT / (2 * r)));j++)
      {
         if(one[0].c[i][j] != 'm' && one[0].c[i][j] != '0')
         {
           for(int s = 0 ; s<= 2;s++)
           {
             if(num[i][j].is_attack[s] == true || num[i][j].is_move[s] == true)
             {
            for(int copy_j = j + 1;copy_j < ((SCREEN_HEIGHT / (2 * r)));copy_j++)
            {
              if(one[0].c[i][copy_j] != 'm' && one[0].c[i][copy_j] != '0')
              {

                for(int s1 = 0; s1 <= 2;s1++)
                {
                   if(num[i][copy_j].is_attack[s1] == true || num[i][copy_j].is_move[s1] == true)
                   {
                     if(one[0].c[i][j] != one[0].c[i][copy_j])
                     {
                         for(int p = 0; p < num[i][j].minus[s];p++)
                         {
                           for(int k = 0; k < num[i][copy_j].minus[s1];k++)
                           {
                              if((num[i][j].x_soldier[s][p] - num[i][copy_j].x_soldier[s1][k]) * (num[i][j].x_soldier[s][p] - num[i][copy_j].x_soldier[s1][k]) + (num[i][j].y_soldier[s][p] - num[i][copy_j].y_soldier[s1][k]) * (num[i][j].y_soldier[s][p] - num[i][copy_j].y_soldier[s1][k]) <= 36)
                             {
                               if(num[i][j].is_continue[s][p] == true && num[i][copy_j].is_continue[s1][k] == true)
                               {
                                  num[i][j].is_continue[s][p] = false;
                                  num[i][copy_j].is_continue[s1][k] = false;
                                  num[i][j].copy_istorecieve[s]--;
                                  num[i][copy_j].copy_istorecieve[s1]--;
                               }
      
                             }
                           }
                         }


                     }
                   }
                }
              }

            }


              for(int copy_i = i + 1;copy_i < ((SCREEN_WIDTH / (2 * r) - 3)) * 2;copy_i++)
            {
                for(int copy_j = 0;copy_j < ((SCREEN_HEIGHT / (2 * r)));copy_j++)
                {
                     if(one[0].c[copy_i][copy_j] != 'm' && one[0].c[copy_i][copy_j] != '0')
                     {
                          for(int s1 = 0; s1 <= 2;s1++)
                         {
                            if(num[copy_i][copy_j].is_attack[s1] == true || num[copy_i][copy_j].is_move[s1] == true)
                             {
                                if(one[0].c[i][j] != one[0].c[copy_i][copy_j])
                                 {
                                   for(int p = 0; p < num[i][j].minus[s];p++)
                                    {
                                        for(int k = 0; k < num[copy_i][copy_j].minus[s1];k++)
                                        {
                                          if((num[i][j].x_soldier[s][p] - num[copy_i][copy_j].x_soldier[s1][k]) * (num[i][j].x_soldier[s][p] - num[copy_i][copy_j].x_soldier[s1][k]) + (num[i][j].y_soldier[s][p] - num[copy_i][copy_j].y_soldier[s1][k]) * (num[i][j].y_soldier[s][p] - num[copy_i][copy_j].y_soldier[s1][k]) <= 36)
                                            {
                                                 if(num[i][j].is_continue[s][p] == true && num[copy_i][copy_j].is_continue[s1][k] == true)
                                                   {
                                                        num[i][j].is_continue[s][p] = false;
                                                        num[copy_i][copy_j].is_continue[s1][k] = false;
                                                        num[i][j].copy_istorecieve[s]--;
                                                        num[copy_i][copy_j].copy_istorecieve[s1]--;
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
           }
         }

       

      }
  }

}




  