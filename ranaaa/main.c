#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "background_partage.h"



int main(int argc,char **argv[])
{
    SDL_Surface* screen=NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    camera c1,c2;
    initcamera (&c1);
    initcamera (&c2);

    background bg;
    init_background (&bg);


    int continuer = 1;


 
    SDL_Event event;
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
     musique();
    while(continuer!=0)
    {
	

	SDL_PollEvent(&event);
            switch(event.type)
            {

            case SDL_QUIT:
                continuer=0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                case SDLK_ESCAPE:
                    continuer=0;
                    break;

                case SDLK_RIGHT:
                    	scrolling_right (&c1);
                    break;
                    
                 case SDLK_UP:
                    	scrolling_up(&c1);
                    break;
                    
                     case SDLK_DOWN:
                    	scrolling_down (&c1);
                    break;


                case SDLK_LEFT :
                    	scrolling_left (&c1);
                    break;

		case SDLK_d:
                    	scrolling_right (&c2);
                    break;
                    case SDLK_z:
               scrolling_up (&c2);
                    break;
                    case SDLK_s:
               scrolling_down (&c2);
                    break;
                case SDLK_q :
                    	scrolling_left (&c2);
                    break;

                }
                break;

            }



	blit_bg1(&c1,screen,&bg);
	blit_bg2(&c2,screen,&bg);
        SDL_Flip(screen);
       
    }
	free_surface_bg_partage(&bg);
     

	return EXIT_SUCCESS;

}


