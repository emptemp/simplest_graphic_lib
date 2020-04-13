#ifndef TSGP_H
#define TSGP_H

////////////////////////////////////////////////////////////////////////////////
/// @file       TSGP_font.h
/// @version    v0.3
/// @brief      contains 8x12 ascii charset 0x20 to 0x7F
///
/// @author     Gerald Tschinkl
////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>   //uint8_t etc.
#include <stdio.h>
#include <stdlib.h>   //abs()
#include <string.h>   //strlen()
#include "font_ascii.h"
// for beautiful sine wave
#include <math.h>

#define ROTATE              (0)
#define BACKCOLOR           (0x00)      // BMP: 0x00 = Black, 0xFF = White
                                        // EPD: 0x00 = White, 0xFF = Black

#define WIDTH               (512)
#define HEIGHT              (512)

#define WORDSIZE            (8)
#define BUFFERSIZE          (HEIGHT  * (WIDTH / WORDSIZE))
#define BLOCK_INDEX         (WIDTH/WORDSIZE) - 1
#if ROTATE
  #define GETBUFPOS(x,y)    (WIDTH*x)/WORDSIZE + BLOCK_INDEX - (y/WORDSIZE)
#else
  #define GETBUFPOS(x,y)      (y*(WIDTH/WORDSIZE) + x/WORDSIZE)
#endif

#if !(WIDTH%WORDSIZE==0 && HEIGHT%WORDSIZE==0)
  #error WIDTH AND HEIGHT ARE NOT DIVISIBLE BY WORDSIZE
#endif

uint8_t fbuf[BUFFERSIZE];

// inverts pixeldot
void xdot(uint16_t x, uint16_t y);

// clears pixeldot
void dot(uint16_t x, uint16_t y);

// ©bresenham line algorithm
void line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

// fills rect with dots
void rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t fill);

// draws beautiful sine waves
void sine(uint16_t x, uint16_t y, uint16_t tlen, uint8_t ampl, uint8_t freq);

// also draws beautiful sine waves but rotated by 90 degrees ;-)
void sine_rot(uint16_t x, uint16_t y, uint16_t tlen, uint8_t ampl, uint8_t freq);

// gets info from char_lut and sets dots accordingly
//void print_chr(uint16_t x, uint16_t y, uint8_t chr);

// gets info from char_lut and sets dots accordingly
void print_chr(uint16_t x, uint16_t y, uint8_t chr, uint8_t size);

// puts string into fbuffer using print_chr()
void print_str(uint16_t x, uint16_t y, char* str, uint8_t size);

#endif

