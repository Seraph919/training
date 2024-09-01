#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define TRUE 1
#define FALSE 0
#define FPS 144
#define FRAME_TARGET_TIME (1000 / FPS)
#define ballspeed_x 5
#define ballspeed_y 5
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// this extern fixes the rediffinition of the variables..
// it makes you declare them here and give them a value in one of the C files.
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Surface *surface;
extern SDL_Texture *texture;
extern int last_frame_time;
extern int condition;
extern float delta_time;
extern SDL_Rect ball;
extern SDL_Rect racket;
extern SDL_Rect midline;
extern SDL_Rect racket2;
extern SDL_Rect bottomline;
extern SDL_Rect topline;
extern int ballspeedX;
extern int ballspeedY;

void process_inpute();
int window_making();
void setup();
void cleaning();
void update();
void render();

#endif