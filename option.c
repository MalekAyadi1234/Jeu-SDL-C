#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "option.h"

/*
SDL_Rect option_menu(SDL_Surface *screen, int *Volume,SDL_Rect posboutton)
{
	SDL_Surface *option[2],*bg,*escape;
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	int n=0,q=1;
	SDL_Event event;

	bg=IMG_Load("bg/bqck.png");
	option[0]=IMG_Load("option/fullscreen.png");
	option[1]=IMG_Load("option/sound.png");
	escape=IMG_Load("boutton/echaptoreturn.png");
	do{
	SDL_BlitSurface(bg,NULL,screen,&pos);
	SDL_BlitSurface(escape,NULL,screen,&pos);
	SDL_BlitSurface(option[n],NULL,screen,&pos);
	SDL_Flip(screen);
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					if (n==0)
					{
						n++;
					}
					else{
						n--;
					}
				break;

				case SDLK_DOWN:
					if (n==1)
					{
						n--;
					}
					else{
						n++;
					}
				break;

				case SDLK_RETURN:
					if (n==0)
					{
						screen=fullscreen_menu(screen);
					}
					else{
						posboutton=sound(screen,Volume,posboutton);
					}
				break;
			}
		case SDL_MOUSEMOTION:
			if (event.motion.x>170 && event.motion.y>130 && event.motion.x<630 && event.motion.y<210 && n==1)
			{
				n=0;
			}
			else if (event.motion.x>170 && event.motion.y>270 && event.motion.x<630 && event.motion.y<350 && n==0)
			{
				n=1;
			}
		break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button==SDL_BUTTON_LEFT)
			{
				if (event.motion.x>0 && event.motion.y>0 && event.motion.x<230 && event.motion.y<50)
				{
						q=0;
				}
				else if (event.motion.x>170 && event.motion.y>130 && event.motion.x<630 && event.motion.y<210)
				{
					screen=fullscreen_menu(screen);
				}
				else if (event.motion.x>170 && event.motion.y>270 && event.motion.x<630 && event.motion.y<350)
				{
					posboutton=sound(screen,Volume,posboutton);
				}
			}
		break;
	}
 	}while(event.key.keysym.sym!=SDLK_ESCAPE && q==1);
 	SDL_FreeSurface(option[0]);
 	SDL_FreeSurface(option[1]);
 	return posboutton;
}

SDL_Surface  *fullscreen_menu(SDL_Surface *screen)
{
	SDL_Surface *fullscreen[2],*bg;
	SDL_Event event;
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	int n=0,t=0;
	bg=IMG_Load("bg/bqck.png");
	fullscreen[0]=IMG_Load("option/yes.png");
	fullscreen[1]=IMG_Load("option/no.png");
	do
	{
		SDL_BlitSurface(bg,NULL,screen,&pos);
		SDL_BlitSurface(fullscreen[n],NULL,screen,&pos);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		t=0;
		switch(event.type)
    	{
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{
							screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);

						}
						else if (n==1)
						{
							screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
							SDL_QUIT;

						}
						SDL_FreeSurface(fullscreen[n]);
						return screen;
					break;
				}
			break;

			case SDL_MOUSEMOTION:
				if (event.motion.x>210 && event.motion.y>250 && event.motion.x<360 && event.motion.y<330 && n==1)
				{
					n=0;
				}
				else if (event.motion.x>460 && event.motion.y>250 && event.motion.x<640 && event.motion.y<330 && n==0)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>210 && event.motion.y>250 && event.motion.x<360 && event.motion.y<330)
				{
					screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
				}
				else if (event.motion.x>460 && event.motion.y>250 && event.motion.x<640 && event.motion.y<330)
				{
					screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
				}
				return screen;
			break;
		}
	}while(event.key.keysym.sym!=SDLK_ESCAPE);


}

SDL_Rect sound(SDL_Surface *screen , int * Volume,SDL_Rect posboutton)
{
	SDL_Surface *boutton, *barre,*bg;
	SDL_Rect posbarre,posbg;
	SDL_Event event;
	int MAX_VOLUME,MIN_VOLUME;
	boutton=IMG_Load("option/Button.png");
	barre=IMG_Load("option/Barre.png");
	bg=IMG_Load("bg/bqck.png");
	posbg.x=0;
	posbg.y=0;
	posbarre.x=180;
	posbarre.y=0;
	MAX_VOLUME=posbarre.x+150;
	MIN_VOLUME=posbarre.x-220;

	do
	{
		SDL_BlitSurface(bg,NULL,screen,&posbg);
		SDL_BlitSurface(barre,NULL,screen,&posbarre);
		SDL_BlitSurface(boutton,NULL,screen,&posboutton);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:
						if (posboutton.x>MIN_VOLUME && *Volume>0)
						{
							posboutton.x=posboutton.x-90;
							*Volume=*Volume-32;
							Mix_VolumeMusic(*Volume);
						}
					break;
					case SDLK_RIGHT:
						if (posboutton.x<MAX_VOLUME && *Volume<128)
						{
							posboutton.x=posboutton.x+90;
							*Volume=*Volume+32;
							Mix_VolumeMusic(*Volume);
						}
					break;

				}
			break;
		}
		SDL_FillRect(screen,&posboutton,SDL_MapRGB(screen->format ,0, 0 ,0 ));


	}while(event.key.keysym.sym!=SDLK_ESCAPE);
	return posboutton;

}
*/


int fullscreen(SDL_Surface *ecran)
{
	SDL_Surface *bg,*sure[5],*full_screen,*keys;
	int n=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	full_screen=IMG_Load("graphic/full-screen-normal.png");
	keys=IMG_Load("graphic/key-settings-normal.png");
	bg=IMG_Load("graphic/back.jpg");
	sure[4]=IMG_Load("graphic/sure_msg.png");
    sure[0]=IMG_Load("graphic/sure_msg_yes_selected.png");
	sure[1]=IMG_Load("graphic/sure_msg_no_selected.png");
	sure[2]=IMG_Load("graphic/sure_msg_yes_clicked.png");
	sure[3]=IMG_Load("graphic/sure_msg_no_clicked.png");

    while(1)
    {
    	SDL_BlitSurface(bg,NULL,ecran,&pos);
    	SDL_BlitSurface(full_screen,NULL,ecran,&pos);
    	SDL_BlitSurface(keys,NULL,ecran,&pos);
    	SDL_BlitSurface(sure[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	t=0;
    	switch(event.type)
    	{
			//avec clavier
    		case SDL_KEYDOWN:

    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
    				if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
					if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{SDL_BlitSurface(sure[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (100);								ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
    				return 0;
						}
						else if (n==1)
						{SDL_BlitSurface(sure[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (100);
							SDL_FreeSurface(bg);
							SDL_FreeSurface(sure[n]);
							return 0;
						}
					break;
						    			}
    		break;

// avec souris
    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					SDL_BlitSurface(sure[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (100);								ecran=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
				return 0;}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					SDL_BlitSurface(sure[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (100);
					return 0;
				}
			break;
    	}
    }
}

void options(SDL_Surface *screen)
{

SDL_Surface *background,*boutton_sfx[6],*boutton_music[6],*full_screen[3],*keys[3],*music[2],*sfx[2];
	int m=1,s=0,ks=0,fs=0,t,n=1,q=1,p_sfx=5,volume_sfx=100,p_music=5,volume_music=100,mp=0;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	full_screen[0]=IMG_Load("graphic/full-screen-normal.png");
	//full_screen[1]=IMG_Load("graphic/full-screen-selected.png");
	full_screen[1]=IMG_Load("graphic/full-screen-clicked.png");
	keys[0]=IMG_Load("graphic/key-settings-normal.png");
	//keys[1]=IMG_Load("graphic/key-settings-selected.png");
keys[1]=IMG_Load("graphic/key-settings-clicked.png");
	background=IMG_Load("graphic/back.jpg");
	music[0]=IMG_Load("graphic/music-normal.png");
   music[1]=IMG_Load("graphic/music-selected.png");
	sfx[1]=IMG_Load("graphic/sfx-selected.png");
	sfx[0]=IMG_Load("graphic/sfx-normal.png");

	boutton_sfx[0]=IMG_Load("graphic/sfx0.png");
	boutton_sfx[1]=IMG_Load("graphic/sfx20.png");
	boutton_sfx[2]=IMG_Load("graphic/sfx40.png");
	boutton_sfx[3]=IMG_Load("graphic/sfx60.png");
	boutton_sfx[4]=IMG_Load("graphic/sfx80.png");
	boutton_sfx[5]=IMG_Load("graphic/sfx100.png");

	boutton_music[0]=IMG_Load("graphic/music0.png");
	boutton_music[1]=IMG_Load("graphic/music20.png");
	boutton_music[2]=IMG_Load("graphic/music40.png");
	boutton_music[3]=IMG_Load("graphic/music60.png");
	boutton_music[4]=IMG_Load("graphic/music80.png");
	boutton_music[5]=IMG_Load("graphic/music100.png");

//init sfx
	Mix_Music *sfx_sound;
	sfx_sound= Mix_LoadMUS("graphic/transition.mp3");
//init music
Mix_Music *music_sound;
music_sound= Mix_LoadMUS("graphic/background.mp3");
Mix_VolumeMusic(volume_music);
Mix_PlayMusic(music_sound,-1);

	do{
	//affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
    SDL_BlitSurface(full_screen[fs],NULL,screen,&pos);
    SDL_BlitSurface(sfx[s],NULL,screen,&pos);
    SDL_BlitSurface(music[m],NULL,screen,&pos);
      SDL_BlitSurface(keys[ks],NULL,screen,&pos);
				SDL_BlitSurface(boutton_sfx[p_sfx],NULL,screen,&pos);
					SDL_BlitSurface(boutton_music[p_music],NULL,screen,&pos);
    SDL_Flip(screen);

    	t=0;
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{

    				case SDLK_UP:

						if (m==0 && s==0 && fs==0 && ks==0)
    				{s=1;}
    					if (m==1 && t==0){

    						ks=1;
    						m=0;
    				fs=0;
    						s=0;
    						t=1;
    						n=3;
    					}
    					else if(s==1 && t==0){
									if (mp==1) 	Mix_PlayMusic(music_sound,-1);
                                m=1;
                                s=0;
                                ks=0;
                                fs=0;
                                t=1;
                n=1;
										      	}
    					else if (ks==1 && t==0){
    						s=1;
    						ks=0;
    					fs=0;
    						m=0;
    						t=1;
    		n=2;
    					}
                        else if (fs==1 && t==0)
                        {
                            s=1;
                            fs=0;
                            m=0;
                            ks=0;
                            t=1;
            n=2;
}
    				break;

    				case SDLK_DOWN:

    				if (m==0 && s==0 && ks==0 && fs==0)
    				{ks=1;}
    					if (m==1 && t==0){

                                m=0;
                                s=1;
                                ks=0;
                                fs=0;
                           n=2;
    					}
    					else if(s==1 && t==0){
								if (mp==1) 	Mix_PlayMusic(music_sound,-1);
    						m=0;
    						s=0;
    						ks=1;
    						fs=0;
    						t=1;
    						n=3;
							}
    					else if (ks==1 && t==0){
    						ks=0;
    						fs=0;
    						m=1;
    						s=0;
    						t=1;
    						 n=1;

							}
                        else if (fs==1 && t==0)
                        {
                            ks=0;
                            s=0;
                            m=1;
                            fs=0;
                            t=1;
                             n=1;

									      }
    				break;
    				case SDLK_LEFT:
						if (n==1){
						if (volume_music>0)
						{
							p_music--;
							volume_music-=20;
						Mix_VolumeMusic(volume_music);
						}}
						else if (n==2){
						if (volume_sfx>0)
						{
							p_sfx--;
							volume_sfx-=20;
							mp=1;
						Mix_VolumeMusic(volume_sfx);
						Mix_PlayMusic(sfx_sound,1);
						}}
    			else	if(n==3)	{
						if (ks==0 && t==0)
						{
							fs--;
							ks++;
							t=1;
						}
						else if (ks==1 && t==0)
						{
							fs++;
							ks--;
							t=1;
						}
						}
					break;

					case SDLK_RIGHT:
					if (n==1){
					if (volume_music<100)
					{
						p_music++;
						volume_music+=20;
					Mix_VolumeMusic(volume_music);
					}}
				else	if (n==2){
					if (volume_sfx<100)
					{
						p_sfx++;
						volume_sfx+=20;
						mp=1;
						Mix_VolumeMusic(volume_sfx);
						Mix_PlayMusic(sfx_sound,1);
					}}
					else if(n==3)	{
						if (ks==0 && t==0)
						{
							fs--;
							ks++;
							t=1;
						}
						else if (ks==1 && t==0)
						{
							fs++;
							ks--;
							t=1;
						}
						}
					break;

    				case SDLK_RETURN:

    					if (ks==1)
    					{
    						SDL_BlitSurface(keys[1],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
    					//non definie
    					}
                        else if (fs==1)
                        {
                          SDL_BlitSurface(full_screen[1],NULL,screen,&pos);
    						SDL_Flip(screen);
    						SDL_Delay(100);
                          fullscreen(screen);
                        }
    				break;
    			}
    		break;

//avec souris
   		case SDL_MOUSEMOTION:
	if (mp==1) 	Mix_PlayMusic(music_sound,-1);
	mp=0;
    				m=0;
    				s=0;
    				fs=0;
    				ks=0;
    			if (event.motion.x>60 && event.motion.y>195 && event.motion.x<910 && event.motion.y<250)
    			{
    			m=1;

    			}

    			else if (event.motion.x>60 && event.motion.y>310 && event.motion.x<910 && event.motion.y<360)
    			{

    				s=1;

    			}
    			else if (event.motion.x>65 && event.motion.y>440 && event.motion.x<420 && event.motion.y<560 )
    			{
    				ks=1;

    			}
    			else if (event.motion.x>580 && event.motion.y>440 && event.motion.x<940 && event.motion.y<560 )
    			{
    				fs=1;

    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    			if (event.motion.x>295 && event.motion.y>195 && event.motion.x<355 && event.motion.y<250)
						{
							if (volume_music>0)
							{
								p_music--;
								volume_music-=20;
							Mix_VolumeMusic(volume_music);

							}
    				//modife music ---
    				}

						else if (event.motion.x>845 && event.motion.y>195 && event.motion.x<905 && event.motion.y<250 )
							{
								if (volume_music<100)
								{
									p_music++;
									volume_music+=20;
									Mix_VolumeMusic(volume_music);

								}
							//modife music +++
						}
					else	if (event.motion.x>295 && event.motion.y>310 && event.motion.x<355 && event.motion.y<360)
							{
								if (volume_sfx>0)
								{mp=1;
									p_sfx--;
									volume_sfx-=20;
								Mix_VolumeMusic(volume_sfx);
		Mix_PlayMusic(sfx_sound,1);
								}
							//modife sfx ---
							}
    				else if (event.motion.x>845 && event.motion.y>310 && event.motion.x<905 && event.motion.y<360 )
							{
								if (volume_sfx<100)
								{mp=1;
									p_sfx++;
									volume_sfx+=20;
									Mix_VolumeMusic(volume_sfx);
									Mix_PlayMusic(sfx_sound,1);
								}
    					//modife sfx+++
    				}
    				else if (ks==1)
    				{
    				ks=2;
    				SDL_Delay (100);

    				}
    				else if (fs==1)
    				{
    			fs=2;
    				SDL_Delay (100);
					fullscreen(screen);
    				}
    				else if (event.motion.x>910 && event.motion.y>55 && event.motion.x<955 && event.motion.y<110 )
    			{
    				q= 0;

    			}
    			}
    		break;


    	}

    	}
 }

 	while(event.key.keysym.sym!=SDLK_ESCAPE &&q!=0);
 	SDL_FreeSurface(background);
    	SDL_FreeSurface(full_screen[0]);
    	SDL_FreeSurface(full_screen[1]);
    	//SDL_FreeSurface(full_screen[2]);
    	SDL_FreeSurface(keys[0]);
    	SDL_FreeSurface(keys[1]);
       // SDL_FreeSurface(keys[2]);
    	SDL_FreeSurface(music[1]);
    	SDL_FreeSurface(music[0]);
    	SDL_FreeSurface(sfx[1]);
    	SDL_FreeSurface(sfx[0]);
}
