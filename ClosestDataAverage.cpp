/*
 * @Author: Mm1KEE
 * @GitHub: https://github.com/Mm1KEE/ClosestDataAverage
 * @Date: 2022-08-28 20:47:36
 * @LastEditTime: 2022-08-29 00:13:54
 * @Description: 
 * 
 * Copyright (c) 2022 by Mm1KEE, All Rights Reserved. 
 */
#include "ClosestDataAverage.h"
#include "Arduino.h"

void rawDataFilter(int xArray[3], int yArray[3]) {
  xDif[0] = xArray[0] - xArray[1];
  xDif[1] = xArray[1] - xArray[2];
  xDif[2] = xArray[2] - xArray[0];
  yDif[0] = yArray[0] - yArray[1];
  yDif[1] = yArray[1] - yArray[2];
  yDif[2] = yArray[2] - yArray[0];
  for (char j = 0; j < 3; j++) {
    xDif[j] = abs(xDif[j]);
    yDif[j] = abs(yDif[j]);
  }
  if (xDif[0] < xDif[1]) {
    if (xDif[0] < xDif[2]) {
      _mouseXAvg = xArray[0] + xArray[1];
    }
    else {
      _mouseXAvg = xArray[0] + xArray[2];
    }
  }
  else {
    if (xDif[1] < xDif[2]) {
      _mouseXAvg = xArray[1] + xArray[2];
    }
    else {
      _mouseXAvg = xArray[0] + xArray[2];
    }
  }
  _mouseXAvg >>= 1;
  if (yDif[0] < yDif[1]) {
    if (yDif[0] < yDif[2]) {
      _mouseYAvg = yArray[0] + yArray[1];
    }
    else {
      _mouseYAvg = yArray[0] + yArray[2];
    }
  }
  else {
    if (yDif[1] < yDif[2]) {
      _mouseYAvg = yArray[1] + yArray[2];
    }
    else {
      _mouseYAvg = yArray[0] + yArray[2];
    }
  }
  _mouseYAvg >>= 1;
}

int getXAvg() {
  return _mouseXAvg;
}

int getYAvg() {
  return _mouseYAvg;
}
