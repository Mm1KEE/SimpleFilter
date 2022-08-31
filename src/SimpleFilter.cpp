/*
   @Author: Mm1KEE
   @GitHub: https://github.com/Mm1KEE/SimpleFilter
   @Date: 2022-08-28 20:47:36
   @LastEditTime: 2022-08-29 00:13:54
   @Description:

   Copyright (c) 2022 by Mm1KEE, All Rights Reserved.
*/
#include "SimpleFilter.h"
#include "Arduino.h"

int rawDataFilter(int intArray[3]) {
  int _intAvg;
  _intDif[0] = intArray[0] - intArray[1];
  _intDif[1] = intArray[1] - intArray[2];
  _intDif[2] = intArray[2] - intArray[0];
  for (char j = 0; j < 3; j++) {
    _intDif[j] = abs(_intDif[j]);
  }
  if (_intDif[0] < _intDif[1]) {
    if (_intDif[0] < _intDif[2]) {
      _intAvg = intArray[0] + intArray[1];
    }
    else {
      _intAvg = intArray[0] + intArray[2];
    }
  }
  else {
    if (_intDif[1] < _intDif[2]) {
      _intAvg = intArray[1] + intArray[2];
    }
    else {
      _intAvg = intArray[0] + intArray[2];
    }
  }
  _intAvg >>= 1;
  //Serial.print("Current array :" + String(intArray[0]) + "," + String(intArray[1]) + "," + String(intArray[2]) + ";");
  //Serial.println("Averaged integer :" + String(_intAvg));
  return _intAvg;
}

int rawDataFilter(int intArray[], int len) {
  //int processedIndex = 0, bufferIndex = 0;
  //int processedRound = 0;
  int _intAvg;
  int _buf[3];
  //Serial.print("array len:"+String(len)+";");
  if (len == 3) {
    _buf[0] = intArray[0];
    _buf[1] = intArray[1];
    _buf[2] = intArray[2];
    return rawDataFilter(_buf);
  }
  else {
    int processRound = getRoot(len, 3)-1;
    int targetCount = pow(3, processRound);
    byte addr1=0;
    byte addr2=addr1+targetCount;
    byte addr3=addr2+targetCount;
    //Serial.println("addr1:"+String(addr1)+"addr2:"+String(addr2)+"addr3:"+String(addr3)+",count:"+String(targetCount));
    _buf[0] = rawDataFilter(intArray,targetCount);
    _buf[1] = rawDataFilter((intArray+addr2),targetCount);
    _buf[2] = rawDataFilter((intArray+addr3),targetCount);
    return rawDataFilter(_buf,3);
  }
}

int getRoot(int input, int r) {
  int i = 0;
  for (int j = input; j >= r; j /= r) {
    i++;
  }
  //Serial.println("Input:" + String(input) + ",root:" + String(i));
  return i;
}
