/**  
* @file main.c  
* @brief Testing Program.  
* @author C Team  
* @version 0.1  
* @date Apr 20, 2021  
*  
* Testing program for enemy *  
*/



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"


int main(char argc, char argv[])
{

    Enemy Ennemie;
hero h;
   int l;
int done =1;

SDL_Event event;     

SDL_Rect positionbg;
SDL_Surface *imageDeFond = NULL;
positionbg.x=0;
positionbg.y=0;
SDL_Surface *screen =NULL;
imageDeFond=IMG_Load("back.png");
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1200,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


Ennemie=InitEnemy(Ennemie);
h=inithero(h);
while(done)
{ 
  

   if(SDL_PollEvent(&event))
   {
     switch(event.type)
{
case SDL_QUIT:
done = 0;
break;
}
   }

     SDL_BlitSurface(imageDeFond, NULL, screen, &positionbg);
  SDL_BlitSurface(h.hero1, NULL, screen, &h.poshero);


     AfficherEnemy(Ennemie,screen);
 l=colusion(  Ennemie ,h );
    Ennemie=AnimateEnemy(Ennemie,l);

  Ennemie=moveenemy(Ennemie ,l);


    
     
SDL_Flip(screen);
}

 


SDL_FreeSurface(screen);
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(h.hero1);
SDL_Quit();

return 0;
 

}

