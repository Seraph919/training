#include "headers.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int last_frame_time = 0;
int condition = 0;
float delta_time = 0;

int window_making()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "there is an error with SDL\n");
        return 0;
    }
    window = SDL_CreateWindow(
        "THE TITLE IS THE TITLE",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        0);
    if (!window)
    {
        fprintf(stderr, "We coudn't create the window..\n");
        return 0;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    return 1;
}

void process_inpute()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            condition = FALSE;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {    
                condition = FALSE;
                break;
            }
            if(event.key.keysym.sym == SDLK_DOWN)
            {
                midline.width += 100;
                break;
            }
    
    }
    return;
}
void setup()
{
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}
void cleaning()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void update()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    
    //wasting time to see what actually is going on in the screen..
    if(!time_to_wait && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);
    
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    // ^ this calculates how many miliseconds the program should wait to make a move.
    last_frame_time = SDL_GetTicks();

    ball.x += 30 * delta_time;
    ball.y += 20 * delta_time;
}
void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 49, 50);
    SDL_RenderClear(renderer);

    SDL_Rect ball_rect = 
    {
        ball.x,
        ball.y,
        ball.width,
        ball.height
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_Rect racket2 = 
    {
        racket.x = 1265,
        racket.y = 360,
        racket.height = 10,
        racket.width = 100
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &racket2);
    
    SDL_Rect racket1 = 
    {
        racket.x = 5,
        racket.y = 360,
        racket.height = 10,
        racket.width = 100
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &racket1);
    
    SDL_Rect midline = 
    {
        racket.x = 640,
        racket.y = 0,
        racket.height = 10,
        racket.width = 720
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &midline);

    SDL_RenderPresent(renderer);
}
