/*
   @Author: Mm1KEE
   @GitHub: https://github.com/Mm1KEE/SimpleFilter
   @Date: 2022-08-29 22:24:24
 * @LastEditTime: 2022-09-01 01:51:14
   @Description: 
   This example demonstrates shows how to use SimpleFilter library with arrays that comes with a length of 3.
   For longer arrays please refer to "SimpleFilterLongArrayExample".

   Copyright (c) 2022 by Mm1KEE, All Rights Reserved.
*/
#include <SimpleFilter.h>
int intArray[3] = { -16, 3, 1};
int longArray[27];
int intAvg;
int max=9;
void setup() {
  Serial.begin(115200);
  while (!Serial);
  //pass the array and its length,get return value as integer
  intAvg = rawDataFilter(intArray,3);
  Serial.println("Current array :"+String(intArray[0])+","+String(intArray[1])+","+String(intArray[2])+";");
  Serial.println("Averaged integer :" + String(intAvg));
  
}

void loop() {}
