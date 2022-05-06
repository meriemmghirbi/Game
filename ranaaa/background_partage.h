
#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED
#include <SDL/SDL_ttf.h>

struct camera
{
	SDL_Rect camera;
}; 
typedef struct camera camera;

struct background
{
	SDL_Surface* background_1,*background_2;
	SDL_Rect pos_bg1,pos_bg2;
        Mix_Music *son;
};
typedef struct background background;


void init_background(background* bg);
void initcamera ( camera* c);
void scrolling_right (camera* c);
void scrolling_up (camera* c);
void scrolling_down (camera* c);
void scrolling_left (camera* c);
void blit_bg1(camera* c1,SDL_Surface *screen,background *bg);
void blit_bg2(camera* c2,SDL_Surface *screen,background *bg);
void free_surface_bg_partage(background* bg);
void musique();

#endif // HERO_H_INCLUDED
