////////////////////////////////////////////////////////////////////////////////
/// @file       TSGP_font.h
/// @brief      contains 8x12 ascii charset 0x20 to 0x7F
///
/// @author     Gerald Tschinkl
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tsgp.h"


#define BMP_NAME            "1.bmp"

#define WIDTH_0       WIDTH & 0xFF
#define WIDTH_1       (WIDTH & 0xFF00) >> 8
#define HEIGHT_0      0xFF - (HEIGHT & 0xFF)  //+1     // needs to be 1px smaller
#define HEIGHT_1      0xFF - ((HEIGHT & 0xFF00) >> 8)
#define BITS_PIXEL    1
#define RAWSIZE       (WIDTH*HEIGHT)/(8/BITS_PIXEL)+62
#define RAWSIZE_0     RAWSIZE & 0xFF
#define RAWSIZE_1     (RAWSIZE & 0xFF00) >> 8

// header info for .bmp file format
uint8_t header[62] = {  0x42,0x4D,    // ID field
    RAWSIZE_0,RAWSIZE_1,0x00,0x00,    // size of bmp
              0x00,0x00,0x00,0x00,    // unused
              0x3E,0x00,0x00,0x00,    // offset of pixel array
              0x28,0x00,0x00,0x00,    // bytes in DIB header
        WIDTH_0,WIDTH_1,0x00,0x00,    // width of bmp
      HEIGHT_0,HEIGHT_1,0xFF,0xFF,    // width of bmp
                        0x01,0x00,    // nr of color planes
                        0x01,0x00,    // bits per pixel
              0x00,0x00,0x00,0x00,    // no compression
              0x00,0x00,0x00,0x00,    // size of raw bitmap data
              0x00,0x00,0x00,0x00,    // print resolution / horizontal
              0x00,0x00,0x00,0x00,    // print resolution / vertical
              0x00,0x00,0x00,0x00,    // number of colors in palette
              0x00,0x00,0x00,0x00,    // all colors important
              0x00,0x00,0x00,0x00,    //
              0xFF,0xFF,0xFF,0x00};   // color palette

// outputs fbuf[] to BMP_NAME
void draw_bmp()
{
//  printf("HEIGHT 1: %X HEIGHT 0: %X\n", HEIGHT_1, HEIGHT_0);
//  printf("WIDTH: %X\n", (WIDTH_1 << 8) | WIDTH_0);
  FILE* fp;
  fp = fopen(BMP_NAME,"w");
  fwrite(header, 1, 62, fp);
  fwrite(fbuf, 1, sizeof(fbuf), fp);
  fclose(fp);
}

int main()
{
  printf("TSGP v0.3\n");
  // set background black
  memset(fbuf, BACKCOLOR, BUFFERSIZE);
  line(0,HEIGHT/2,WIDTH-1,HEIGHT/2);
  line(WIDTH/2,0,WIDTH/2,HEIGHT-1);

  for(uint16_t i = 8; i < WIDTH; i=i*2)
    sine(0, HEIGHT/2, WIDTH-1, i-1, 0xFF/i+1);

  for(uint16_t i = 8; i < HEIGHT; i=i*2)
    sine_rot(WIDTH/2, 0, HEIGHT-1, i-1, 0xFF/i+1);

  rect(0, 0, 128, 104, 1);
  line(0, 104, 128, 104);
  line(128, 0, 128, 104);
  line(1, 14, 128, 14);

  print_str(1,1, "TSGP v0.3   4/19",1);
  for(uint8_t c=0x00; c<0x60; c++)
    print_chr(1+c%16*8, 20+c/16*14, c,1);

  print_str(10,300,">:O|=<", 1);
  print_str(10,320,">:O|=<", 2);
  print_str(10,352,">:O|=<", 3);
  print_str(10,388,">:O|=<", 4);
  print_str(10,440,">:O|=<", 5);

  draw_bmp();
  printf("done writing\n%s\n", BMP_NAME);
  return 0;
}
