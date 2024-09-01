#include "headers.h"

int window_making()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "there is an error with SDL\n");
        return 0;
    }
    window = SDL_CreateWindow(
        "who cares about what's written here anyway!",
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
/////////////////////////////////////////////////////////////////////////////////////////////////////
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
    }
    return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
    ball.x = WINDOW_WIDTH / 2;
    ball.y = WINDOW_HEIGHT / 2;
    ball.w = 15;
    ball.h = 15;

    racket.x = 0;
    racket.y = WINDOW_HEIGHT / 2;
    racket.w = 10;
    racket.h = 100;

    racket2.x = WINDOW_WIDTH - 10;
    racket2.y = WINDOW_HEIGHT / 2;
    racket2.w = 10;
    racket2.h = 100;

    midline.x = WINDOW_WIDTH / 2;
    midline.y = 0;
    midline.w = 10;
    midline.h = WINDOW_WIDTH;

    topline.x = 0;
    topline.y = 0;
    topline.w = WINDOW_WIDTH;
    topline.h = 10;
    
    bottomline.x = 0;
    bottomline.y = WINDOW_HEIGHT - 10;
    bottomline.w = WINDOW_WIDTH;
    bottomline.h = 10;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void cleaning()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void update()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    //wasting time to see what actually is going on in the screen..
    if(!time_to_wait && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void background_img()
{
    surface = IMG_Load("src/ss.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer,texture,NULL,NULL);

}
////////////////////////////////////////////////////////////////////////////////////////////////////
void keyboard_input()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if(state[SDL_SCANCODE_W] && racket.y > 0)
        racket.y -= 20;                          // the size of the racket is 100.
    if(state[SDL_SCANCODE_S] && racket.y < WINDOW_HEIGHT - 100)
        racket.y += 20;
    if(state[SDL_SCANCODE_I] && racket2.y > 0)
        racket2.y -= 20;
    if(state[SDL_SCANCODE_K] && racket2.y < WINDOW_HEIGHT - 100)
        racket2.y += 20;

}
////////////////////////////////////////////////////////////////////////////////////////////////////
void ballcont()
{
    ball.x += ballspeedX;
    ball.y += ballspeedY;
    //reverse if the ball touches the edges
    if (ball.y <= 0 || ball.y >= WINDOW_HEIGHT - 15)
        ballspeedY = -ballspeedY;

    if ((SDL_HasIntersection(&ball, &racket) || SDL_HasIntersection(&ball, &racket2)))
    //|| ((SDL_HasIntersection(&ball, &bottomline) || SDL_HasIntersection(&ball, &topline))))
        ballspeedX *= -1;

    if (ball.x < 0 || ball.x > WINDOW_WIDTH)
    {
        ball.x = WINDOW_WIDTH / 2;
        ball.y = WINDOW_HEIGHT / 2;
        ballspeedX = ballspeed_x;
        ballspeedY = ballspeed_y;
    }

}
/// ////////////////////////////////////////////////////////////////////////////////////////////////
void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 49, 50);
    SDL_RenderClear(renderer);

    background_img();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball);
    SDL_RenderFillRect(renderer, &racket);
    SDL_RenderFillRect(renderer, &racket2);
    SDL_RenderFillRect(renderer, &midline);
    SDL_RenderFillRect(renderer, &bottomline);
    SDL_RenderFillRect(renderer, &topline);
    ballcont();
    keyboard_input();

    SDL_RenderPresent(renderer);
}
