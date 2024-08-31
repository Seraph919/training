#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0
#define FPS 240
#define FRAME_TARGET_TIME (1000 / FPS)

// this extern fixes the rediffinition of the variables..
// it makes you declare them here and give them a value in one of the C files.
extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern int last_frame_time;
extern int condition;
extern float delta_time;

struct ball
{
    float x;
    float y;
    float width;
    float height; 
} ball;

struct racket
{
    int x;
    int y;
    int width;
    int height;
}racket;

struct midline
{
    int x;
    int y;
    int width;
    int height;
}midline;

void process_inpute();
int window_making();
void setup();
void cleaning();
void update();
void render();

#endif