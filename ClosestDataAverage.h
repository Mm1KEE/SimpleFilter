/*
 * @Author: Mm1KEE
 * @GitHub: https://github.com/Mm1KEE/ClosestDataAverage
 * @Date: 2022-08-28 20:47:36
 * @LastEditTime: 2022-08-29 00:13:16
 * @Description: denoising for the raw input from touch screen
 * 
 * Copyright (c) 2022 by Mm1KEE, All Rights Reserved. 
 */
#ifndef _CDA_H_
#define _CDA_H_

static int xDif[3], yDif[3];
static int _mouseXAvg, _mouseYAvg;

void rawDataFilter(int xArray[3], int yArray[3]);
int getXAvg();
int getYAvg();

#endif
