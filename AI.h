#ifndef __AI_HEADER
#define __AI_HEADER
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
#include "engine.h"

void sarbaz1(struct region num[20][20],int i,int j,struct potion potions[],int s);
void sarbaz2(struct region num[20][20],int i,int j,struct potion potions[],int s,struct color_militaries one[]);
void sarbazkhoneh1(struct region num[20][20],int i,int j,struct potion potions[],int s);
void sarbazkhoneh2(struct region num[20][20],int i,int j,struct potion potions[],int s);
void to_check_on_potion(struct potion potions[],struct region num[20][20],struct color_militaries one[]);
void username(char * username,SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
void check_bold(int mouse_move_x,int mouse_move_y,int x0,int y0,int r,bool buttons[],int i,bool pashm);
int go_and_continue(int mouse_x,int mouse_y,bool buttons[]);
int show_menu(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
void get_text_and_rect2(SDL_Renderer *renderer, int x, int y, char *text);
void leaderboard(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
void swap(struct name_order *xp, struct name_order *yp);
void bubblesort(struct name_order arr[] , int n);
void file_work(char * ptr,struct name_order class[50],int n);
void new_game(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x_0,Sint16 y_0,struct color_militaries one[],struct name_order class[50],struct region num[20][20],struct potion potions[],char ptr[]);
void first_appear(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x0,Sint16 y0);
void collision(struct color_militaries one[],struct region num[20][20],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void showimg(SDL_Renderer * sdlRenderer,char * str,int x0,int y0,int w0,int h0);
void potionsion(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct potion potions[],struct region num[20][20]);
void checkPOT(struct potion potions[],SDL_Renderer * sdlRenderer);
int map_game(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT);
void color_rand2(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[]);
void color_rand3(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[]);
void color_randmemory(const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,struct color_militaries  one[]);
void go_for_potoion(struct potion potions[],struct region num[20][20],struct color_militaries one[]);
void moveforprotect(struct region num[20][20],struct color_militaries one[],char a);
void AI_GAME_P(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void AI_GAME_G(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void AI_GAME_R(struct region num[20][20],struct color_militaries one[],const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r);
void check_win(int winning[],struct color_militaries one[],struct region num[20][20]);
int go_forscore(int winning[],struct region num[20][20],struct color_militaries one[]);
int show_save_randomampe(SDL_Renderer * sdlRenderer);
#endif