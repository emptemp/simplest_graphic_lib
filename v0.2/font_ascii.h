////////////////////////////////////////////////////////////////////////////////
/// @file       TSGP_font.h
/// @brief      contains 8x12 ascii charset 0x20 to 0x7F
/// 
/// @author     Gerald Tschinkl
////////////////////////////////////////////////////////////////////////////////

#define D_CLUT             (32)
#define C_WIDTH            (8)
#define C_HEIGHT           (12)

// this represents 8x12 characters, in ascii " "==0x20 to "~"==0x7F
// one bit represents one pixel, one byte for every row, 12 rows in total
uint16_t char_lut[100][12] = {  {
                                0x00, 0x00, 0x00, 0x00, // space " "
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x10, 0x10, 0x10, // "!"
                                0x10, 0x10, 0x10, 0x00, 
                                0x00, 0x10, 0x00, 0x00, 
                                },
                                {
                                0x50, 0x50, 0x00, 0x00,  // """
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x50, 0x50, 0x50,  // "#"
                                0xf8, 0x50, 0x50, 0xf8, 
                                0x50, 0x50, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x20, 0x70, 0xa8,  // "$"
                                0xa0, 0x70, 0x28, 0x28, 
                                0xa8, 0x70, 0x20, 0x00, 
                                },
                                {
                                0x00, 0x00, 0xc8, 0xc8,  // "%"
                                0x10, 0x20, 0x20, 0x40, 
                                0x98, 0x98, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x20, 0x50, 0x50,  // "&"
                                0x20, 0x24, 0x54, 0x88, 
                                0x88, 0x74, 0x00, 0x00, 
                                },
                                {
                                0x30, 0x20, 0x00, 0x00,  // "`"
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x08, 0x10, 0x20,  // "("
                                0x20, 0x20, 0x20, 0x20, 
                                0x10, 0x08, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x40, 0x20, 0x10,  // ")"
                                0x10, 0x10, 0x10, 0x10, 
                                0x20, 0x40, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x44,  // "*"
                                0x28, 0xfe, 0x28, 0x44, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x10,  // "+"
                                0x10, 0x7c, 0x10, 0x10, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // ","
                                0x00, 0x00, 0x00, 0x00, 
                                0x20, 0x20, 0x40, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // "-"
                                0x00, 0xf8, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // "."
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x20, 0x00, 0x00, 
                                },
                                { 
                                0x00, 0x00, 0x04, 0x04, // "/"
                                0x08, 0x10, 0x10, 0x20, 
                                0x40, 0x40, 0x80, 0x00,  
                                },
                                {
                                0x00, 0x70, 0x88, 0x88,  // "0"
                                0x98, 0xa8, 0xc8, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x10, 0x30, 0x50,  // "1"
                                0x10, 0x10, 0x10, 0x10, 
                                0x10, 0x78, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88,  // "2"
                                0x08, 0x08, 0x10, 0x60, 
                                0x80, 0xf8, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x08,  // "3"
                                0x08, 0x30, 0x08, 0x08, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x08, 0x18, 0x28,  // "4"
                                0x48, 0x88, 0x88, 0xf8, 
                                0x08, 0x08, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf8, 0x80, 0x80,  // "5"
                                0xf0, 0x08, 0x08, 0x08, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x30, 0x40, 0x80,  // "6"
                                0xf0, 0x88, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf8, 0x88, 0x08,  // "7"
                                0x10, 0x10, 0x10, 0x20, 
                                0x20, 0x20, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88,  // "8"
                                0x88, 0x70, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88,  // "9"
                                0x88, 0x88, 0x78, 0x08, 
                                0x10, 0x60, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // ":"
                                0x20, 0x00, 0x00, 0x00, 
                                0x20, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // ";"
                                0x20, 0x00, 0x00, 0x00, 
                                0x20, 0x20, 0x40, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x10, 0x20,  // "<"
                                0x40, 0x80, 0x40, 0x20, 
                                0x10, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00,  // "="
                                0xf8, 0x00, 0x00, 0xf8, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x80, 0x40,  // ">"
                                0x20, 0x10, 0x20, 0x40, 
                                0x80, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x70, 0x88,  // "?"
                                0x88, 0x08, 0x10, 0x20, 
                                0x20, 0x00, 0x20, 0x00, 
                                },
                                {
                                0x00, 0x78, 0x84, 0x9c, // "@"
                                0xa4, 0xa4, 0xa4, 0x9c, 
                                0x80, 0x7c, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88, // "A"
                                0x88, 0xf8, 0x88, 0x88, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf0, 0x88, 0x88, // "B"
                                0x88, 0xf0, 0x88, 0x88, 
                                0x88, 0xf0, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x80, // "C"
                                0x80, 0x80, 0x80, 0x80, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xe0, 0x90, 0x88, // "D"
                                0x88, 0x88, 0x88, 0x88, 
                                0x90, 0xe0, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf8, 0x80, 0x80, // "E"
                                0x80, 0xf0, 0x80, 0x80, 
                                0x80, 0xf8, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf8, 0x80, 0x80, // "F"
                                0x80, 0xf0, 0x80, 0x80, 
                                0x80, 0x80, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x80, // "G"
                                0x80, 0x98, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x88, 0x88, 0x88, // "H"
                                0x88, 0xf8, 0x88, 0x88, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x38, 0x10, 0x10, // "I"
                                0x10, 0x10, 0x10, 0x10, 
                                0x10, 0x38, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x1c, 0x08, 0x08, // "J"
                                0x08, 0x08, 0x08, 0x48, 
                                0x48, 0x30, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x88, 0x88, 0x90, // "K"
                                0xa0, 0xc0, 0xa0, 0x90, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x40, 0x40, 0x40, // "L"
                                0x40, 0x40, 0x40, 0x40, 
                                0x40, 0x7C, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x82, 0xC6, 0xAA, // "M"
                                0x92, 0x82, 0x82, 0x82, 
                                0x82, 0x82, 0x00, 0x00,
                                },
                                {
                                0x00, 0x88, 0x88, 0xc8, // "N"
                                0xa8, 0x98, 0x88, 0x88, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88, // "O"
                                0x88, 0x88, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00,
                                },
                                {
                                0x00, 0xf0, 0x88, 0x88, // "P"
                                0x88, 0xf0, 0x80, 0x80, 
                                0x80, 0x80, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x88, // "Q"
                                0x88, 0x88, 0x88, 0x88, 
                                0x88, 0x70, 0x18, 0x00, 
                                },
                                {
                                0x00, 0xf0, 0x88, 0x88, // "R"
                                0x88, 0xf0, 0xc0, 0xa0, 
                                0x90, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x70, 0x88, 0x80, // "S"
                                0x80, 0x70, 0x08, 0x08, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x7c, 0x10, 0x10, // "T"
                                0x10, 0x10, 0x10, 0x10, 
                                0x10, 0x10, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x88, 0x88, 0x88, // "U"
                                0x88, 0x88, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x44, 0x44, 0x44, // "V"
                                0x44, 0x28, 0x28, 0x28,
                                0x10, 0x10, 0x00, 0x00,
                                },
                                {
                                0x00, 0x82, 0x82, 0x82, // "W"
                                0x82, 0x82, 0x92, 0xaa,
                                0xc6, 0x82, 0x00, 0x00,
                                },
                                {
                                0x00, 0x88, 0x88, 0x50, // "X"
                                0x50, 0x20, 0x50, 0x50, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x88, 0x88, 0x50, // "Y"
                                0x50, 0x20, 0x20, 0x20, 
                                0x20, 0x20, 0x00, 0x00, 
                                },
                                {
                                0x00, 0xf8, 0x08, 0x10, // "Z"
                                0x10, 0x20, 0x40, 0x40, 
                                0x80, 0xf8, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x30, 0x20, 0x20, // "["
                                0x20, 0x20, 0x20, 0x20, 
                                0x20, 0x30, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x40, 0x40, // "\"
                                0x20, 0x10, 0x10, 0x08, 
                                0x04, 0x04, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x60, 0x20, 0x20, // "]"
                                0x20, 0x20, 0x20, 0x20, 
                                0x20, 0x60, 0x00, 0x00, 
                                },
                                {
                                0x20, 0x50, 0x88, 0x00, // "^"
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "_" 
                                0x00, 0x00, 0x00, 0x00, // 
                                0x00, 0x00, 0x00, 0xf8, 
                                },
                                {
                                0x30, 0x10, 0x00, 0x00, // "´"
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "a"
                                0x70, 0x08, 0x78, 0x88, 
                                0x88, 0x78, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x80, 0x80, 0x80, // "b"
                                0xf0, 0x88, 0x88, 0x88, 
                                0x88, 0xf0, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "c"
                                0x70, 0x88, 0x80, 0x80, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x08, 0x08, 0x08, // "d"
                                0x78, 0x88, 0x88, 0x88, 
                                0x88, 0x78, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "e"
                                0x70, 0x88, 0x88, 0xf8, 
                                0x80, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x18, 0x20, 0x20, // "f"
                                0x70, 0x20, 0x20, 0x20, 
                                0x20, 0x20, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "g"
                                0x78, 0x88, 0x88, 0x88, 
                                0x88, 0x78, 0x08, 0x70, 
                                },
                                {
                                0x00, 0x80, 0x80, 0x80, // "h"
                                0xf0, 0x88, 0x88, 0x88, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x10, 0x00, 0x00, // "i"
                                0x30, 0x10, 0x10, 0x10, 
                                0x10, 0x38, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x10, 0x00, 0x00, // "j"
                                0x10, 0x10, 0x10, 0x10, 
                                0x10, 0x10, 0x50, 0x20, 
                                },
                                {
                                0x00, 0x80, 0x80, 0x80, // "k"
                                0x90, 0xa0, 0xc0, 0xa0, 
                                0x90, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x60, 0x20, 0x20,  // "l"
                                0x20, 0x20, 0x20, 0x20,
                                0x20, 0x70, 0x00, 0x00,
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "m"
                                0xfc, 0x92, 0x92, 0x92,
                                0x92, 0x92, 0x00, 0x00,
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "n"
                                0xf0, 0x88, 0x88, 0x88, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "o"
                                0x70, 0x88, 0x88, 0x88, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "p"
                                0xf0, 0x88, 0x88, 0x88, 
                                0x88, 0xf0, 0x80, 0x80, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "q"
                                0x78, 0x88, 0x88, 0x88, 
                                0x88, 0x78, 0x08, 0x08, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "r"
                                0xb8, 0xc0, 0x80, 0x80, 
                                0x80, 0x80, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "s"
                                0x70, 0x80, 0x70, 0x08, 
                                0x88, 0x70, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x20, 0x20, // "t"
                                0x78, 0x20, 0x20, 0x20, 
                                0x20, 0x18, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "u"
                                0x88, 0x88, 0x88, 0x88, 
                                0x88, 0x78, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "v"
                                0x44, 0x44, 0x28, 0x28,
                                0x10, 0x10, 0x00, 0x00,
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "w"
                                0x82, 0x82, 0x92, 0x92,
                                0x92, 0xec, 0x00, 0x00,
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "x" 
                                0x88, 0x50, 0x20, 0x50, 
                                0x88, 0x88, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "y"
                                0x88, 0x88, 0x88, 0x88, 
                                0x88, 0x78, 0x08, 0x70, 
                                },
                                {
                                0x00, 0x00, 0x00, 0x00, // "z"
                                0xf8, 0x10, 0x20, 0x40, 
                                0x80, 0xf8, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x18, 0x20, 0x20, // "{"
                                0x20, 0x40, 0x20, 0x20, 
                                0x20, 0x18, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x10, 0x10, 0x10, // "|"
                                0x10, 0x10, 0x10, 0x10, 
                                0x10, 0x10, 0x00, 0x00, 
                                },
                                {
                                0x00, 0x60, 0x10, 0x10, // "}"
                                0x10, 0x08, 0x10, 0x10, 
                                0x10, 0x60, 0x00, 0x00, 
                                },
                                {
                                0x44, 0xb4, 0x88, 0x00, // "~"
                                0x00, 0x00, 0x00, 0x00, 
                                0x00, 0x00, 0x00, 0x00, 
                                }};

