#include <stdbool.h>

#define GLEW_STATIC

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>


int main(void)
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("Unable to init SDL: %s\n", SDL_GetError());
            return 1;
        }

    // stuff for OpenGL compatibility
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // define window dimension and title
    SDL_Window* window = SDL_CreateWindow("Hello, world!", 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Unable to create renderer: %s\n", SDL_GetError());
        return 1;
    }

    // initialize OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        printf("Unable to create context: %s\n", SDL_GetError());
        return 1;
    }

    // initialize glew
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK){
        printf("Could not initialize glew.\n");
    }

    // start app main event loop
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT) break;
        }

        // draw object 
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        printf("%u\n", vertexBuffer);

        SDL_GL_SwapWindow(window);

    }

    SDL_GL_DeleteContext(context);
    SDL_Quit();

    return 0;
}

