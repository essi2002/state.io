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


void username(char * username,SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT)
{
 
    SDL_bool shallExit = SDL_FALSE;
    int ind = 0;
    char c;
    int s;
    int l;
    while(shallExit == SDL_FALSE)
    {
        SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
       showimg(sdlRenderer,"username.jpeg",0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        showimg2(sdlRenderer,"username.bmp",120,340,140,80);
         get_text_and_rect(sdlRenderer,145,380,username);
        SDL_RenderPresent(sdlRenderer);
         
          SDL_Event sdlEvent;
          while(SDL_PollEvent(&sdlEvent))
          {
               int lenght = strlen(username);
                switch(sdlEvent.type)
                {
                     case SDL_QUIT:
                      shallExit = SDL_TRUE;
                     break;
                     case SDL_MOUSEBUTTONDOWN:
                       s = sdlEvent.button.x;
                       l = sdlEvent.button.y;
                       if( ((s - 215) <= 75 && (s - 215) >= -75) && ( (l - 390) <= 50 && (l - 390) >= -50) )
                       {
                            if(ind == 0)
                            {
                                 ind = 1;
                            }
                            else
                            {
                                 ind = 0;
                            }

                       }
                     break;
                     case SDL_KEYUP:
                       if(ind == 1)
                       {
                            switch(sdlEvent.key.keysym.sym)
                            {
                                 case SDLK_SPACE:
                                 c = ' ';
                                 break;
                                 case SDLK_RETURN:
                                    if(lenght > 0)
                                    {
                                         //printf("%s\n",username);
                                         return;
                                    }
                                 break;
                                 case SDLK_BACKSPACE:
                                  c = ' ';
                                  if(lenght > 0)
                                  {
                                  username[lenght - 1] = '\0';
                                  }
                                 break;
                                 default:
                                   if(sdlEvent.key.keysym.sym != SDLK_UP && sdlEvent.key.keysym.sym != SDLK_DOWN && sdlEvent.key.keysym.sym != SDLK_RIGHT && sdlEvent.key.keysym.sym != SDLK_LEFT)
                                   {
                                       c = sdlEvent.key.keysym.sym;
                                   }
                                 break;

                            }
                            if(lenght <= 10)
                            {
                                 if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                                 {
                                       username[lenght] = c;
                                       username[lenght + 1] = '\0';
                                 }
                            }
                       }
                     break;
                     
                     

                }
          } 
    }
}

void check_bold(int mouse_move_x,int mouse_move_y,int x0,int y0,int r,bool buttons[],int i,bool pashm)
{
    if ((mouse_move_x - x0) <= r && (mouse_move_x - x0) >= -r && (mouse_move_y - y0) <= r && (mouse_move_y - y0) >= -r)
    {
         buttons[i] = pashm;
         return;
    }
    
}
int go_and_continue(int mouse_x,int mouse_y,bool buttons[])
{
  if(buttons[0] == false &&(mouse_x - 125) <= 25 && (mouse_x - 125) >= -25&& (mouse_y - 175) <= 25 && (mouse_y - 175 ) >= -25)
  {
    return 0;
  }
  else if(buttons[0] == true &&(mouse_x - 125) <= 35 && (mouse_x - 125) >= -35&& (mouse_y - 175) <= 35 && (mouse_y - 175 ) >= -35)
  {
    return 0;
  }
  else if(buttons[1] == false &&(mouse_x - 125) <= 25 && (mouse_x - 125) >= -25&& (mouse_y - 325) <= 25 && (mouse_y - 325 ) >= -25)
  {
     return 1;
  }
  else if(buttons[1] == true &&(mouse_x - 125) <= 35 && (mouse_x - 125) >= -35&& (mouse_y - 325) <= 35 && (mouse_y - 325 ) >= -35)
  {
       return 1;

  }
  else if(buttons[2] == false &&(mouse_x - 125) <= 25 && (mouse_x - 125) >= -25&& (mouse_y - 475) <= 25 && (mouse_y - 475 ) >= -25)
  {
     return 2;
  }
  else if(buttons[2] == true &&(mouse_x - 125) <= 35 && (mouse_x - 125) >= -35&& (mouse_y - 475) <= 35 && (mouse_y - 475 ) >= -35)
  {
       return 2;
  }
     return -1;
}
int show_menu(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT)
{
     bool buttons[3];
     buttons[0] = false;
     buttons[1] = false;
     buttons[2] = false;

     SDL_bool shallExit = SDL_FALSE;
     int mouse_move_x;
     int mouse_move_y;
     int mouse_x;
     int mouse_y;
   while(shallExit == SDL_FALSE)
   {
         SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
        showimg(sdlRenderer,"menu.jpg",0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        if(buttons[0] == false)
        {
        showimg2(sdlRenderer,"newgame.bmp",100,150,100,100);
        }
        else
        {
             showimg2(sdlRenderer,"newgame.bmp",90,140,120,120);
             
        }
        if(buttons[1] == false )
        {
              showimg2(sdlRenderer,"resume.bmp",100,300,100,100);
        }
        else
        {
              showimg2(sdlRenderer,"resume.bmp",90,290,120,120);
        }
        if(buttons[2] == false)
        {
        showimg2(sdlRenderer,"leaderboard.bmp",100,450,100,100);
        }
        else
        {
              showimg2(sdlRenderer,"leaderboard.bmp",90,440,120,120);

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
                    if(buttons[0] == false)
                    {
                    check_bold(mouse_move_x,mouse_move_y,125,175,25,buttons,0,true);
                    }
                    else
                    {
                     check_bold(mouse_move_x,mouse_move_y,125,175,35,buttons,0,false);
                    }
                     if(buttons[1] == false)
                    {
                    check_bold(mouse_move_x,mouse_move_y,125,325,25,buttons,1,true);
                    }
                    else
                    {
                       check_bold(mouse_move_x,mouse_move_y,125,325,35,buttons,1,false);
                    }
                      if(buttons[2] == false)
                    {
                    check_bold(mouse_move_x,mouse_move_y,125,475,25,buttons,2,true);
                    }
                    else
                    {
                     check_bold(mouse_move_x,mouse_move_y,125,475,35,buttons,2,false);
                    }

                  break;
               
                  case SDL_MOUSEBUTTONDOWN:
                  mouse_x = sdlEvent.button.x;
                  mouse_y = sdlEvent.button.y;
                  if(go_and_continue(mouse_x,mouse_y,buttons) != -1)
                  {
                         return(go_and_continue(mouse_x,mouse_y,buttons));
                  }
                  break;
               

             }
        }


   }
   return 0;
}

void swap(struct name_order *xp, struct name_order *yp)
{
    struct name_order temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubblesort(struct name_order arr[] , int n)
{
  int i, j;
   for (i = 0; i < n-1; i++)   
   {
       for (j = 0; j < n-i-1; j++) 
       {
           if (arr[j].score < arr[j+1].score)
           {
              swap(&arr[j], &arr[j+1]);
           }
       }
   }
}

void leaderboard(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT)
{
     SDL_bool shallExit = SDL_FALSE;
     while(shallExit == SDL_FALSE)
     {
           SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
           SDL_RenderClear(sdlRenderer);
           showimg(sdlRenderer,"leaderboard.png",0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
         FILE* f1;
           f1 = fopen("wholename.txt", "r");
           FILE* f2;
           f2 = fopen("wholename.txt", "r");
           char names[20];
          int total_users = 0;
          while (fscanf(f1, "%[^\n]%*c", names) != EOF)
          {
            total_users++;
          }

          fclose(f1);
          int i = 0;
          int y = 50;
          while (fscanf(f2, "%[^\n]%*c", names) != EOF && (i < total_users && i < 5))
          {
            showimg(sdlRenderer,"lead.jpg",300,y,200,100);
            get_text_and_rect(sdlRenderer,340,y + 35,names);
            y += 105;
            i++;
          }
          fclose(f2);
           SDL_RenderPresent(sdlRenderer);
           SDL_Event sdlEvent;
          while(SDL_PollEvent(&sdlEvent))
          {
               switch(sdlEvent.type)
               {
               case SDL_QUIT:
               shallExit = SDL_TRUE;
               break;
               }
          }
     }
  
}


  










void file_work( char new_username[35], struct name_order participants[50], int n)
{

    FILE* f1;
    FILE* f2;
    FILE* f3;
    f1 = fopen("wholename.txt", "rw");
    f2 = fopen("name.txt", "rw");
    f3 = fopen("score.txt", "rw");

     if (f1 == NULL) {
        printf("File doesn't exist!");
        return ;
    }
    if (f2 == NULL) {
        printf("File doesn't exist!");
        return ;
    }
    if (f3 == NULL) {
        printf("File doesn't exist!");
        return ;
    }


    int total_users1 = 0;
    int total_users2 = 0;
    int total_users3 = 0;
    while (fscanf(f3, "%d", &participants[total_users3].score) != EOF)
    {
      total_users3++;
    }
    fclose(f3);
    while (fscanf(f2, " %s", participants[total_users2].str) != EOF)
    {
      
      total_users2++;
    }
    fclose(f2);
    while (fscanf(f1, " %[^\n]%*c", participants[total_users1].whole_name) != EOF)
    {
      total_users1++;
    }
    fclose(f1);

    int check = 0;
    for(int i = 0; i < total_users1;i++)
    {
      if(strcmp(participants[i].str, new_username)==0)
      {
        participants[i].score += n;
        char old_user[20];
        strcpy(old_user,participants[i].str);
        strcat(old_user," : ");
        char cpy[10];
        sprintf(cpy, "%d", participants[i].score);
        strcat(old_user,cpy);
        strcpy(participants[i].whole_name,old_user);
        check = 1;
        break;
      }
    }
    if(check==0)
    {
      strcpy(participants[total_users1].str,new_username);
      
      participants[total_users1].score = n;
      strcat(new_username," : ");
      char cpy[20];
      sprintf(cpy, "%d", n);
      strcat(new_username,cpy);
      strcpy(participants[total_users1].whole_name,new_username);
      total_users1++;
    }

    f1 = fopen("wholename.txt", "w");
    f2 = fopen("name.txt", "w");
    f3 = fopen("score.txt", "w");

   bubblesort(participants,total_users1);
    for (int i = 0; i < total_users1; i++) {
  
        fprintf(f1, "%s\n", participants[i].whole_name);
        fprintf(f2, "%s\n", participants[i].str);
        fprintf(f3, "%d\n", participants[i].score);
    }

        fclose(f2);
        fclose(f1);
        fclose(f3);
}


void save_game(struct region num[20][20],struct color_militaries one[],struct potion potions[])
{
     FILE * fp = fopen("save_num.txt","w");
     FILE * fp1 = fopen("save_one.txt","w");
     FILE * fp2 = fopen("save_potion.txt","w");
     for(int i = 0; i < 20;i++)
     {
          for(int j = 0; j < 20;j++ )
          {
               fprintf(fp1,"%c %d %d %u",one[0].c[i][j],one[0].index_potion[i][j],one[0].number_ofpotion[i][j],one[0].color_arr[i][j]);
               fprintf(fp,"%s %d %d %d %d ",num[i][j].str,num[i][j].soldiers,num[i][j].x_pos,num[i][j].y_pos,num[i][j].copy_soldier);
              for(int s = 0; s<= 2;s++)
              {
                   fprintf(fp,"%d %d %d %d %d %d %d %u %d %d %d %d ",num[i][j].vx[s],num[i][j].vy[s],num[i][j].is_move[s],num[i][j].is_attack[s],num[i][j].i[s],num[i][j].j[s],num[i][j].minus[s],num[i][j].color[s],num[i][j].copy_vx[s],num[i][j].copy_vy[s],num[i][j].is_torecieve[s],num[i][j].copy_istorecieve[s]);
                   for(int l = 0; l < 400;l++)
                   {
                       fprintf(fp,"%d %d %d %d %d ",num[i][j].x_soldier[s][l],num[i][j].y_soldier[s][l],num[i][j].soldier[s][l],num[i][j].isto_plus[s][l],num[i][j].is_continue[s][l]);
                   }

              }
          }
     }
     for(int s = 0; s< 4;s++)
     {
          fprintf(fp2,"%s %d %d %d %d",potions[s].str,potions[s].pos_x,potions[s].pos_y,potions[s].is_push,potions[s].time);
     }



    fclose(fp);
    fclose(fp1);
    fclose(fp2);

}

void upload_game(struct region num[20][20],struct color_militaries one[],struct potion potions[])
{
     FILE * fp = fopen("save_num.txt","r");
     FILE * fp1 = fopen("save_one.txt","r");
     FILE * fp2 = fopen("save_potion.txt","r");
  for(int i = 0; i < 20;i++)
     {
          for(int j = 0; j < 20;j++ )
          {
               fscanf(fp1,"%c %d %d %u",&one[0].c[i][j],&one[0].index_potion[i][j],&one[0].number_ofpotion[i][j],&one[0].color_arr[i][j]);
               fscanf(fp,"%s %d %d %d %d ",num[i][j].str,&num[i][j].soldiers,&num[i][j].x_pos,&num[i][j].y_pos,&num[i][j].copy_soldier);
              for(int s = 0; s<= 2;s++)
              {
                   fscanf(fp,"%d %d %d %d %d %d %d %u %d %d %d %d ",&num[i][j].vx[s],&num[i][j].vy[s],&num[i][j].is_move[s],&num[i][j].is_attack[s],&num[i][j].i[s],&num[i][j].j[s],&num[i][j].minus[s],&num[i][j].color[s],&num[i][j].copy_vx[s],&num[i][j].copy_vy[s],&num[i][j].is_torecieve[s],&num[i][j].copy_istorecieve[s]);
                   for(int l = 0; l < 400;l++)
                   {
                       fscanf(fp,"%d %d %d %d %d ",&num[i][j].x_soldier[s][l],&num[i][j].y_soldier[s][l],&num[i][j].soldier[s][l],&num[i][j].isto_plus[s][l],&num[i][j].is_continue[s][l]);
                   }

              }
          }
     }
     for(int s = 0; s< 4;s++)
     {
          fscanf(fp2,"%s %d %d %d %d",potions[s].str,&potions[s].pos_x,&potions[s].pos_y,&potions[s].is_push,&potions[s].time);
     }




    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}



void new_game(SDL_Renderer * sdlRenderer,const int SCREEN_WIDTH,const int SCREEN_HEIGHT,int r,Sint16 x_0,Sint16 y_0,struct color_militaries one[],struct name_order class[50],struct region num[20][20],struct potion potions[],char ptr[])
{
     
      short * array_x = (short *)malloc(6 * sizeof(short));
       short * array_y = (short *)malloc(6 * sizeof(short));

    int winning[4];
   
    first_appear(num,one,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0);
    
    int mouse_xfirst;
    int mouse_yfirst;
    int mouse_xsecond;
    int mouse_ysecond;

    int time = 1;
    SDL_bool shallExit = SDL_FALSE;
   while (shallExit == SDL_FALSE) 
   {
     
        SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
        showimg2(sdlRenderer,"saveandexitgame.bmp",300,35,100,60);
        number_of_each_region(num,one,SCREEN_WIDTH,SCREEN_HEIGHT,r,x_0,y_0);
        drawn_hexagonal(array_x,array_y,r,x_0,y_0,SCREEN_WIDTH,SCREEN_HEIGHT,sdlRenderer,one,num);  
        potionsion(SCREEN_WIDTH,SCREEN_HEIGHT,r,potions,num);
        checkPOT(potions,sdlRenderer);
        move_militaries(one,num,SCREEN_WIDTH,SCREEN_HEIGHT,sdlRenderer,r);
        collision(one,num,SCREEN_WIDTH,SCREEN_HEIGHT,r);
        
        to_check_on_potion(potions,num,one);
        go_for_potoion(potions,num,one);
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(200);
        if(time %  80== 0)
        {
          //   AI_GAME_G(num,one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
          //   moveforprotect(num,one,'B');
           //  moveforprotect(num,one,'P');
            // moveforprotect(num,one,'R');
           //  moveforprotect(num,one,'G');
        }
        if(time % 50 == 0)
        {
          // AI_GAME_P(num,one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
           //  moveforprotect(num,one,'B');
          //   moveforprotect(num,one,'P');
           //  moveforprotect(num,one,'R');
           //  moveforprotect(num,one,'G');
        }
        if(time % 110 == 0)
        {
             //AI_GAME_R(num,one,SCREEN_WIDTH,SCREEN_HEIGHT,r);
            // moveforprotect(num,one,'B');
            // moveforprotect(num,one,'P');
            // moveforprotect(num,one,'R');
              //moveforprotect(num,one,'G');

        }
        check_win(winning,one,num);
        switch(go_forscore(winning,num,one))
        {
             case 1:
                file_work(ptr,class,winning[0]);
               file_work("p",class,winning[1]);
               file_work("R",class,winning[2]);
               file_work("G",class,winning[3]);
               leaderboard(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
               return;
             break;

             case -1:
               file_work(ptr,class,-winning[0]);
               file_work("p",class,winning[1]);
               file_work("R",class,winning[2]);
               file_work("G",class,winning[3]);
               leaderboard(sdlRenderer,SCREEN_WIDTH,SCREEN_HEIGHT);
                return;
             break;
        }
        SDL_Event sdlEvent;
       time++;
        while(SDL_PollEvent(&sdlEvent))
        {
           switch(sdlEvent.type)
            {
                int ind1;
                int ind2;
                case SDL_QUIT:
                shallExit = SDL_TRUE;
                break;
                case SDL_MOUSEBUTTONDOWN:
                mouse_xfirst = sdlEvent.button.x;
                mouse_yfirst = sdlEvent.button.y;
                printf("%d %d\n",mouse_xfirst,mouse_yfirst);
                if(mouse_xfirst - 400 <= 100 &&mouse_xfirst - 400 >=  -100 && mouse_yfirst - 95 <= 50 && mouse_yfirst - 94 >= -50)
                {
                   save_game(num,one,potions);
                   return;
                }
                checkout(&mouse_xfirst,&mouse_yfirst,30,num,&ind1,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                printf("%d %d\n",mouse_xfirst,mouse_yfirst);  
                break;
                case SDL_MOUSEBUTTONUP:
                mouse_xsecond = sdlEvent.button.x;
                mouse_ysecond = sdlEvent.button.y;
                printf("%d %d\n",mouse_xsecond,mouse_ysecond);
                checkout(&mouse_xsecond,&mouse_ysecond,35,num,&ind2,SCREEN_WIDTH,SCREEN_HEIGHT,r);
                printf("%d %d\n",mouse_xsecond,mouse_ysecond);
                   switch(ind1 * ind2)
                    {
                         case 1:
                          if((mouse_ysecond != mouse_yfirst || mouse_xsecond != mouse_xfirst) && (one[0].c[mouse_xfirst][mouse_yfirst] == 'B'))
                              {
                                  // printf("1\n");
                                    for(int s= 0;s <= 2;s++)
                                    {
                                         if(num[mouse_xfirst][mouse_yfirst].is_move[s] == false &&  num[mouse_xfirst][mouse_yfirst].is_attack[s] == false)
                                         {
                                               num[mouse_xfirst][mouse_yfirst].is_move[s] = true;
                                               num[mouse_xfirst][mouse_yfirst].is_attack[s] = true;
                                               num[mouse_xfirst][mouse_yfirst].i[s] = mouse_xsecond;
                                               num[mouse_xfirst][mouse_yfirst].j[s] = mouse_ysecond;
                                               set_move(num,mouse_xfirst,mouse_xsecond,mouse_yfirst,mouse_ysecond,s);
                                              rate_seting(num,mouse_xfirst,mouse_xsecond,mouse_yfirst,mouse_ysecond,s);
                                              num[mouse_xfirst][mouse_yfirst].is_torecieve[s] = num[mouse_xfirst][mouse_yfirst].copy_soldier;
                                               num[mouse_xfirst][mouse_yfirst].copy_istorecieve[s] = num[mouse_xfirst][mouse_yfirst].copy_soldier;
                                              num[mouse_xfirst][mouse_yfirst].copy_soldier = 0;
                                              switch(one[0].c[mouse_xfirst][mouse_yfirst])
                                              {
                                                  case 'B':
                                                  num[mouse_xfirst][mouse_yfirst].color[s] = 0xeeff3434;
                                                  break;
                                                  case 'G':
                                                  num[mouse_xfirst][mouse_yfirst].color[s] = 0xff00ff00;
                                                  break;
                                                  case 'P':
                                                  num[mouse_xfirst][mouse_yfirst].color[s] = 0xffff6666;
                                                  break;
                                                  case 'R':
                                                  num[mouse_xfirst][mouse_yfirst].color[s] = 0xff6666ff;
                                                  break;
                                              }
                                              
                                              break;
                                         }
                                    }
                              } 
                             break;
                     }
                     break;
                }
        }  
        
       
   }
  free(array_y);
  free(array_x);

}


int goandcontinue3(int mouse_x,int mouse_y)
{
  if(mouse_x - 400 >= -50 &&  mouse_x - 400 <= 50 && mouse_y - 100 >= -50 && mouse_y - 100 <= 50)
  {
    return 0;
  }
  else if(mouse_x - 400 >= -50 &&  mouse_x - 400 <= 50 && mouse_y - 250 >= -50 && mouse_y - 250 <= 50)
  {
    return 1;
  }
  else if(mouse_x - 400 >= -50 &&  mouse_x - 400 <= 50 && mouse_y - 400 >= -50 && mouse_y - 400 <= 50)
  {
     return 2;
  }

  return -1;
}


int show_maps_in(SDL_Renderer * sdlRenderer)
{
      SDL_bool shallExit = SDL_FALSE;
   while (shallExit == SDL_FALSE) 
   {
        SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
        showimg(sdlRenderer,"leaderboard.png",0,0,800,640);
        showimg2(sdlRenderer,"one.bmp",350,50,100,100);
        showimg2(sdlRenderer,"two.bmp",350,200,100,100);
        showimg2(sdlRenderer,"three.bmp",350,350,100,100);
        SDL_RenderPresent(sdlRenderer);
        SDL_Event sdlEvent;
        int mouse_x;
        int mouse_y;
        while(SDL_PollEvent(&sdlEvent))
        {
           switch(sdlEvent.type)
            {
                 case SDL_QUIT:
                 shallExit = SDL_TRUE;
                 break;
                 case SDL_MOUSEBUTTONDOWN:
                 mouse_x = sdlEvent.button.x;
                 mouse_y = sdlEvent.button.y;
                 if(goandcontinue3(mouse_x,mouse_y) != -1)
                 {
                      return(goandcontinue3(mouse_x,mouse_y));
                 }
                 break;

            }

        }
   }


}



int goandcontinue34(int mouse_x,int mouse_y)
{
  if(mouse_x - 400 >= -100 &&  mouse_x - 400 <= 100 && mouse_y - 250 >= -50 && mouse_y - 250 <= 50)
  {
    return 0;
  }
  

  return -1;
}




int show_save_randomampe(SDL_Renderer * sdlRenderer)
{
        SDL_bool shallExit = SDL_FALSE;
   while (shallExit == SDL_FALSE) 
   {
        SDL_SetRenderDrawColor(sdlRenderer, 0xee, 0xee, 0xee, 0xee);
        SDL_RenderClear(sdlRenderer);
        showimg(sdlRenderer,"leaderboard.png",0,0,800,640);
        showimg2(sdlRenderer,"save_map.bmp",300,200,200,100);
        SDL_RenderPresent(sdlRenderer);
        SDL_Event sdlEvent;
        int mouse_x;
        int mouse_y;
        while(SDL_PollEvent(&sdlEvent))
        {
           switch(sdlEvent.type)
            {
                 case SDL_QUIT:
                 shallExit = SDL_TRUE;
                 break;
                 case SDL_MOUSEBUTTONDOWN:
                 mouse_x = sdlEvent.button.x;
                 mouse_y = sdlEvent.button.y;
                 return(goandcontinue34(mouse_x,mouse_y));
                 break;

            }

        }
   }
   return -3;
}
