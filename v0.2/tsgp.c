////////////////////////////////////////////////////////////////////////////////
/// @file       TSGP_font.h
/// @version    v0.3
/// @brief      contains 8x12 ascii charset 0x20 to 0x7F
/// 
/// @author     Gerald Tschinkl
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdint.h>   //uint8_t etc.
#include <string.h>   //strlen()
#include "font_ascii.h"
#include "draw_bmp.c"

// for sleep
#include <unistd.h>
// for beautiful sine wave
#include <math.h>

/* TODO
 > sprintf() to print_str() w/ MACRO
 > compatibility with any dimension (works?)
   - this is mainly a problem with the .bmp file format :(
   - draw_bmp.c still buggy af. header?
 > fontsize doubler via rect()? 
 > sine without math.h
 > character rotation, plotter, ...
*/

// inverts pixeldot
void xdot(uint16_t x, uint16_t y)
{
  // calc position in buf and set 1
#if ROTATE
  fbuf[GETBUFPOS(x,y)] ^= 0x01 << y%WORDSIZE;
#else
  fbuf[GETBUFPOS(x,y)] ^= 0x01 << (WORDSIZE-1-(x%WORDSIZE));
#endif
}

// clears pixeldot
void dot(uint16_t x, uint16_t y)
{
  // calc position in buf and set 1
#if ROTATE
  fbuf[GETBUFPOS(x,y)] &= 0x00 << y%WORDSIZE;
#else
  fbuf[GETBUFPOS(x,y)] &= 0x01 << (WORDSIZE-1-(x%WORDSIZE));
#endif
}

// ©bresenham line algorithm
void line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  int16_t dx = abs(x1-x0);
  int16_t sx = x0<x1 ? 1 : -1;
  int16_t dy = abs(y1-y0);
  int16_t sy = y0<y1 ? 1 : -1; 
  int16_t err = (dx>dy ? dx : -dy)/2, e2;
  while(1)
  {
    xdot(x0,y0);
    if (x0 == x1 && y0 == y1) 
      break;
    e2 = err;
    if (e2 > -dx) { 
      err -= dy; 
      x0 += sx; 
    }
    if (e2 < dy) { 
      err += dx; 
      y0 += sy; 
    }
  }
}

// fills rect with dots
void rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t fill)
{
  for(uint16_t y_=y0; y_<=y1; y_++)
    for(uint16_t x_=x0; x_<=x1; x_++)
      fill==1 ? dot(x_,y_):xdot(x_,y_);
}

// draws beautiful sine waves
void sine(uint16_t x, uint16_t y, uint16_t tlen, uint8_t ampl, uint8_t freq)
{
  for(uint16_t x_ = 0; x_ < tlen; x_++) {
    int16_t y_ = ampl*sin(x_*freq*(3.14/180));
    //printf("sin(%u)=%d\n", x_, y_);
    xdot(x+x_,y-y_);
  }
}
// also draws beautiful sine waves but rotated by 90 degrees ;-)
void sine_rot(uint16_t x, uint16_t y, uint16_t tlen, uint8_t ampl, uint8_t freq)
{
  for(uint16_t y_ = 0; y_ < tlen; y_++) {
    int16_t x_ = ampl*sin(y_*freq*(3.1415/180));
    //printf("sin(%u)=%d\n", x_, y_);
    xdot(x-x_,y+y_);
  }
}

// gets info from char_lut and sets dots accordingly
void print_chr(uint16_t x, uint16_t y, uint8_t chr)
{
  for(uint16_t cs=0; cs<8*12; cs++) {
    uint16_t y_ = y + cs/8;
    uint16_t x_ = x + cs%8;
    if((char_lut[chr][cs/8] >> (8-(cs%8))) & 0x01)  {
      //printf("%u %u - %u %u\n", cs/8, cs%8, x_, y_);
      xdot(x_,y_);
    }
  }
}

// puts string into fbuffer using print_chr()
void print_str(uint16_t x, uint16_t y, char* str)
{
  x-=8; // dirty
  for(uint8_t i = 0; i < strlen(str); i++)
    if(0x19 < str[i] && str[i] < 0x80) // san check
      print_chr(x+=8, y, str[i]-D_CLUT);
    else // print space
      print_chr(x+=8, y, str[0]);  
}

int main()
{
  printf("TSGP v0.2\n");
  // set background black
  memset(fbuf, 0x00, BUFFERSIZE);

  line(0,HEIGHT/2,WIDTH-1,HEIGHT/2);
  line(WIDTH/2,0,WIDTH/2,HEIGHT-1);
  
  print_str(10,10,">:O|=<");

  for(uint16_t i = 8; i < WIDTH; i=i*2)
    sine(0, HEIGHT/2, WIDTH-1, i-1, 0xFF/i+1);     
 
  for(uint16_t i = 8; i < HEIGHT; i=i*2)
    sine_rot(WIDTH/2, 0, HEIGHT-1, i-1, 0xFF/i+1);

  rect(0, 0, 128, 104, 1);
  line(0, 104, 128, 104);
  line(128, 0, 128, 104);
  line(1, 14, 128, 14);  

  print_str(1,1, "TSGP v0.2   4/19"); 
  for(uint8_t c=0x00; c<0x60; c++)
    print_chr(1+c%16*8, 20+c/16*14, c);
  
  print_str(333,130,">:O|=<");
  draw_bmp();
  printf("done writing\n%s\n", BMP_NAME);
  return 0;
}








