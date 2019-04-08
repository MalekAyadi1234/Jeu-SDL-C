#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "def.h"
#include "background.h"
#include "perssonage.h"
#include "jouer.h"
#include "mouvement.h"
#include "collision.h"
#include "coin.h"
#include "coeur.h"
#include "enemi.h"




#define gravity 9.81;
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 0.5
#define MAX_SPEED 5


void inisialiser_enemie (enemie *f)
{
f->enemie=IMG_Load("enemi/mummy.png");
f->rect.x=750;
f->rect.y=350;
f->rect.w=50;
f->rect.h=100;
f->frame=0;
f->state=0;
f->direction=0;
f->onground=0;
}

void MoveEnnemi(enemie *E)
{
        	if (E->direction==1)
        	{
        		E->rect.x -=1;

        	}
        	if(E->direction==2)
        	{
        		E->rect.x +=1;
        	}

}

void update_ennemi(enemie *E ,SDL_Surface *screen,SDL_Rect r)
{
	if (E->rect.x-r.x<=400 && E->rect.x-r.x >50)
	{
		E->direction=1;
		MoveEnnemi(E);
		printf("direction1\n");
	}

	else if (E->rect.x-r.x<=50 && E->rect.x-r.x>= -50 )
	{
		E->state=2; //state attacking
		printf ("attack\n");
	}
	else if (E->rect.x - r.x >= (-400) && E->rect.x -r.x < (-50))
	{
		E->direction=2;
		MoveEnnemi(E);
		printf("direction 2\n");
	}
	else
	{
		E->state=0; //state waiting
	}
	           gravite_enemi (screen,E);


}

void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos)
{
	SDL_BlitSurface(f->enemie,&f->rects[f->frame],screen,&pos);
}

void animation (enemie *p)
{

	p->frame++;
	if (p->frame>=5)
		p->frame=0;
}

/*********************************************************************************************************/
/*********************************************************************************************************/
void setrects_enemie(SDL_Rect* clip)
{
clip[0].x=0;
clip[0].y=0;
clip[0].w=53;
clip[0].h=98;

clip[1].x=53;
clip[1].y=0;
clip[1].w=52;
clip[1].h=98;

clip[2].x=105;
clip[2].y=0;
clip[2].w=51;
clip[2].h=98;

clip[3].x=156;
clip[3].y=0;
clip[3].w=56;
clip[3].h=98;

clip[4].x=212;
clip[4].y=0;
clip[4].w=58;
clip[4].h=100;

clip[5].x=270;
clip[5].y=0;
clip[5].w=56;
clip[5].h=102;


}