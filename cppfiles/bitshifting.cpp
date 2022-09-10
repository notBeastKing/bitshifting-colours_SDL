#include<iostream>
#include<screen.h>
#include<iomanip>

using namespace std;
using namespace dingus;

int main(int argc, char *argv[])
{
    //the way colours are taken in hex for RGBA32 pixelformatin SDL is 
    // 0xAABBGGRR
    //AA: alpha value (0 = lowest value, FF = 255(max value))
    //BB: blue value  (0 = lowest value, FF = 255(max blue value))
    //GG: green value  (0 = lowest value, FF = 255(max green value))
    //RR: red value  (0 = lowest value, FF = 255(max red value))
    
   system("cls");
    unsigned char alpha = 0xFF;
    unsigned char blue = 0x12;
    unsigned char green = 0x34;
    unsigned char red = 0x56;

    unsigned int colour = alpha;

    cout<<colour<<"\n"; // this will output the integer value of the hex number

    cout<<hex<<colour<<"\n";//hex is from iomanip it outputs the int value in hexadecimal form

    colour <<= 8; //this moves the bit by 8 bits to the left 

    cout<<setfill('0')<<setw(8)<<colour<<"\n"; // we use setfill to fill the gap between with 0's

    colour >>= 8; //>> is the right bitshift operator, it shifts the bit to the right by 8 bits ie 1 byte

    cout<<setfill('0')<<setw(8)<<colour<<"\n";


    //let's see how we can combine all the hexvalues of alpha, red, blue, green into colour

    colour = 0;

    colour +=alpha; //we are adding alpha value to the start 
    colour <<= 8;   //moving it by 1 byte to make space for the red value
    colour += blue; //adding blue next
     colour <<= 8;  //moving by a byte
    colour += green; // adding green
     colour <<= 8; // moving by a byte
    colour += red; // adding red

    cout<<colour<<"\n"; // the final vlaue of colour will red the required combination of alpha blue green and red
    cout<<sizeof(int)<<"\n";
    screan bit;
    bit.createscreen();
    
    bit.create_rend_texture();
   
    bit.setbuffer(colour);
    
    bit.process_events();
    

    SDL_Event event;
    bool run = true;

    while(run == true)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                run = false;
            }
        }
    }

    bit.close();

    return 0;
}