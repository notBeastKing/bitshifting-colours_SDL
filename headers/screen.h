#ifndef SCREEN__H
#define SCREEN__H

// #pragma once

#include<SDL2/SDL.h>
#include<iostream>

using namespace std;
namespace dingus
{
class screan
{
     public:
        int const width = 1200; //screen width and height
        int const height = 800;
    

    private:        // creating variables
        SDL_Window *m_window;
        SDL_Renderer *m_renderwin;
        SDL_Texture *m_texturewin;
        Uint32 *m_buffer = new Uint32[width * height];

    public: //functions
    screan();
    bool createscreen();
    bool create_rend_texture();
    void setbuffer(int color);
    void screen_update();
    void setpixel(int x, int y, Uint8 red, Uint8 blue, Uint8 green);
    bool process_events();
    void close();
};
}


 #endif

//instead of using header gaurds we can use #pragma once