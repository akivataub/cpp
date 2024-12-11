#include <iostream>
#include <SDL2/SDL.h>
int x12 = 1;
int y12 = 1;
int w = 10;
int h = 10;

int main(int argc, char* argv[]) {
SDL_Window* window = NULL;
SDL_Renderer* ren = NULL;
SDL_Init( SDL_INIT_EVERYTHING );

window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);


ren = SDL_CreateRenderer(window, -1, 0);
SDL_Event event;
bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = false;
				} 
				
				else if (event.type == SDL_KEYDOWN) {
                if (x12 < 0){
                    x12 = 0;
                } 
                if (x12 + w > 1280){ 
                    x12 = 1280 - w; 
                } 
                if (y12 < 0){ 
                        y12 = 0;
                } 
                if (y12 + h > 720){ 
                    y12 = 720 - h; 
                }
                if (event.key.keysym.sym == SDLK_a) {
                    x12 = x12 - 10;
                }

                if (event.key.keysym.sym == SDLK_d){
                    x12 = x12 + 10;
                }
                }
            }
        }
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Set draw color to red
        SDL_RenderClear(ren); // Clear the renderer
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); // Set draw color to red
        SDL_Rect rect = {x12, y12, w, h}; 
        SDL_RenderFillRect(ren, &rect); // Draw the rectangle
        SDL_RenderPresent(ren);	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
    return 0;
}