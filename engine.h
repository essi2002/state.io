#ifndef __ENGINE_HEADER
#define __ENGINE_HEADER

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <string.h>




struct color_militaries
{
   Uint32 color_arr[28][28];
   char c [28][28];
   int count_line[28][28];
   int index_potion[20][20];
   int number_ofpotion[20][20];
};



struct region
{
   int soldiers;
   int x_pos;
   int y_pos;
   int x_soldier[3][400];
   int y_soldier[3][400];
   bool soldier[3][400];
   bool isto_plus[3][400];
   bool is_continue[3][400];
   char c;
   char str[15];
   int vx[3];
   int vy[3];
   bool is_move[3];
   bool is_attack[3];  
   int i[3];
   int j[3];
   int minus[3];
   int copy_soldier;
   Uint32 color[3];
   int copy_vx[3];
   int copy_vy[3];
   bool increase;
   int factor;
   int fac_inc;
   int is_torecieve[3];
   int copy_istorecieve[3];
   int count;
   int radius;

};


struct potion
{
   bool is_push;
   char str[25];
   int time;
   int pos_x;
   int pos_y;
};

struct name_order
{
   int score;
   char str[50];
   char whole_name[50];
   
};
void boxes(short * array_x,short * array_y,Sint16 x0,Sint16 y0,int r,int a);
void draw_line(short * array_x,short * array_y,SDL_Renderer *sdlRenderer);
void drawn_hexagonal(short * array_x,short * array_y,int r,Sint16 x0,Sint16 y0,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer *sdlRenderer,struct color_militaries  one[],struct region num[20][20]);
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text);
void color_rand(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[]);
void draw_polygonon_place(int a,Sint16 x0,Sint16 y0,SDL_Renderer *sdlRenderer,Uint32 color,int lenght);
void number_of_each_region(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x0,Sint16 y0);
void checkout(int  * mouse_x,int  * mouse_y,int u,struct region num[20][20],int * ind,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void set_move(struct region num[20][20],int mouse_xfirst,int mouse_xsecond,int mouse_yfirst,int mouse_ysecond,int s);
void attackto(struct region num[20][20],struct color_militaries one[1],SDL_Renderer *sdlRenderer,int mouse_xfirst,int mouse_yfirst,int s);
void rate_seting(struct region num[20][20],int mouse_xfirst,int mouse_xsecond,int mouse_yfirst,int mouse_ysecond,int s);
void attackfrom(struct region num[20][20],int mouse_xfirst,int mouse_yfirst,int s);
void move_militaries(struct color_militaries one[],struct region num[20][20],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,SDL_Renderer *sdlRenderer,int r);

void already_make_map1(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void already_make_map2(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void already_make_map3(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void random_map(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,bool to_save);

void saved_random_map(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void memory_mangement(struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void upload_game(struct region num[20][20],struct color_militaries one[],struct potion potions[]);
void save_game(struct region num[20][20],struct color_militaries one[],struct potion potions[]);
void showimg2(SDL_Renderer * sdlRenderer,char * str,int x0,int y0,int w0,int h0);
int show_maps_in(SDL_Renderer * sdlRenderer);
#endif



