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

void check_bold2(int mouse_move_x,int mouse_move_y,int x0,int y0,int r,bool butt[],int i,bool pashm)
{
    if ((mouse_move_x - x0) <= r && (mouse_move_x - x0) >= -r && (mouse_move_y - y0) <= r && (mouse_move_y - y0) >= -r)
    {
         butt[i] = pashm;
         return;
    }
    
}

int go_and_continue2(int mouse_x,int mouse_y,bool butt[])
{
  if(butt[0] == false &&(mouse_x - 700) <= 50 && (mouse_x - 700) >= -50&& (mouse_y - 100) <= 50 && (mouse_y - 100 ) >= -50)
  {
    return 0;
  }
  else if(butt[0] == true &&(mouse_x - 700) <= 60 && (mouse_x - 700) >= -60&& (mouse_y - 100) <= 60 && (mouse_y - 100 ) >= -60)
  {
    return 0;
  }
  else if(butt[1] == false &&(mouse_x - 700) <= 50 && (mouse_x - 700) >= -50&& (mouse_y - 250) <= 50 && (mouse_y - 250 ) >= -50)
  {
     return 1;
  }
  else if(butt[1] == true &&(mouse_x - 700) <= 60 && (mouse_x - 700) >= -60&& (mouse_y - 250) <= 60 && (mouse_y - 250 ) >= -60)
  {
       return 1;

  }
  else if(butt[2] == false &&(mouse_x - 700) <= 50 && (mouse_x - 700) >= -50&& (mouse_y - 400) <= 50 && (mouse_y - 400 ) >= -50)
  {
     return 2;
  }
  else if(butt[2] == true &&(mouse_x - 700) <= 60 && (mouse_x - 700) >= -60&& (mouse_y - 400) <= 60 && (mouse_y - 400 ) >= -60)
  {
       return 2;
  }
  else if(butt[3] == false &&(mouse_x - 700) <= 50 && (mouse_x - 700) >= -50&& (mouse_y - 550) <= 50 && (mouse_y - 550 ) >= -50)
  {
     return 3;
  }
  else if(butt[3] == true &&(mouse_x - 700) <= 60 && (mouse_x - 700) >= -60&& (mouse_y - 550) <= 60 && (mouse_y - 550 ) >= -60)
  {
       return 3;
  }
     return -1;
}

int map_game(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT)
{
     bool butt[4];
     butt[0] = false;
     butt[1] = false;
     butt[2] = false;
     butt[3] = false;
     int mouse_move_x;
     int mouse_move_y;
     int mouse_x;
     int mouse_y;
 SDL_bool shallExit = SDL_FALSE;
 while(shallExit == SDL_FALSE)
 {

      SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
        showimg(sdlRenderer,"map.jpeg",0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        if(butt[0] == false)
        {
           
            showimg2(sdlRenderer,"rename.bmp",650,50,100,100);
        }
        else
        {
             showimg2(sdlRenderer,"rename.bmp",640,40,120,120);
             
        }
        if(butt[1] == false)
        {
            
               showimg2(sdlRenderer,"random.bmp",650,200,100,100);
        }
        else
        {
              
               showimg2(sdlRenderer,"random.bmp",650,190,120,120);
        }
        if(butt[2] == false)
        {
            showimg2(sdlRenderer,"saved_random_map.bmp",650,350,100,100);
           
        }
        else
        {
            showimg2(sdlRenderer,"saved_random_map.bmp",650,340,120,120);
             

        }
        if(butt[3] == false)
        {
         
            showimg2(sdlRenderer,"memorymanagement.bmp",650,500,100,100);

        }
        else
        {
           
             showimg2(sdlRenderer,"memorymanagement.bmp",650,490,120,120);


        }
     SDL_RenderPresent(sdlRenderer);
     SDL_Event sdlEvent;
     while(SDL_PollEvent(&sdlEvent))
     {
         switch(sdlEvent.type)
         {
             case SDL_QUIT:
             shallExit = SDL_TRUE;
             break;
             case SDL_MOUSEMOTION:
                    mouse_move_x = sdlEvent.motion.x;
                    mouse_move_y = sdlEvent.motion.y;
                    if(butt[0] == false)
                    {
                    check_bold2(mouse_move_x,mouse_move_y,700,100,50,butt,0,true);
                    }
                    else
                    {
                     check_bold2(mouse_move_x,mouse_move_y,700,100,60,butt,0,false);
                    }
                     if(butt[1] == false)
                    {
                    check_bold2(mouse_move_x,mouse_move_y,700,250,50,butt,1,true);
                    }
                    else
                    {
                       check_bold2(mouse_move_x,mouse_move_y,700,250,60,butt,1,false);
                    }
                     if(butt[2] == false)
                    {
                       check_bold2(mouse_move_x,mouse_move_y,700,400,50,butt,2,true);
                    }
                    else
                    {
                       check_bold2(mouse_move_x,mouse_move_y,700,400,60,butt,2,false);
                    }
                    if(butt[3] == false)
                    {
                       check_bold2(mouse_move_x,mouse_move_y,700,550,50,butt,3,true);
                    }
                    else
                    {
                      check_bold2(mouse_move_x,mouse_move_y,700,550,60,butt,3,false);
                    }
             break;
             case SDL_MOUSEBUTTONDOWN:
                  mouse_x = sdlEvent.button.x;
                  mouse_y = sdlEvent.button.y;
                  if(go_and_continue2(mouse_x,mouse_y,butt) != -1)
                  {
                    return(go_and_continue2(mouse_x,mouse_y,butt));

                  }
             break;
         }
     }
 }

return 0;


}



void already_make_map1(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
  color_rand(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);
  one[0].c[3][2] = 'P';
  one[0].color_arr[3][2] = 0xffff9a9a;
  one[0].c[2][1] = 'R';
  one[0].color_arr[2][1] = 0xaaec6fff;
  one[0].c[2][3] = 'B';
  one[0].color_arr[2][3] = 0xccffd62b;

}
void already_make_map2(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
  color_rand2(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);
  one[0].c[1][2] = 'P';
  one[0].color_arr[1][2] = 0xffff9a9a;
 one[0].c[0][1] = 'R';
  one[0].color_arr[0][1] = 0xaaec6fff;
  one[0].c[4][3] = 'B';
  one[0].color_arr[4][3] = 0xccffd62b;
}
void already_make_map3(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
  color_rand3(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);
  one[0].c[1][2] = 'P';
  one[0].color_arr[1][2] = 0xffff9a9a;
  one[0].c[2][1] = 'R';
  one[0].color_arr[2][1] = 0xaaec6fff;
  one[0].c[3][3] = 'B';
  one[0].color_arr[3][3] = 0xccffd62b;
  one[0].c[2][3] = 'G';
  one[0].color_arr[2][3] = 0xff00ff22;

}
void random_map(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,bool to_save)
{
 color_rand(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);
  srand(time(0));

char choice[3];
int pos_x[3];
int pos_y[3];
  
  choice[2] = 'B';
  switch(rand() % 3)
  {
      case 0:
        choice[0] = 'P';
        choice[1] = 'R';
      break;
      case 1:
        choice[0] = 'G';
        choice[1] = 'P';
      break;
      case 2:
        choice[0] = 'R';
        choice[1] = 'G';
      break;
  }
  pos_x[2] = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2);
  pos_y[2] = rand() % ((SCREEN_HEIGHT / (2 * r)) );



  pos_x[1] = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2);
  pos_y[1] = rand() % ((SCREEN_HEIGHT / (2 * r)) );

  while(pos_x[1] == pos_x[2] && pos_y[1] == pos_y[2])
  {
      pos_x[1] = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2);
      pos_y[1] = rand() % ((SCREEN_HEIGHT / (2 * r)) );

  }

  pos_x[0] = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2);
  pos_y[0] = rand() % ((SCREEN_HEIGHT / (2 * r)) );

  while((pos_x[0] == pos_x[2] && pos_y[0] == pos_y[2]) || (pos_x[0] == pos_x[1] && pos_y[0] == pos_y[1]))
  {
      pos_x[0] = rand() % ((SCREEN_WIDTH / (2 * r) - 3) * 2);
      pos_y[0] = rand() % ((SCREEN_HEIGHT / (2 * r)) );

  }

    one[0].c[pos_x[2]][pos_y[2]] = 'B';
    one[0].color_arr[pos_x[2]][pos_y[2]] = 0xccffd62b;
    for(int i = 0; i < 2;i++)
    {
        switch(choice[i])
        {
            case 'P':
            one[0].c[pos_x[i]][pos_y[i]] = 'P';
            one[0].color_arr[pos_x[i]][pos_y[i]] = 0xffff9a9a;
            break;

            case 'R':
             one[0].c[pos_x[i]][pos_y[i]] = 'R';
            one[0].color_arr[pos_x[i]][pos_y[i]] = 0xaaec6fff;

            break;

            case 'G':
             one[0].c[pos_x[i]][pos_y[i]] = 'G';
            one[0].color_arr[pos_x[i]][pos_y[i]] = 0xff00ff22;
            break;
        }
    }
   if(to_save == true)
   {
       //PRGB
       FILE * fp = fopen("map.txt","w");
       FILE * fp1 = fopen("pos_x.txt","w");
       FILE * fp2 = fopen("pos_y.txt","w");
       bool exitchar[4];
       char c_copy[4][1];
       int copy_posx[4];
       int copy_posy[4];
       exitchar[0] = false;
       exitchar[1] = false;
       exitchar[2] = false;
       exitchar[3] = false;
           for(int j = 0; j < 3;j++)
           {
              if('P' == choice[j])
              {
                  c_copy[0][0] = 'P';
                  exitchar[0] = true;
                 copy_posx[0] = pos_x[j];
                 copy_posy[0] = pos_y[j];
                  break;
              }
           }
            for(int j = 0; j < 3;j++)
           {
              if('R' == choice[j])
              {
                    c_copy[1][0] = 'R';
                  exitchar[1] = true;
                 copy_posx[1] = pos_x[j];
                 copy_posy[1] = pos_y[j];
                  break;
              }
           }
             for(int j = 0; j < 3;j++)
           {
              if('G' == choice[j])
              {
                    c_copy[2][0] = 'G';
                  exitchar[2] = true;
                 copy_posx[2] = pos_x[j];
                 copy_posy[2] = pos_y[j];
                  break;
              }
           }
              for(int j = 0; j < 3;j++)
           {
              if('B' == choice[j])
              {
                    c_copy[3][0] = 'B';
                  exitchar[3] = true;
                 copy_posx[3] = pos_x[j];
                 copy_posy[3] = pos_y[j];
                  break;
              }
           }
         



         for(int i = 0;i < 4;i++)
         {
             if(exitchar[i] == true)
             {
             putc(c_copy[i][0],fp);
              fprintf(fp1,"%d ",copy_posx[i]);
              fprintf(fp2,"%d ",copy_posy[i]);
               
             }
             else
             {
                   putc('N',fp);
              fprintf(fp1,"%d ",0);
              fprintf(fp2,"%d ",0);

             }
         }
         fclose(fp);
         fclose(fp1);
         fclose(fp2);
   }

}

void saved_random_map(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
    FILE * fp = fopen("map.txt","r");
       FILE * fp1 = fopen("pos_x.txt","r");
       FILE * fp2 = fopen("pos_y.txt","r");
   char c[4][1];
   bool exist[4];
   int posx[4];
   int posy[4];
   int i = 0;
   char a;
   while((a = getc(fp)) != EOF)
   {
       
       c[i][0] = a;
       fscanf(fp1,"%d ",&posx[i]);
       printf("%d\n",posx[i]);
           
          fscanf(fp2,"%d ",&posy[i]);
          printf("%d\n",posy[i]);
       if(strcmp(c[i],"N") != 0)
       {
          
        exist[i] = false;
       }
       else
       {
           exist[i] = true;
       }
    i++;
   }

   color_rand(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);

   for(int j = 0;j < i;j++)
   {
       if(exist[j] == false)
         {
             one[0].c[posx[j]][posy[j]] =  c[j][0];
             switch(one[0].c[posx[j]][posy[j]])
             {
                 case 'B':
                 one[0].color_arr[posx[j]][posy[j]] = 0xccffd62b;
                 break;
                 case 'G':
                 one[0].color_arr[posx[j]][posy[j]] = 0xff00ff00;
                 break;
                 case 'P':
                  one[0].color_arr[posx[j]][posy[j]] = 0xffff9a9a;
                 break;

                 case 'R':
                  one[0].color_arr[posx[j]][posy[j]] = 0xaaec6fff;
                 break;
             }
         }
   }



fclose(fp);
fclose(fp1);
fclose(fp2);


}

void memory_mangement(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r)
{
  color_randmemory(SCREEN_WIDTH,SCREEN_HEIGHT,r,one);
  one[0].c[2][2] = 'R';
  one[0].color_arr[2][2] = 0xaaec6fff;
}





