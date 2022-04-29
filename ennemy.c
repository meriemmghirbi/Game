#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
Enemy InitEnemy(Enemy Ennemie)
{

  Ennemie.image[0]=IMG_Load("rpg1.png");
  Ennemie.image[1]=IMG_Load("rpg2.png");
  Ennemie.image[2]=IMG_Load("rpg3.png");
Ennemie.Hit=IMG_Load("imagedehit.png");


  Ennemie.image2[0]=IMG_Load("rpd1.png");
  Ennemie.image2[1]=IMG_Load("rpd2.png");
  Ennemie.image2[2]=IMG_Load("rpd3.png");
 
  Ennemie.imageActuel=Ennemie.image[0];

  

  Ennemie.position.x=50;
  Ennemie.position.y=500;
Ennemie.position.h=250;
Ennemie.position.w=100;

  Ennemie.speed=5;
  Ennemie.frame=0;   
  Ennemie.direction=0;   
                             
  return Ennemie;
}
hero inithero( hero h)
{
h.hero1=IMG_Load("d5alte fi 7it.jpg");
h.poshero.x=1000;
h.poshero.y=500;
h.poshero.h=250;
h.poshero.w=100;
return h;
}

void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen)

{ 

  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
//SDL_BlitSurface(Ennemie.Hit,NULL,screen,&Ennemie.position);

}

Enemy AnimateEnemy(Enemy Ennemie, int l ){

  if (Ennemie.frame==2) {
    Ennemie.frame=0;
  }
  else
  Ennemie.frame++;
	if (Ennemie.direction==0)
 	 	Ennemie.imageActuel=Ennemie.image[Ennemie.frame];
else if(Ennemie.direction==1)
	 	 Ennemie.imageActuel=Ennemie.image2[Ennemie.frame];
  if(l==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}

Enemy moveenemy(Enemy Ennemie , int  l )
{

  int PosMax=1000;
  int PosMin=0;

if (l==1)
Ennemie.speed=0;


 if (Ennemie.direction==0&&Ennemie.position.x <PosMax) 
Ennemie.position.x+=Ennemie.speed;
 if (Ennemie.direction==0&&Ennemie.position.x== PosMax)

	Ennemie.direction=1;

if (Ennemie.direction==1&&Ennemie.position.x>0) 
Ennemie.position.x-=Ennemie.speed ;
if (Ennemie.direction==1&&Ennemie.position.x== 0)

	Ennemie.direction=0;



return Ennemie;
}
int colusion( Enemy Ennemie , hero h  )  
{
    int col=0;
   if 
    ((h.poshero.x + h.poshero.w< Ennemie.position.x) || (h.poshero.x>  Ennemie.position.x +  Ennemie.position.w) ||
(h.poshero.y + h.poshero.h<  Ennemie.position.y) || (h.poshero.y>  Ennemie.position.y +  Ennemie.position.h ))


col = 0 ;
else

col= 1;

return col;
}

void deplacerIA( Enemy Ennemie, SDL_Rect  poshero)
{
int distEH;
if ((posHero.x+posHero.w)<=(Ennemie->posEcran).x)
distEH=(Ennemie->posEcran).x-(posHero.x+posHero.w);
if ((Ennemie->posEcran).x+(Ennemie->posEcran).w<=posHero.x)
distEH=posHero.x-((Ennemi->posEcran).x+(Ennemie->posEcran).w);
updateEtatEnnemie(Ennemie,distEH);
deplacer(Ennemie,posHero);
}






