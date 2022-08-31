/*
   @Author: Mm1KEE
   @GitHub: https://github.com/Mm1KEE/SimpleFilter
   @Date: 2022-08-28 20:47:36
   @LastEditTime: 2022-08-29 00:13:16
   @Description: denoising for the raw input from touch screen

   Copyright (c) 2022 by Mm1KEE, All Rights Reserved.
*/
#ifndef _CDA_H_
#define _CDA_H_

static int _intDif[3];
static int _buf1[9],_buf0[3];

int rawDataFilter(int intArray[3]);
int rawDataFilter(int intArray[],int len);
static int getRoot(int input, int r);

#endif
