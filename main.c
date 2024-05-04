#include <stdbool.h>

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>


int main(void)
{
    // initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // stuff for OpenGL compatibility
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // define window dimension and title
    SDL_Window* window = SDL_CreateWindow("Hello, world!", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE);

    // initialize OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // start app main event loop
    SDL_Event windowEvent;

    // initialize glew
    glewExperimental = GL_TRUE;
    glewInit();

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
        }
        SDL_GL_SwapWindow(window);

        //GLuint vertexBuffer;
        //glGenBuffers(1, &vertexBuffer);
        //printf("%u\n", vertexBuffer);
    }

    // FIX: glGenBuffers causes segfault WHY?
    // draw object 
    //GLuint vertexBuffer;
    //glGenBuffers(1, &vertexBuffer);
    //printf("%u\n", vertexBuffer);

    SDL_GL_DeleteContext(context);
    SDL_Quit();

    return 0;
}

