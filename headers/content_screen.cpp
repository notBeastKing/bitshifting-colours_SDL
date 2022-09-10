#include<screen.h>

namespace dingus
{
    screan::screan() {
        cout<<"constructor created"<<"\n";
    }

    bool screan::createscreen() //initializing video and creating a window
    {  
         if(SDL_Init(SDL_INIT_VIDEO) < 0)   {
            cout<<"video initialization didn't work"<<"\n";
                return false;
         }

            m_window = SDL_CreateWindow("class window", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 
            width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

            if(m_window < 0)
            {
                return false;
            }

            cout<<SDL_GetError()<<"\n";


         return true;
    }

    bool screan::create_rend_texture() //creating renderer and creating texture
    {
        m_renderwin = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
        m_texturewin = SDL_CreateTexture(m_renderwin, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width,height);

        if(m_texturewin < 0 || m_renderwin < 0)
        {
            return false;
        }

         cout<<SDL_GetError()<<"\n";

        return true;
    }

    void screan::setbuffer(int colour) //setting buffer
    {
        // memset(m_buffer, 122 , width*height*sizeof(Uint32));

        // auto color = SDL_Color();

        // color.r = 255;
        // color.g = 165;
        // color.b = 0;
        // color.a = 255;
        //  cout<<SDL_GetError()<<"\n";

        for(int i =0; i<width*height; i++)
    {
        m_buffer[i] =  colour;
    }  
    }

    bool screan::process_events() // updating and displaying and rendering textures
    {
        SDL_UpdateTexture(m_texturewin, NULL, m_buffer, width * sizeof(Uint32));
        SDL_RenderClear(m_renderwin);
        SDL_RenderCopy(m_renderwin,m_texturewin,NULL, NULL);
        SDL_RenderPresent(m_renderwin);
        
         cout<<SDL_GetError()<<"\n";

        return true;
    }

    void screan::close() //closing and destroying the buffer 
    {
        delete []m_buffer;
        SDL_DestroyTexture(m_texturewin);
        SDL_DestroyRenderer(m_renderwin);
        SDL_DestroyWindow(m_window);

         cout<<SDL_GetError()<<"\n";

        SDL_Quit();

    }

    void screan::screen_update()
    {
        
        SDL_UpdateTexture(m_texturewin, NULL, m_buffer, width * sizeof(Uint32));
        SDL_RenderClear(m_renderwin);
        SDL_RenderCopy(m_renderwin,m_texturewin,NULL, NULL);
        SDL_RenderPresent(m_renderwin);
        
    }

    void screan::setpixel(int x, int y, Uint8 red, Uint8 blue, Uint8 green)
    {
        Uint8 alpha = 0xFF;
        Uint32 colour = 0;

        colour +=alpha;
        colour <<=8;
        colour +=blue;
        colour <<=8;
        colour +=green;
        colour <<=8;
        colour +=red;
        colour <<=8;

        m_buffer[y * width + x] = colour; //x and y are the co ordinates
        

        


    }
}