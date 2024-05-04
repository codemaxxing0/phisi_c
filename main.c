#include <stdbool.h>

#include <SDL.h>
#include <SDL_opengl.h>

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);

    // stuff for compatibility
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window* window = SDL_CreateWindow("Hello, world!", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE);

    // start context
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // app main event loop
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
        }

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_Quit();

    return 0;
}

