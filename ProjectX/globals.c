#include "headers.h"

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
int last_frame_time = 0;
int condition = 0;
float delta_time = 0;
SDL_Rect ball;
SDL_Rect racket;
SDL_Rect racket2;
SDL_Rect midline;
SDL_Rect bottomline;
SDL_Rect topline;
int ballspeedX = ballspeed_x;
int ballspeedY = ballspeed_y;