/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap converter for emWin V5.18.                           *
*        Compiled Sep 24 2012, 15:52:34                              *
*        (C) 1998 - 2012 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: clear                                                 *
* Dimensions:  50 * 44                                               *
* NumColors:   256                                                   *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmclear;

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _Colorsclear[] = {
  0xF7F4F1, 0xFCF7F1, 0xCBE5FC, 0xC4E1FC,
  0xFEFCFD, 0xDBEDFD, 0xD2E8FD, 0xD7FDFE,
  0xEBFEFE, 0xB3E8FE, 0x74D8FC, 0xB8FAFE,
  0x97F4FE, 0x00B2FF, 0x29C2FF, 0xC7FCFE,
  0x7AE5FE, 0x85EAFD, 0xF1FEFE, 0xA7F9FE,
  0xEAD4B9, 0xF1F6FD, 0x66CCFD, 0x69D3FE,
  0xE6C8A7, 0xE1FEFE, 0xABE5FB, 0xE3F1FD,
  0xA4DAFB, 0xDAA877, 0xEBDBC5, 0xE2BB93,
  0x86DAFF, 0xF5F2E9, 0x8AF1FF, 0xBBEBFE,
  0x144BDB, 0xE1B487, 0xE4C19C, 0xFBF9F4,
  0xDBE8F4, 0xCAA275, 0xF2E7D6, 0x7BC6E6,
  0xEAF4FD, 0xD9B48A, 0xEEE5D4, 0xD39C69,
  0x4896EB, 0x93EBFC, 0xC4D4E5, 0xCDE9FE,
  0xF3EEE3, 0xA5B6A7, 0x8AD6DD, 0xBACCDD,
  0x83CBE5, 0x88D4E5, 0xBBDEFC, 0xD9D8D7,
  0xEDE1CD, 0xCBDBEA, 0xEAEBEA, 0x3A86EA,
  0x68BBDF, 0x74C8DF, 0x73CEFB, 0xB5B3AA,
  0xF1DDC6, 0xBBAA89, 0x9BBAB6, 0xA3A2A1,
  0xB4B3B3, 0xDBBB94, 0xBBC3CB, 0xD1E6FB,
  0xBDA27C, 0xD8A16D, 0x0A3CD8, 0x0644E6,
  0x4786FE, 0xABAAA9, 0xB2ADA5, 0xBDBBBA,
  0xCBB291, 0xD6B892, 0xDCC5A9, 0xCAC6BD,
  0xDDCCB3, 0xE8CEB0, 0x86CADA, 0xB2E5FE,
  0xC8C7C5, 0xCCCAC5, 0xCBCCCB, 0xC5D3DD,
  0xE5E4E1, 0xF6F4F2, 0xCB9C6A, 0xC29E71,
  0xE0AC7B, 0x134AE6, 0x1751E6, 0x1A56F5,
  0x205AF7, 0x2964FD, 0x326CFE, 0x59A7FA,
  0x989896, 0xB3AA92, 0xB0ADAA, 0xC3AB85,
  0xC2B69A, 0xB6C3AD, 0xA4C4B6, 0xC2C1BD,
  0xD4CABB, 0xEBD0AA, 0x97C5C9, 0x96DADC,
  0xB6C9DB, 0xB4E3DC, 0x9AE1E6, 0xB3EAF6,
  0xDCD2C4, 0xE1DCD2, 0xF8E7CA, 0xEFE9DC,
  0xEAE9E5, 0x1551DD, 0x2B6DE2, 0x4678FF,
  0x7884B6, 0x3D8AF7, 0x4696F7, 0x5EB9F9,
  0x7BA6FE, 0x6EC0DF, 0xA6B29D, 0xB8BB9E,
  0x9A9DA0, 0xAAA5A1, 0xB4B7B9, 0xC6B18E,
  0xD4BA9A, 0xDCBE9A, 0xCDBCA4, 0xC7BBAA,
  0xD3BEA3, 0xC1BCB5, 0xCCC3AB, 0xDACEBC,
  0xFCDAA6, 0xB5BBC2, 0xBBBDC1, 0x8CC5CB,
  0x93DEE5, 0xBAD3E4, 0xA4C9FD, 0xA9E5E3,
  0xBDE8E3, 0xC2C4C2, 0xD1CEC4, 0xD9D3C8,
  0xC3CCD6, 0xC9CDD1, 0xE0DED9, 0xC6E4D8,
  0xE4E0DD, 0xE9E4D9, 0xCCD8E1, 0xD0E5F7,
  0xE4E9EE, 0x707BB8, 0x0B44DC, 0x245EDC,
  0x3677DF, 0x0B4DF8, 0x0E50F5, 0x2459E3,
  0x2E74E4, 0x3570FF, 0x4267CF, 0x5F79C9,
  0x607ACF, 0x6080D4, 0x758BD4, 0x62A1DA,
  0x72BCDF, 0x5487FF, 0x5298FF, 0x6491FF,
  0x64B9FF, 0x70B3FF, 0x7ED2DF, 0xA79A89,
  0xA49E96, 0xA3AD9B, 0x9AA7A8, 0x9CB3AA,
  0xAEA9A3, 0xA7A9AB, 0xB9AEB1, 0xA1BDB1,
  0xAFB4B9, 0xA9BEBB, 0xB4B8BD, 0xCAAD86,
  0xC0AF8B, 0xD6AE87, 0xC0B395, 0xD0B79A,
  0xA6C0AF, 0xB2CDBC, 0xEDCA9D, 0xF8CC94,
  0xCAC0A3, 0xC0C5AA, 0xD0C5B7, 0xD8C6B4,
  0xC1D0B9, 0x8C9BC9, 0x92BEC8, 0x8DB6FF,
  0x97BFFF, 0xA6BEE8, 0x9BC4DF, 0xBDC0C6,
  0xBEC9CF, 0xA1D4CE, 0xBDC9D5, 0xA0DFDC,
  0xB3DCD0, 0xA8E0DC, 0x9DC4FE, 0xA9CDE6,
  0xB8EEF6, 0xBFE1FF, 0xC4C7C9, 0xC5C9CB,
  0xD6D4CB, 0xDED9CD, 0xCAD7E2, 0xC6D8E8,
  0xD2DDE3, 0xC1DEF7, 0xCDDEF0, 0xCBEBE7,
  0xD5E0E8, 0xD3EFEC, 0xD5F4EE, 0xC7E4F6,
  0xC1EFFE, 0xE8E7E8, 0xE1E8F0, 0xF9F7F5
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palclear = {
  256,  // Number of entries
  0,    // No transparency
  &_Colorsclear[0]
};

static GUI_CONST_STORAGE unsigned char _acclear[] = {
  /* RLE: 050 Pixels @ 000,000 */ 50, 0x0D, 
  /* RLE: 050 Pixels @ 000,001 */ 50, 0x0E, 
  /* RLE: 001 Pixels @ 000,002 */ 1, 0x23, 
  /* RLE: 045 Pixels @ 001,002 */ 45, 0x09, 
  /* RLE: 004 Pixels @ 046,002 */ 4, 0x23, 
  /* RLE: 048 Pixels @ 000,003 */ 48, 0x04, 
  /* ABS: 004 Pixels @ 048,003 */ 0, 4, 0x27, 0x27, 0x04, 0x04, 
  /* RLE: 025 Pixels @ 002,004 */ 25, 0x15, 
  /* ABS: 002 Pixels @ 027,004 */ 0, 2, 0x12, 0x12, 
  /* RLE: 017 Pixels @ 029,004 */ 17, 0x15, 
  /* ABS: 007 Pixels @ 046,004 */ 0, 7, 0x04, 0x61, 0xA8, 0x7D, 0x15, 0x2C, 0x1B, 
  /* RLE: 024 Pixels @ 003,005 */ 24, 0x05, 
  /* ABS: 002 Pixels @ 027,005 */ 0, 2, 0x28, 0x28, 
  /* RLE: 016 Pixels @ 029,005 */ 16, 0x05, 
  /* ABS: 007 Pixels @ 045,005 */ 0, 7, 0x1B, 0x15, 0xAC, 0x5E, 0x73, 0x2C, 0x2C, 
  /* RLE: 023 Pixels @ 002,006 */ 23, 0x05, 
  /* ABS: 006 Pixels @ 025,006 */ 0, 6, 0x06, 0x3D, 0x4A, 0x9A, 0xF2, 0x06, 
  /* RLE: 014 Pixels @ 031,006 */ 14, 0x05, 
  /* ABS: 008 Pixels @ 045,006 */ 0, 8, 0x1B, 0x2C, 0xAC, 0xA5, 0x9A, 0x2C, 0x1B, 0x05, 
  /* RLE: 021 Pixels @ 003,007 */ 21, 0x06, 
  /* ABS: 008 Pixels @ 024,007 */ 0, 8, 0x4B, 0xF6, 0xA4, 0xC9, 0x47, 0x4A, 0x3D, 0xAB, 
  /* RLE: 013 Pixels @ 032,007 */ 13, 0x06, 
  /* ABS: 008 Pixels @ 045,007 */ 0, 8, 0x05, 0x2C, 0xFE, 0xA5, 0xE3, 0x2C, 0x1B, 0x05, 
  /* RLE: 020 Pixels @ 003,008 */ 20, 0x06, 
  /* ABS: 009 Pixels @ 023,008 */ 0, 9, 0xAB, 0x3D, 0xE4, 0x99, 0xCE, 0x8E, 0xCC, 0x99, 0xF3, 
  /* RLE: 013 Pixels @ 032,008 */ 13, 0x06, 
  /* ABS: 009 Pixels @ 045,008 */ 0, 9, 0x05, 0x2C, 0xFE, 0xA4, 0x4A, 0x2C, 0x1B, 0x06, 0x02, 
  /* RLE: 018 Pixels @ 004,009 */ 18, 0x33, 
  /* ABS: 012 Pixels @ 022,009 */ 0, 12, 0xAB, 0xF8, 0xA5, 0x48, 0x6E, 0xEE, 0xEF, 0x51, 0x47, 0x37, 0x06, 0x06, 
  /* RLE: 009 Pixels @ 034,009 */ 9, 0x33, 
  /* ABS: 010 Pixels @ 043,009 */ 0, 10, 0x02, 0x4B, 0x05, 0x2C, 0x28, 0x5F, 0x4A, 0x2C, 0x1B, 0x06, 
  /* RLE: 016 Pixels @ 003,010 */ 16, 0x02, 
  /* ABS: 015 Pixels @ 019,010 */ 0, 15, 0x33, 0x02, 0x02, 0xF4, 0x97, 0x96, 0x52, 0x6E, 0x93, 0x93, 0xC4, 0x8C, 0x78, 0x33, 0x33, 
  /* RLE: 011 Pixels @ 034,010 */ 11, 0x02, 
  /* ABS: 008 Pixels @ 045,010 */ 0, 8, 0x05, 0x1B, 0x28, 0x5F, 0xE6, 0x2C, 0x1B, 0x06, 
  /* RLE: 018 Pixels @ 003,011 */ 18, 0x02, 
  /* ABS: 013 Pixels @ 021,011 */ 0, 13, 0x3D, 0xF0, 0x26, 0x55, 0x52, 0x52, 0x54, 0xCF, 0xC3, 0x8C, 0x78, 0x33, 0x33, 
  /* RLE: 011 Pixels @ 034,011 */ 11, 0x02, 
  /* ABS: 008 Pixels @ 045,011 */ 0, 8, 0x06, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x1B, 0x06, 
  /* RLE: 017 Pixels @ 003,012 */ 17, 0x02, 
  /* ABS: 012 Pixels @ 020,012 */ 0, 12, 0xAA, 0x74, 0x58, 0x14, 0x58, 0x43, 0x52, 0xD3, 0x55, 0x45, 0x6D, 0xE4, 
  /* RLE: 013 Pixels @ 032,012 */ 13, 0x02, 
  /* ABS: 008 Pixels @ 045,012 */ 0, 8, 0x06, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x05, 0x33, 
  /* RLE: 013 Pixels @ 003,013 */ 13, 0x03, 
  /* ABS: 020 Pixels @ 016,013 */ 0, 20, 0x02, 0x03, 0xFB, 0x3D, 0xA2, 0x91, 0x75, 0x21, 0x80, 0x8E, 0xC8, 0x56, 0x18, 0x2D, 0x54, 0x57, 0xF3, 0xFB, 0x03, 0x02, 
  /* RLE: 009 Pixels @ 036,013 */ 9, 0x03, 
  /* ABS: 008 Pixels @ 045,013 */ 0, 8, 0x06, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x05, 0x02, 
  /* RLE: 009 Pixels @ 003,014 */ 9, 0x03, 
  /* ABS: 022 Pixels @ 012,014 */ 0, 22, 0x02, 0x02, 0x33, 0x33, 0x02, 0x03, 0xF2, 0xA2, 0x58, 0x14, 0x7E, 0x27, 0x3E, 0x8E, 0x8D, 0xDB, 0x14, 0x26, 0x91, 0x94, 0x57, 0x5F, 
  /* RLE: 011 Pixels @ 034,014 */ 11, 0x03, 
  /* ABS: 008 Pixels @ 045,014 */ 0, 8, 0x06, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x05, 0x02, 
  /* RLE: 010 Pixels @ 003,015 */ 10, 0x03, 
  /* RLE: 003 Pixels @ 013,015 */ 3, 0x02, 
  /* ABS: 020 Pixels @ 016,015 */ 0, 20, 0xFB, 0x3D, 0xA2, 0x91, 0x75, 0x21, 0x04, 0x04, 0x3E, 0x48, 0x8D, 0x74, 0x44, 0x14, 0x18, 0x55, 0x54, 0x57, 0xF3, 0xF5, 
  /* RLE: 009 Pixels @ 036,015 */ 9, 0x03, 
  /* ABS: 008 Pixels @ 045,015 */ 0, 8, 0x33, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x05, 0x02, 
  /* RLE: 009 Pixels @ 003,016 */ 9, 0x03, 
  /* ABS: 026 Pixels @ 012,016 */ 0, 26, 0x3A, 0x9E, 0xE0, 0xDF, 0xE1, 0x5D, 0x58, 0x18, 0x44, 0x27, 0x04, 0x04, 0x3E, 0x6E, 0x47, 0xA3, 0x2A, 0x44, 0x59, 0x91, 0x55, 0x92, 0x5C, 0x5F, 0xF5, 0xED, 
  /* RLE: 007 Pixels @ 038,016 */ 7, 0x03, 
  /* ABS: 008 Pixels @ 045,016 */ 0, 8, 0x33, 0x1B, 0x28, 0x32, 0x37, 0x1B, 0x05, 0x02, 
  /* RLE: 007 Pixels @ 003,017 */ 7, 0xED, 
  /* ABS: 028 Pixels @ 010,017 */ 0, 28, 0x03, 0xED, 0x9E, 0x88, 0xBD, 0xB5, 0xBA, 0x90, 0xD6, 0x1E, 0x34, 0x27, 0x04, 0x04, 0xFD, 0x51, 0x47, 0xA6, 0x01, 0x2A, 0x14, 0x59, 0x18, 0x55, 0x54, 0x73, 0x32, 0xF5, 
  /* RLE: 007 Pixels @ 038,017 */ 7, 0xED, 
  /* ABS: 008 Pixels @ 045,017 */ 0, 8, 0x02, 0x05, 0x28, 0x32, 0x78, 0x06, 0x33, 0x5B, 
  /* RLE: 008 Pixels @ 003,018 */ 8, 0x1C, 
  /* ABS: 027 Pixels @ 011,018 */ 0, 27, 0xEA, 0x88, 0xBD, 0x69, 0xB1, 0xB8, 0x94, 0x98, 0x2A, 0x34, 0x21, 0x27, 0x04, 0x60, 0x47, 0x6C, 0x3B, 0x00, 0x34, 0x2E, 0x1E, 0x59, 0x91, 0x2D, 0x92, 0xA1, 0x37, 
  /* RLE: 007 Pixels @ 038,018 */ 7, 0x1C, 
  /* ABS: 008 Pixels @ 045,018 */ 0, 8, 0x5B, 0x33, 0xFB, 0xEB, 0xE2, 0x23, 0x5B, 0x20, 
  /* RLE: 005 Pixels @ 003,019 */ 5, 0x42, 
  /* ABS: 031 Pixels @ 008,019 */ 0, 31, 0x0A, 0x42, 0xC1, 0xBF, 0x83, 0x6A, 0xB2, 0x4F, 0xB9, 0x7C, 0x7E, 0x2A, 0x7F, 0x7F, 0x34, 0x00, 0x3B, 0x8C, 0x6C, 0x73, 0x60, 0x21, 0x21, 0x2E, 0x14, 0x59, 0x18, 0x49, 0x54, 0xCD, 0x38, 
  /* RLE: 006 Pixels @ 039,019 */ 6, 0x42, 
  /* ABS: 008 Pixels @ 045,019 */ 0, 8, 0x20, 0x09, 0x1A, 0x38, 0xBC, 0x09, 0x1C, 0x0A, 
  /* RLE: 006 Pixels @ 003,020 */ 6, 0x16, 
  /* ABS: 031 Pixels @ 009,020 */ 0, 31, 0xC0, 0xBE, 0x83, 0x69, 0x68, 0xB3, 0xB6, 0xDD, 0xF1, 0x7E, 0x2E, 0x2E, 0x2E, 0xA9, 0xA6, 0x5E, 0x48, 0x51, 0x73, 0x3B, 0x61, 0x04, 0x34, 0x3C, 0x1E, 0x14, 0x26, 0x2D, 0x8B, 0xDE, 0x2B, 
  /* RLE: 005 Pixels @ 040,020 */ 5, 0x16, 
  /* ABS: 046 Pixels @ 045,020 */ 0, 46, 0x20, 0x1A, 0x1C, 0x2B, 0x40, 0x23, 0x1A, 0x0A, 0x16, 0x16, 0x16, 0x17, 0x16, 0xC0, 0x6B, 0x50, 0x69, 0x67, 0x66, 0xB7, 0xCA, 0x58, 0x14, 0x44, 0x3C, 0x2E, 0x2A, 0xF1, 0x53, 0x53, 0xA6, 0xA8, 0x5C, 0x5C, 0x3E, 
        0x04, 0x27, 0x34, 0x2E, 0x14, 0x59, 0x18, 0x90, 0xD2, 0x46, 0x2B, 
  /* RLE: 004 Pixels @ 041,021 */ 4, 0x16, 
  /* ABS: 237 Pixels @ 045,021 */ 0, 237, 0x20, 0x5B, 0x1C, 0x2B, 0x40, 0x23, 0x1A, 0x20, 0x16, 0x16, 0x17, 0x17, 0x16, 0x6B, 0x50, 0x6A, 0x68, 0x4F, 0x24, 0x84, 0xD6, 0x98, 0x59, 0x14, 0x1E, 0x3C, 0x2A, 0x7C, 0x43, 0x48, 0xA6, 0x80, 0x5D, 0x5C, 0x3E, 
        0x04, 0x04, 0x27, 0x34, 0x3C, 0x1E, 0x14, 0x26, 0x2D, 0x8B, 0x76, 0x2B, 0x17, 0x16, 0x16, 0x20, 0x5B, 0x1C, 0x2B, 0x40, 0x23, 0x1A, 0x20, 0x17, 0x16, 0x17, 0x17, 0x16, 0xBE, 0x6A, 0x68, 0x66, 0x4F, 0xAE, 0xAD, 0x1F, 0xD7, 0x18, 0x59, 0x14, 0x1E, 
        0x44, 0x7C, 0x95, 0x48, 0x53, 0x73, 0x5C, 0x3B, 0xFD, 0x61, 0x04, 0x04, 0x27, 0x21, 0x2E, 0x14, 0x59, 0x26, 0x90, 0x70, 0x76, 0x42, 0x16, 0x17, 0x20, 0x5B, 0x1A, 0x2B, 0x40, 0x23, 0x1A, 0x20, 0x17, 0x17, 0x17, 0x0A, 0x16, 0x85, 0x68, 0x66, 0x24, 
        0x81, 0xAF, 0x84, 0xD1, 0x25, 0x26, 0x26, 0x18, 0x59, 0x14, 0x7C, 0x74, 0x95, 0x6E, 0x48, 0x5D, 0xA6, 0x60, 0x61, 0x04, 0x04, 0x04, 0x27, 0x34, 0x3C, 0x1E, 0x14, 0x1F, 0x1D, 0x35, 0x42, 0x17, 0x17, 0x20, 0x09, 0x1A, 0x2B, 0x89, 0x23, 0x1A, 0x20, 
        0x17, 0x17, 0x17, 0x0A, 0x16, 0x85, 0x67, 0x65, 0x24, 0xB0, 0xBB, 0xC6, 0x29, 0x1D, 0x25, 0x1F, 0x26, 0x18, 0x59, 0x14, 0x14, 0x97, 0xDA, 0xDA, 0xA3, 0x7D, 0x60, 0x3E, 0xFF, 0x04, 0x04, 0x04, 0x27, 0x21, 0x7F, 0x44, 0x1F, 0x4D, 0x8A, 0x42, 0x17, 
        0x17, 0x20, 0x09, 0x1A, 0x2B, 0x89, 0x23, 0x1A, 0x20, 0x17, 0x17, 0x0A, 0x0A, 0x16, 0x85, 0x66, 0xAE, 0x81, 0x30, 0x38, 0xD4, 0x4C, 0x29, 0x64, 0x25, 0x1F, 0x26, 0x18, 0x59, 0x14, 0x14, 0x14, 0x7C, 0xF1, 0x7D, 0xA9, 0x80, 0xFF, 
  /* RLE: 004 Pixels @ 032,026 */ 4, 0x04, 
  /* ABS: 046 Pixels @ 036,026 */ 0, 46, 0x27, 0x34, 0x1E, 0x49, 0x29, 0xC7, 0x42, 0x17, 0x17, 0x20, 0x09, 0x1A, 0x38, 0x89, 0x23, 0x1A, 0x20, 0x17, 0x17, 0x0A, 0x10, 0x17, 0x3F, 0x81, 0xAE, 0x81, 0x30, 0x0A, 0x36, 0x46, 0x6D, 0x29, 0x1D, 0x25, 0x1F, 
        0x26, 0x26, 0x75, 0x59, 0x14, 0x1E, 0x1E, 0x3C, 0x2E, 0x7F, 0x00, 
  /* RLE: 005 Pixels @ 032,027 */ 5, 0x04, 
  /* ABS: 054 Pixels @ 037,027 */ 0, 54, 0x1E, 0x2D, 0xD0, 0xCB, 0x5A, 0x0A, 0x17, 0x17, 0x20, 0x09, 0x1A, 0x38, 0x89, 0x23, 0x1A, 0x20, 0x0A, 0x0A, 0x0A, 0x10, 0x17, 0x3F, 0x24, 0x4E, 0x81, 0x30, 0x0A, 0x10, 0x38, 0x46, 0x4C, 0x29, 0x64, 0x25, 0x25, 
        0x1F, 0x26, 0x18, 0x59, 0x14, 0x1E, 0x3C, 0x3C, 0x2A, 0x21, 0x27, 0x04, 0x04, 0x04, 0x21, 0x56, 0x63, 0xC5, 0x5A, 
  /* RLE: 004 Pixels @ 041,028 */ 4, 0x0A, 
  /* ABS: 045 Pixels @ 045,028 */ 0, 45, 0x20, 0x09, 0x1A, 0x38, 0x89, 0x23, 0x09, 0x20, 0x0A, 0x0A, 0x0A, 0x10, 0x17, 0x3F, 0x24, 0x4E, 0x24, 0x30, 0x0A, 0x10, 0x0A, 0x5A, 0x46, 0x6D, 0x29, 0x4D, 0x64, 0x25, 0x1F, 0x26, 0x18, 0x59, 0x14, 0x1E, 0x1E, 
        0x3C, 0x2A, 0x34, 0x04, 0x04, 0x44, 0x91, 0x70, 0x35, 0x9B, 
  /* RLE: 005 Pixels @ 040,029 */ 5, 0x0A, 
  /* ABS: 046 Pixels @ 045,029 */ 0, 46, 0x20, 0x09, 0x1A, 0x38, 0x41, 0xFC, 0x09, 0x20, 0x0A, 0x0A, 0x10, 0x10, 0x0A, 0x3F, 0x24, 0x4E, 0x81, 0x30, 0x0A, 0x10, 0x10, 0x0A, 0x39, 0x46, 0x4C, 0x2F, 0x1D, 0x64, 0x25, 0x1F, 0x26, 0x26, 0x18, 0x59, 0x14, 
        0x1E, 0x1E, 0x2E, 0x21, 0x21, 0x56, 0x63, 0x8A, 0x5A, 0x0A, 0x10, 
  /* RLE: 004 Pixels @ 041,030 */ 4, 0x0A, 
  /* ABS: 018 Pixels @ 045,030 */ 0, 18, 0x31, 0x09, 0x1A, 0x39, 0x41, 0xFC, 0x09, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0A, 0x3F, 0xAE, 0x81, 0xB4, 0x6B, 
  /* RLE: 005 Pixels @ 013,031 */ 5, 0x10, 
  /* ABS: 021 Pixels @ 018,031 */ 0, 21, 0x36, 0xCB, 0x6D, 0x29, 0x4D, 0x64, 0x25, 0x25, 0x1F, 0x26, 0x18, 0x59, 0x14, 0x44, 0x44, 0x59, 0x56, 0x70, 0x8A, 0x9B, 0x0A, 
  /* RLE: 006 Pixels @ 039,031 */ 6, 0x10, 
  /* ABS: 020 Pixels @ 045,031 */ 0, 20, 0x31, 0x23, 0x7B, 0x39, 0x41, 0xFC, 0x09, 0x31, 0x10, 0x10, 0x10, 0x11, 0x0A, 0x3F, 0x24, 0x82, 0x30, 0x16, 0x10, 0x11, 
  /* RLE: 004 Pixels @ 015,032 */ 4, 0x10, 
  /* ABS: 018 Pixels @ 019,032 */ 0, 18, 0x39, 0x72, 0x4C, 0x2F, 0x1D, 0x64, 0x64, 0x25, 0x1F, 0x26, 0x18, 0x59, 0x14, 0x14, 0x2D, 0x63, 0x35, 0x36, 
  /* RLE: 008 Pixels @ 037,032 */ 8, 0x10, 
  /* ABS: 018 Pixels @ 045,032 */ 0, 18, 0x31, 0x23, 0x7B, 0x39, 0x41, 0xFC, 0x09, 0x31, 0x10, 0x10, 0x11, 0x22, 0x10, 0x30, 0x82, 0x30, 0x16, 0x10, 
  /* RLE: 007 Pixels @ 013,033 */ 7, 0x11, 
  /* ABS: 016 Pixels @ 020,033 */ 0, 16, 0x77, 0xD4, 0xD0, 0x29, 0x4D, 0x1D, 0x64, 0x25, 0x1F, 0x26, 0x26, 0x1F, 0x55, 0xD0, 0x8A, 0x76, 
  /* RLE: 007 Pixels @ 036,033 */ 7, 0x11, 
  /* ABS: 018 Pixels @ 043,033 */ 0, 18, 0x10, 0x10, 0x31, 0x0B, 0x7B, 0x39, 0xC2, 0xFC, 0x0B, 0x31, 0x11, 0x11, 0x11, 0x22, 0x11, 0x87, 0x30, 0x16, 
  /* RLE: 009 Pixels @ 011,034 */ 9, 0x22, 
  /* ABS: 019 Pixels @ 020,034 */ 0, 19, 0x31, 0x9C, 0x72, 0x4C, 0x2F, 0x4D, 0x1D, 0x64, 0x25, 0x1F, 0x1F, 0x1D, 0x63, 0xD4, 0x77, 0x31, 0x11, 0x22, 0x22, 
  /* RLE: 006 Pixels @ 039,034 */ 6, 0x11, 
  /* ABS: 009 Pixels @ 045,034 */ 0, 9, 0x0C, 0x0B, 0x7B, 0x9C, 0xC2, 0x0F, 0x0B, 0x0C, 0x11, 
  /* RLE: 004 Pixels @ 004,035 */ 4, 0x22, 
  /* ABS: 003 Pixels @ 008,035 */ 0, 3, 0x0A, 0x42, 0x20, 
  /* RLE: 010 Pixels @ 011,035 */ 10, 0x0C, 
  /* ABS: 018 Pixels @ 021,035 */ 0, 18, 0x31, 0xE7, 0x71, 0xD0, 0x29, 0x2F, 0x4D, 0x1D, 0x1D, 0x1D, 0x6F, 0x8B, 0xE5, 0x31, 0x22, 0x22, 0x22, 0x0C, 
  /* RLE: 006 Pixels @ 039,035 */ 6, 0x22, 
  /* ABS: 010 Pixels @ 045,035 */ 0, 10, 0x0C, 0xFC, 0xEC, 0x9C, 0xC2, 0x0F, 0x0B, 0x0C, 0x22, 0x22, 
  /* RLE: 015 Pixels @ 005,036 */ 15, 0x0C, 
  /* RLE: 003 Pixels @ 020,036 */ 3, 0x13, 
  /* ABS: 010 Pixels @ 023,036 */ 0, 10, 0x9F, 0xD5, 0x6F, 0x62, 0x4D, 0x4D, 0x2F, 0x29, 0x71, 0xE9, 
  /* RLE: 012 Pixels @ 033,036 */ 12, 0x0C, 
  /* ABS: 008 Pixels @ 045,036 */ 0, 8, 0x13, 0x0F, 0xEC, 0x9C, 0x36, 0x0F, 0x0B, 0x13, 
  /* RLE: 004 Pixels @ 003,037 */ 4, 0x0C, 
  /* RLE: 017 Pixels @ 007,037 */ 17, 0x13, 
  /* ABS: 008 Pixels @ 024,037 */ 0, 8, 0x79, 0xD9, 0x6F, 0x62, 0x2F, 0x6F, 0x8B, 0xE8, 
  /* RLE: 011 Pixels @ 032,037 */ 11, 0x13, 
  /* ABS: 011 Pixels @ 043,037 */ 0, 11, 0x0C, 0x0C, 0x13, 0x0F, 0xEC, 0x7A, 0x36, 0x0F, 0x0F, 0x13, 0x0C, 
  /* RLE: 007 Pixels @ 004,038 */ 7, 0x13, 
  /* RLE: 014 Pixels @ 011,038 */ 14, 0x0B, 
  /* ABS: 007 Pixels @ 025,038 */ 0, 7, 0xA0, 0xDC, 0x29, 0x63, 0xD9, 0x79, 0xEC, 
  /* RLE: 007 Pixels @ 032,038 */ 7, 0x0B, 
  /* RLE: 006 Pixels @ 039,038 */ 6, 0x13, 
  /* ABS: 009 Pixels @ 045,038 */ 0, 9, 0x0B, 0x0F, 0xFC, 0x7A, 0x9C, 0x07, 0x0F, 0x0B, 0x13, 
  /* RLE: 010 Pixels @ 004,039 */ 10, 0x0B, 
  /* RLE: 012 Pixels @ 014,039 */ 12, 0x0F, 
  /* ABS: 004 Pixels @ 026,039 */ 0, 4, 0xA7, 0x96, 0xD8, 0xA7, 
  /* RLE: 004 Pixels @ 030,039 */ 4, 0x0F, 
  /* RLE: 011 Pixels @ 034,039 */ 11, 0x0B, 
  /* ABS: 007 Pixels @ 045,039 */ 0, 7, 0x0F, 0x07, 0x0F, 0x9F, 0xE7, 0x19, 0x07, 
  /* RLE: 009 Pixels @ 002,040 */ 9, 0x0F, 
  /* RLE: 016 Pixels @ 011,040 */ 16, 0x07, 
  /* ABS: 002 Pixels @ 027,040 */ 0, 2, 0xFA, 0xFA, 
  /* RLE: 010 Pixels @ 029,040 */ 10, 0x07, 
  /* RLE: 006 Pixels @ 039,040 */ 6, 0x0F, 
  /* ABS: 007 Pixels @ 045,040 */ 0, 7, 0x07, 0x19, 0xFA, 0xA0, 0x79, 0x08, 0x19, 
  /* RLE: 004 Pixels @ 002,041 */ 4, 0x07, 
  /* RLE: 037 Pixels @ 006,041 */ 37, 0x19, 
  /* ABS: 011 Pixels @ 043,041 */ 0, 11, 0x07, 0x07, 0x19, 0x08, 0x19, 0xF9, 0xF7, 0x12, 0x12, 0x08, 0x19, 
  /* RLE: 042 Pixels @ 004,042 */ 42, 0x08, 
  /* ABS: 006 Pixels @ 046,042 */ 0, 6, 0x12, 0x12, 0x08, 0x08, 0x12, 0x12, 
  /* RLE: 004 Pixels @ 002,043 */ 4, 0x08, 
  /* RLE: 037 Pixels @ 006,043 */ 37, 0x12, 
  /* ABS: 002 Pixels @ 043,043 */ 0, 2, 0x08, 0x08, 
  /* RLE: 004 Pixels @ 045,043 */ 4, 0x12, 
  /* RLE: 001 Pixels @ 049,043 */ 1, 0x04, 
  0
};  // 1467 bytes for 2200 pixels

GUI_CONST_STORAGE GUI_BITMAP bmclear = {
  50, // xSize
  44, // ySize
  50, // BytesPerLine
  GUI_COMPRESS_RLE8, // BitsPerPixel
  _acclear,  // Pointer to picture data (indices)
  &_Palclear,  // Pointer to palette
  GUI_DRAW_RLE8
};

/*************************** End of file ****************************/
