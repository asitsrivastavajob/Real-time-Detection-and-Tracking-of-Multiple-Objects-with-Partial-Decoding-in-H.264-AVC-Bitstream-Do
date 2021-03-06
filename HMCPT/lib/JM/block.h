
/*!
 ************************************************************************
 * \file block.h
 *
 * \brief
 *    definitions for block decoding functions
 *
 * \author
 *  Inge Lille-Langoy               <inge.lille-langoy@telenor.com>    \n
 *  Telenor Satellite Services                                         \n
 *  P.O.Box 6914 St.Olavs plass                                        \n
 *  N-0130 Oslo, Norway
 *
 ************************************************************************
 */

#ifdef __cplusplus
extern "C" { //visible only to a C++ compiler
#endif

#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "global.h"

#define DQ_BITS         6
#define DQ_ROUND        (1<<(DQ_BITS-1))

extern const byte QP_SCALE_CR[52] ;
extern const int  dequant_coef[6][4][4];
extern const unsigned char subblk_offset_x[3][8][4];
extern const unsigned char subblk_offset_y[3][8][4];

#endif

#ifdef __cplusplus
} //visible only to a C++ compiler
#endif