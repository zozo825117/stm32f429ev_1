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
* Source file: fixed                                                 *
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

extern GUI_CONST_STORAGE GUI_BITMAP bmfixed;

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
static GUI_CONST_STORAGE GUI_COLOR _Colorsfixed[] = {
  0xF9F3EC, 0xF5ECE2, 0xF3E9DE, 0xFBF6F1,
  0xF6F0E9, 0xFEFDF9, 0xF9F1E6, 0xD1BBAA,
  0xDCCABE, 0xF8EEE3, 0xF4ECE8, 0xFCF9F4,
  0xCEB9AA, 0xECE2DA, 0xD8C4B5, 0xDECDC0,
  0xE4DCD4, 0xF5F0E6, 0xFFF9EB, 0xD8C5B8,
  0xF1E6DD, 0x68C3E5, 0x88DAF7, 0x86E9FD,
  0x5894BA, 0xD7C5B8, 0xE3D4C9, 0xEBE4E4,
  0x5B87A5, 0x6D8CAA, 0x7793A8, 0x6C94B5,
  0x57A5C9, 0xB9C3C9, 0x91C8F8, 0xA9F5FE,
  0xDBD9D4, 0xE9DED5, 0xE5DFE3, 0x547B95,
  0x7A9BB9, 0x7CA3BB, 0x4D9BC5, 0x75A3CB,
  0x67A7D3, 0x7BD9F5, 0x8499AB, 0xA3B2BB,
  0xD6C3B6, 0x8C8AC2, 0xAEBBC3, 0x83B6E7,
  0x88C4F9, 0x95E3F5, 0xCCCBC2, 0xDCD4CA,
  0xD3CEDA, 0xD1D3D3, 0xE0D1C4, 0xE4D9CC,
  0xEDE2D5, 0x517B41, 0x75716B, 0x6F8B6A,
  0x377A9C, 0x477C9A, 0x6B7B8B, 0x5C5BBB,
  0x6A68BC, 0x7573BA, 0x5A5AC5, 0x778695,
  0x4B86A5, 0x628CB5, 0x66A6C9, 0x7AABDD,
  0x77B8E1, 0x71C3E6, 0x7BC7E9, 0x75E2FC,
  0x9B938B, 0x9A9C9C, 0x94A391, 0x8582BD,
  0x97A8B6, 0xBBBAB6, 0xD3BFB2, 0xCBC4BD,
  0xA8A4CA, 0xB1ADCF, 0x95E2F9, 0x92ECFE,
  0x9EF3FE, 0xACFBFF, 0xC5CBCD, 0xD4CBC2,
  0xD9D1C7, 0xCDC9DA, 0xDAD7D4, 0xDCDDDB,
  0xDBD5E1, 0xE9E4E8, 0x446C3E, 0x424240,
  0x53565A, 0x615F5A, 0x476D44, 0x597C53,
  0x5E7E61, 0x717271, 0x568043, 0x668659,
  0x638A59, 0x638262, 0x6D8973, 0x799177,
  0x7D967C, 0x89857F, 0x849D7B, 0x2F7EA4,
  0x3B7CA8, 0x757A81, 0x617E9A, 0x4847AD,
  0x5757AE, 0x5755B2, 0x457FA0, 0x6563B2,
  0x7876BC, 0x7D7CB9, 0x6B6CC2, 0x6566D5,
  0x6B6CD6, 0x7677D2, 0x7677DF, 0x388BAF,
  0x4B819E, 0x7F9481, 0x6A869B, 0x458AB5,
  0x518BB4, 0x4A9DBD, 0x758DA3, 0x509FC0,
  0x6C95C0, 0x619DC0, 0x6D9ECE, 0x7196C1,
  0x4FA3CF, 0x5EB1CD, 0x5DA7D1, 0x5DACD5,
  0x4FB5D7, 0x5DB4D2, 0x6CA0C5, 0x68B1D7,
  0x68B5DC, 0x78B1D0, 0x7FB9D7, 0x77B1DB,
  0x78AFE5, 0x6CC0DC, 0x76C4DA, 0x78C5E6,
  0x73CAE1, 0x7BCAEC, 0x6FD1EB, 0x8F8E8C,
  0x849B80, 0x868C91, 0x80959B, 0x90A885,
  0x97A68B, 0x97B09F, 0xB0A79E, 0x909FA9,
  0x93A3A7, 0x9FAEA9, 0x9BB0A9, 0x8CA6B4,
  0x80A4BE, 0x81A8BF, 0x9DB3BF, 0xA2AEA2,
  0xA4A6A9, 0xA3A9AB, 0xB4BDA0, 0xBFB5AC,
  0xA6A7B2, 0xA0AFBD, 0xA4B9B2, 0xAEBAB0,
  0xAFB5BA, 0xB8B9B8, 0xC1B7AD, 0xC7BEB6,
  0xBFC4B2, 0xBDC4B9, 0xC6D1BC, 0x9492C8,
  0x9F9FCB, 0x8F8FDA, 0x9495D0, 0xA29FC9,
  0x80A9CE, 0x90A8C0, 0x8EB5CA, 0x95B4C5,
  0x9AB6C9, 0x82B9D9, 0xA3AFC1, 0xA7A3CC,
  0xB2B9C0, 0xBCB8C5, 0xBEBFCF, 0xA9ACD6,
  0xB2AFD3, 0x8A8AE6, 0x9C9DE3, 0x86BFF3,
  0xB8B6EA, 0xC0BCD8, 0xABC2CE, 0xAEC6D2,
  0xA9CADC, 0xBDD0D9, 0xBCE0DC, 0x81C1EC,
  0x98D1FF, 0x9EE2F6, 0x90F3FF, 0xB1E5EC,
  0xA0F2FD, 0xA5FAFF, 0xBEF3F6, 0xBAFFFF,
  0xC0C4C5, 0xC3C7C9, 0xC9CCC8, 0xD7D6C0,
  0xD0D0CE, 0xD8D8CC, 0xC0C0D7, 0xC6C2DA,
  0xCAC6D8, 0xCFD1D3, 0xCDD9DC, 0xD3D6DB,
  0xD8D1DF, 0xE0CFC5, 0xE0DFDD, 0xE8DFD9,
  0xE5E0D8, 0xDBD8F1, 0xE7E9EA, 0xF9EFE9
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palfixed = {
  256,  // Number of entries
  0,    // No transparency
  &_Colorsfixed[0]
};

static GUI_CONST_STORAGE unsigned char _acfixed[] = {
  /* ABS: 006 Pixels @ 000,000 */ 0, 6, 0x03, 0x04, 0x3C, 0x3A, 0x0E, 0x07, 
  /* RLE: 044 Pixels @ 006,000 */ 44, 0x0C, 
  /* ABS: 005 Pixels @ 000,001 */ 0, 5, 0x01, 0x14, 0x25, 0x1A, 0xF9, 
  /* RLE: 045 Pixels @ 005,001 */ 45, 0x08, 
  /* ABS: 005 Pixels @ 000,002 */ 0, 5, 0xF9, 0x1A, 0x10, 0xFB, 0x14, 
  /* RLE: 043 Pixels @ 005,002 */ 43, 0x0A, 
  /* ABS: 007 Pixels @ 048,002 */ 0, 7, 0x04, 0x04, 0x56, 0x13, 0x10, 0x0A, 0x03, 
  /* RLE: 045 Pixels @ 005,003 */ 45, 0x05, 
  /* ABS: 005 Pixels @ 000,004 */ 0, 5, 0x07, 0x19, 0x0D, 0x03, 0x0B, 
  /* RLE: 042 Pixels @ 005,004 */ 42, 0x03, 
  /* ABS: 008 Pixels @ 047,004 */ 0, 8, 0x0B, 0x0B, 0x05, 0x0C, 0x30, 0x0D, 0x05, 0x05, 
  /* RLE: 031 Pixels @ 005,005 */ 31, 0x00, 
  /* RLE: 003 Pixels @ 036,005 */ 3, 0x03, 
  /* RLE: 008 Pixels @ 039,005 */ 8, 0x00, 
  /* ABS: 008 Pixels @ 047,005 */ 0, 8, 0x03, 0x0B, 0x0B, 0x0C, 0x19, 0x0D, 0x05, 0x0B, 
  /* RLE: 031 Pixels @ 005,006 */ 31, 0x00, 
  /* RLE: 003 Pixels @ 036,006 */ 3, 0x03, 
  /* RLE: 008 Pixels @ 039,006 */ 8, 0x00, 
  /* ABS: 008 Pixels @ 047,006 */ 0, 8, 0x03, 0x03, 0x0B, 0x0C, 0x19, 0x0D, 0x0B, 0x0B, 
  /* RLE: 029 Pixels @ 005,007 */ 29, 0x00, 
  /* ABS: 007 Pixels @ 034,007 */ 0, 7, 0x03, 0x03, 0x04, 0x0A, 0x04, 0x03, 0x03, 
  /* RLE: 006 Pixels @ 041,007 */ 6, 0x00, 
  /* ABS: 008 Pixels @ 047,007 */ 0, 8, 0x03, 0x03, 0x0B, 0x0C, 0x19, 0x0D, 0x0B, 0x0B, 
  /* RLE: 028 Pixels @ 005,008 */ 28, 0x00, 
  /* ABS: 009 Pixels @ 033,008 */ 0, 9, 0x03, 0x0B, 0x03, 0x65, 0x64, 0x65, 0x03, 0x0B, 0x03, 
  /* RLE: 005 Pixels @ 042,008 */ 5, 0x00, 
  /* ABS: 008 Pixels @ 047,008 */ 0, 8, 0x03, 0x03, 0x0B, 0x0C, 0x19, 0x0D, 0x0B, 0x0B, 
  /* RLE: 028 Pixels @ 005,009 */ 28, 0x00, 
  /* ABS: 008 Pixels @ 033,009 */ 0, 8, 0x04, 0x1B, 0x64, 0xDD, 0xD8, 0xF3, 0x26, 0x0A, 
  /* RLE: 006 Pixels @ 041,009 */ 6, 0x00, 
  /* ABS: 008 Pixels @ 047,009 */ 0, 8, 0x03, 0x03, 0x0B, 0x07, 0x0E, 0x0D, 0x0B, 0x0B, 
  /* RLE: 026 Pixels @ 005,010 */ 26, 0x00, 
  /* ABS: 024 Pixels @ 031,010 */ 0, 24, 0x03, 0x12, 0x26, 0x59, 0x31, 0x80, 0x80, 0x31, 0x59, 0x38, 0x0A, 0x12, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0B, 0x07, 0x0E, 0x0D, 0x0B, 0x0B, 
  /* RLE: 027 Pixels @ 005,011 */ 27, 0x00, 
  /* ABS: 011 Pixels @ 032,011 */ 0, 11, 0x11, 0x38, 0xC7, 0x44, 0x43, 0x43, 0x44, 0x53, 0x58, 0xF8, 0x0A, 
  /* RLE: 004 Pixels @ 043,011 */ 4, 0x00, 
  /* ABS: 008 Pixels @ 047,011 */ 0, 8, 0x03, 0x03, 0x0B, 0x07, 0x0E, 0x0D, 0x0B, 0x0B, 
  /* RLE: 024 Pixels @ 005,012 */ 24, 0x00, 
  /* ABS: 026 Pixels @ 029,012 */ 0, 26, 0x03, 0x03, 0x0A, 0x24, 0xD6, 0xCA, 0x85, 0x84, 0x83, 0x46, 0x7D, 0x45, 0xD3, 0x61, 0x1B, 0x00, 0x00, 0x04, 0x00, 0x03, 0x0B, 0x07, 0x0E, 0x0D, 0x0B, 0x0B, 
  /* RLE: 013 Pixels @ 005,013 */ 13, 0x00, 
  /* ABS: 002 Pixels @ 018,013 */ 0, 2, 0x04, 0x04, 
  /* RLE: 008 Pixels @ 020,013 */ 8, 0x00, 
  /* ABS: 027 Pixels @ 028,013 */ 0, 27, 0xFF, 0x0D, 0xF1, 0x36, 0xC5, 0xD4, 0xD7, 0xDA, 0xD9, 0x86, 0x46, 0x7B, 0x7F, 0xCB, 0x61, 0x1B, 0x00, 0x00, 0x04, 0x00, 0x03, 0x0B, 0x07, 0x0E, 0x0D, 0x0B, 0x0B, 
  /* RLE: 021 Pixels @ 005,014 */ 21, 0x04, 
  /* ABS: 017 Pixels @ 026,014 */ 0, 17, 0x00, 0x03, 0x09, 0xC4, 0xA8, 0x74, 0x52, 0xBF, 0xF7, 0xFD, 0xDC, 0xC9, 0x82, 0x7C, 0x81, 0xF4, 0x0A, 
  /* RLE: 004 Pixels @ 043,014 */ 4, 0x04, 
  /* ABS: 008 Pixels @ 047,014 */ 0, 8, 0x00, 0x03, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 
  /* RLE: 020 Pixels @ 005,015 */ 20, 0x04, 
  /* ABS: 031 Pixels @ 025,015 */ 0, 31, 0xFF, 0x04, 0xFE, 0xF6, 0xB2, 0x72, 0x71, 0x3F, 0xAB, 0xC6, 0x63, 0xF2, 0xC8, 0x31, 0x53, 0x58, 0x26, 0x12, 0x12, 0x04, 0x04, 0x04, 0x00, 0x03, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 0x04, 
  /* RLE: 012 Pixels @ 006,016 */ 12, 0x11, 
  /* RLE: 006 Pixels @ 018,016 */ 6, 0x04, 
  /* ABS: 033 Pixels @ 024,016 */ 0, 33, 0x06, 0x06, 0x1B, 0xE0, 0x9D, 0xB5, 0xB0, 0x73, 0x3D, 0x6E, 0x76, 0xB7, 0xB9, 0xBC, 0xD5, 0x38, 0x26, 0x0A, 0xFF, 0xFF, 0x04, 0x11, 0x04, 0x00, 0x03, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 0x11, 0x01, 
  /* RLE: 015 Pixels @ 007,017 */ 15, 0x11, 
  /* ABS: 035 Pixels @ 022,017 */ 0, 35, 0x06, 0x06, 0x01, 0xFA, 0xE1, 0x9E, 0x97, 0xD1, 0xDF, 0xAD, 0x70, 0x3D, 0x6B, 0x3F, 0x52, 0x55, 0x10, 0x06, 0x12, 0x06, 0x01, 0x09, 0x09, 0x01, 0x09, 0xFF, 0x03, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 0x01, 0x02, 
  /* RLE: 015 Pixels @ 007,018 */ 15, 0x01, 
  /* ABS: 019 Pixels @ 022,018 */ 0, 19, 0x06, 0x06, 0x63, 0xCE, 0x4A, 0x9C, 0xA5, 0xE5, 0xEA, 0xE2, 0xBE, 0x89, 0x6A, 0x66, 0xAC, 0x10, 0x09, 0x09, 0x09, 
  /* RLE: 004 Pixels @ 041,018 */ 4, 0x01, 
  /* ABS: 010 Pixels @ 045,018 */ 0, 10, 0x02, 0x01, 0x11, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 
  /* RLE: 015 Pixels @ 005,019 */ 15, 0x02, 
  /* ABS: 020 Pixels @ 020,019 */ 0, 20, 0x01, 0x01, 0x0D, 0x62, 0xDE, 0x4A, 0x94, 0x4D, 0x5A, 0x5D, 0xEB, 0xE7, 0xD0, 0xAA, 0x6C, 0x6F, 0xBA, 0x09, 0x12, 0x01, 
  /* RLE: 006 Pixels @ 040,019 */ 6, 0x02, 
  /* ABS: 009 Pixels @ 046,019 */ 0, 9, 0x01, 0x09, 0x00, 0x00, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 
  /* RLE: 015 Pixels @ 005,020 */ 15, 0x02, 
  /* ABS: 019 Pixels @ 020,020 */ 0, 19, 0x06, 0x09, 0x5E, 0x29, 0x91, 0x9B, 0x4E, 0x35, 0x23, 0x5D, 0x5C, 0xA2, 0x7E, 0x27, 0xB1, 0xEF, 0x3C, 0x01, 0x09, 
  /* RLE: 008 Pixels @ 039,020 */ 8, 0x02, 
  /* ABS: 008 Pixels @ 047,020 */ 0, 8, 0x09, 0x00, 0x00, 0x07, 0x0E, 0x0D, 0x0B, 0x03, 
  /* RLE: 013 Pixels @ 005,021 */ 13, 0x02, 
  /* ABS: 019 Pixels @ 018,021 */ 0, 19, 0x09, 0x02, 0x0D, 0x39, 0xCF, 0x18, 0x2A, 0xA3, 0x5A, 0x23, 0x23, 0x35, 0xA4, 0x20, 0x88, 0x8E, 0xF5, 0x12, 0x12, 
  /* RLE: 010 Pixels @ 037,021 */ 10, 0x02, 
  /* ABS: 008 Pixels @ 047,021 */ 0, 8, 0x09, 0x00, 0x00, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 
  /* RLE: 012 Pixels @ 005,022 */ 12, 0x02, 
  /* ABS: 020 Pixels @ 017,022 */ 0, 20, 0x01, 0x06, 0x02, 0x32, 0x1F, 0x18, 0x96, 0x4D, 0x35, 0x23, 0xE9, 0x5B, 0x95, 0x40, 0x1C, 0x32, 0x24, 0x14, 0x09, 0x09, 
  /* RLE: 010 Pixels @ 037,022 */ 10, 0x02, 
  /* ABS: 008 Pixels @ 047,022 */ 0, 8, 0x11, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 
  /* RLE: 010 Pixels @ 005,023 */ 10, 0x02, 
  /* ABS: 020 Pixels @ 015,023 */ 0, 20, 0x01, 0x09, 0x02, 0x10, 0xED, 0x29, 0x8B, 0x2A, 0x4D, 0x16, 0x5C, 0xE8, 0x16, 0xA1, 0x18, 0x27, 0xAF, 0xFC, 0x12, 0x06, 
  /* RLE: 012 Pixels @ 035,023 */ 12, 0x02, 
  /* ABS: 008 Pixels @ 047,023 */ 0, 8, 0x11, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 
  /* RLE: 010 Pixels @ 005,024 */ 10, 0x02, 
  /* ABS: 020 Pixels @ 015,024 */ 0, 20, 0x09, 0x06, 0xFC, 0x54, 0x1C, 0x18, 0x96, 0x4D, 0x16, 0x5B, 0xE6, 0x2D, 0x8D, 0x40, 0x1E, 0xED, 0xFC, 0x01, 0x09, 0x09, 
  /* RLE: 010 Pixels @ 035,024 */ 10, 0x01, 
  /* ABS: 010 Pixels @ 045,024 */ 0, 10, 0x02, 0x01, 0x11, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 
  /* RLE: 008 Pixels @ 005,025 */ 8, 0x02, 
  /* ABS: 021 Pixels @ 013,025 */ 0, 21, 0x01, 0x01, 0x02, 0xFB, 0x21, 0x1F, 0x78, 0x2A, 0x4D, 0x16, 0x5B, 0x17, 0xA6, 0x99, 0x48, 0x27, 0x2F, 0x09, 0x12, 0x09, 0x02, 
  /* RLE: 011 Pixels @ 034,025 */ 11, 0x01, 
  /* ABS: 012 Pixels @ 045,025 */ 0, 12, 0x02, 0x01, 0x11, 0x00, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x02, 0x02, 
  /* RLE: 006 Pixels @ 007,026 */ 6, 0x01, 
  /* ABS: 019 Pixels @ 013,026 */ 0, 19, 0x09, 0x09, 0x24, 0xD2, 0x28, 0x18, 0x20, 0x15, 0x16, 0x17, 0x17, 0x15, 0x87, 0x41, 0xB3, 0xF0, 0x0D, 0x09, 0x09, 
  /* RLE: 015 Pixels @ 032,026 */ 15, 0x01, 
  /* ABS: 010 Pixels @ 047,026 */ 0, 10, 0x11, 0x00, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x02, 0x02, 
  /* RLE: 004 Pixels @ 007,027 */ 4, 0x01, 
  /* ABS: 019 Pixels @ 011,027 */ 0, 19, 0x09, 0x01, 0x14, 0x10, 0x21, 0x28, 0x18, 0x2C, 0x4D, 0x2D, 0x17, 0x4F, 0x15, 0x20, 0x88, 0x8A, 0xEC, 0x12, 0x12, 
  /* RLE: 017 Pixels @ 030,027 */ 17, 0x01, 
  /* ABS: 009 Pixels @ 047,027 */ 0, 9, 0x11, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 0x01, 
  /* RLE: 004 Pixels @ 006,028 */ 4, 0x02, 
  /* ABS: 020 Pixels @ 010,028 */ 0, 20, 0x01, 0x06, 0x09, 0x39, 0xB6, 0xB4, 0x9A, 0x9B, 0x4E, 0x16, 0x17, 0x4F, 0x98, 0x77, 0x88, 0x2F, 0x24, 0x14, 0x06, 0x06, 
  /* RLE: 017 Pixels @ 030,028 */ 17, 0x01, 
  /* ABS: 031 Pixels @ 047,028 */ 0, 31, 0x11, 0x00, 0x00, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 0x01, 0x02, 0x02, 0x02, 0x01, 0x02, 0x02, 0x25, 0x21, 0x29, 0x9A, 0x9F, 0xE3, 0x16, 0x16, 0x2D, 0x15, 0x8F, 0x88, 0x1E, 0x62, 0x12, 0x12, 
  /* RLE: 019 Pixels @ 028,029 */ 19, 0x01, 
  /* ABS: 031 Pixels @ 047,029 */ 0, 31, 0x11, 0x00, 0x00, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 0x01, 0x02, 0x02, 0x01, 0x09, 0x02, 0x3A, 0xC3, 0xBD, 0xCC, 0xA0, 0x22, 0xE4, 0xE4, 0x34, 0x2C, 0x8C, 0x28, 0x21, 0x10, 0x02, 0x06, 0x06, 
  /* RLE: 019 Pixels @ 028,030 */ 19, 0x01, 
  /* ABS: 029 Pixels @ 047,030 */ 0, 29, 0xFF, 0x00, 0x03, 0x07, 0x0E, 0x0D, 0x0B, 0x00, 0x01, 0x02, 0x02, 0x01, 0x09, 0x0D, 0x57, 0xB8, 0xCD, 0x33, 0xDB, 0x22, 0x22, 0x33, 0x4B, 0x93, 0x1E, 0x32, 0x02, 0x12, 0x06, 
  /* RLE: 021 Pixels @ 026,031 */ 21, 0x01, 
  /* ABS: 029 Pixels @ 047,031 */ 0, 29, 0xFF, 0x00, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x02, 0x02, 0x01, 0x09, 0xFB, 0xC0, 0x2E, 0xCC, 0x22, 0x34, 0xA0, 0x92, 0x49, 0x1D, 0xBD, 0x39, 0x1B, 0x09, 0x06, 0x06, 
  /* RLE: 021 Pixels @ 026,032 */ 21, 0x09, 
  /* ABS: 028 Pixels @ 047,032 */ 0, 28, 0xFF, 0x03, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x02, 0x01, 0x14, 0x3B, 0x36, 0x54, 0x1F, 0x92, 0x33, 0x4B, 0x90, 0x1D, 0x8E, 0xAF, 0xEE, 0x06, 0x12, 0x09, 0x01, 
  /* RLE: 022 Pixels @ 025,033 */ 22, 0x09, 
  /* ABS: 026 Pixels @ 047,033 */ 0, 26, 0xFF, 0x03, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x01, 0x09, 0x10, 0xC2, 0x51, 0x2E, 0x90, 0x49, 0x1C, 0x7A, 0x42, 0xA9, 0xC1, 0x10, 0x01, 0x06, 0x06, 
  /* RLE: 024 Pixels @ 023,034 */ 24, 0x09, 
  /* ABS: 026 Pixels @ 047,034 */ 0, 26, 0x00, 0x03, 0x0B, 0x07, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x09, 0x06, 0x37, 0x50, 0x6D, 0x42, 0x1D, 0x1D, 0x47, 0x47, 0xA7, 0xAE, 0x3B, 0x12, 0x12, 0x09, 0x09, 
  /* RLE: 024 Pixels @ 023,035 */ 24, 0x06, 
  /* ABS: 022 Pixels @ 047,035 */ 0, 22, 0x00, 0x03, 0x0B, 0x0C, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x06, 0x12, 0x5F, 0x3E, 0x67, 0x68, 0x79, 0x51, 0xC1, 0x36, 0x37, 0x10, 0x02, 
  /* RLE: 028 Pixels @ 019,036 */ 28, 0x06, 
  /* ABS: 026 Pixels @ 047,036 */ 0, 26, 0x00, 0x03, 0x03, 0x0C, 0x13, 0x0D, 0x0B, 0x00, 0x01, 0x09, 0x12, 0x60, 0x75, 0x69, 0x3E, 0x50, 0xBB, 0x3B, 0x01, 0x00, 0x12, 0x06, 0x09, 0x09, 0xFF, 0xFF, 
  /* RLE: 024 Pixels @ 023,037 */ 24, 0x06, 
  /* ABS: 028 Pixels @ 047,037 */ 0, 28, 0x00, 0x03, 0x03, 0x07, 0x13, 0x0D, 0x0B, 0x03, 0x01, 0x02, 0x09, 0x0D, 0x60, 0x57, 0x5F, 0x37, 0x25, 0x14, 0x09, 0x06, 0x06, 0x06, 0x09, 0x09, 0x06, 0xFF, 0x06, 0x06, 
  /* RLE: 020 Pixels @ 025,038 */ 20, 0xFF, 
  /* ABS: 019 Pixels @ 045,038 */ 0, 19, 0x06, 0xFF, 0x00, 0x03, 0x0B, 0x07, 0x13, 0x0D, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0x00, 0x0B, 0x05, 0x0B, 0x0B, 0x03, 
  /* RLE: 011 Pixels @ 014,039 */ 11, 0x00, 
  /* RLE: 023 Pixels @ 025,039 */ 23, 0x03, 
  /* ABS: 007 Pixels @ 048,039 */ 0, 7, 0x0B, 0x0B, 0x0E, 0x08, 0x25, 0x00, 0x0B, 
  /* RLE: 045 Pixels @ 005,040 */ 45, 0x05, 
  /* ABS: 007 Pixels @ 000,041 */ 0, 7, 0x3A, 0x1A, 0x10, 0x0D, 0x0A, 0x00, 0x03, 
  /* RLE: 013 Pixels @ 007,041 */ 13, 0x00, 
  /* RLE: 030 Pixels @ 020,041 */ 30, 0x04, 
  /* ABS: 004 Pixels @ 000,042 */ 0, 4, 0x14, 0x3C, 0x3B, 0xF9, 
  /* RLE: 046 Pixels @ 004,042 */ 46, 0x0F, 
  /* ABS: 005 Pixels @ 000,043 */ 0, 5, 0x06, 0x02, 0x1A, 0x19, 0x56, 
  /* RLE: 045 Pixels @ 005,043 */ 45, 0x07, 
  0
};  // 1206 bytes for 2200 pixels

GUI_CONST_STORAGE GUI_BITMAP bmfixed = {
  50, // xSize
  44, // ySize
  50, // BytesPerLine
  GUI_COMPRESS_RLE8, // BitsPerPixel
  _acfixed,  // Pointer to picture data (indices)
  &_Palfixed,  // Pointer to palette
  GUI_DRAW_RLE8
};

/*************************** End of file ****************************/