 


#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/**  
* @struct enemy 
* @brief struct for enemy
*/  

typedef struct
{
  SDL_Surface *image[3]; /*!< Surface. */
  SDL_Surface *image2[3]; /*!< Surface. */
   SDL_Surface *imageActuel; /*!< Surface. */
SDL_Surface *Hit; /*!< Surface. */
  SDL_Rect position; /*!< Rectangle*/ 

 
   int frame;
  int direction;
int speed;

}Enemy;
typedef struct
{
SDL_Surface *hero1;
SDL_Rect  poshero; 
}
hero;




hero inithero( hero h);
Enemy InitEnemy(Enemy Ennemie);
void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
Enemy AnimateEnemy(Enemy Ennemie , int l);
int colusion( Enemy Ennemie , hero h  );
Enemy moveenemy(Enemy Ennemie , int l  );

#endif
