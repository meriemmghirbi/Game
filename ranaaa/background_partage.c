#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background_partage.h"


void initcamera ( camera* c )
{
    c->camera.x=0;
    c->camera.y=0;
    c->camera.h=688;
    c->camera.w=800;
}

void init_background(background* bg)
{
    bg->background_1 = IMG_Load("background.png");
    bg->background_2 = IMG_Load("background.png");
    bg->pos_bg1.x = 0;
    bg->pos_bg1.y = 0;
    bg->pos_bg2.x = 400;
    bg->pos_bg2.y = 0;
}

void scrolling_right (camera* c)
{
       c->camera.x++;
}
void scrolling_up (camera* c)
{
       c->camera.y--;
}
void scrolling_down (camera* c)
{  


c->camera.y++;

    
}

void scrolling_left (camera* c)
{
   c->camera.x--;
}

void blit_bg1(camera* c1,SDL_Surface *screen,background *bg)
{
	SDL_BlitSurface(bg->background_1 , &c1->camera , screen , &bg->pos_bg1 ); 
	
}


void blit_bg2(camera* c2,SDL_Surface *screen,background *bg)

{
	SDL_BlitSurface(bg->background_2 , &c2->camera , screen , &bg->pos_bg2 ); 
	
}

void free_surface_bg_partage(background* bg)
{
	SDL_FreeSurface(bg->background_1);
	SDL_FreeSurface(bg->background_2);
	
}
void musique()//juste hot musique f blaset musique.mp3
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1);//-1:boucle infinie

}

