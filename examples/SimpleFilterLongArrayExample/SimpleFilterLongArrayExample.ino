/*
   @Author: Mm1KEE
   @GitHub: https://github.com/Mm1KEE/SimpleFilter
   @Date: 2022-08-29 22:24:24
 * @LastEditTime: 2022-09-01 01:49:46
   @Description: 
   This example demonstrates shows how to use SimpleFilter library with long arrays .
   In this example,integers are acquired from serial,but you can use pretty much any 
   source，like adc.                

   Copyright (c) 2022 by Mm1KEE, All Rights Reserved.
*/
#include <SimpleFilter.h>
int intArray[3] = { -16, 3, 1};
int longArray[27];
int intAvg;
void setup() {
  Serial.begin(115200);
  while (!Serial);
  //pass the array,get return value as integer
  intAvg = rawDataFilter(intArray,3);
  Serial.println("Current array :"+String(intArray[0])+","+String(intArray[1])+","+String(intArray[2])+";");
  Serial.println("Averaged integer :" + String(intAvg));
  
}

void loop() { 
  int i;
  int max=9;
  //read 9 integers form serial
  Serial.println("Input "+String(max)+" integers for process.");
  for (i = 0; i <= max-1; i++) {
    while (!Serial.available());
    //read int from serial then store them in the array
    longArray[i] = Serial.parseInt(SKIP_ALL, 10);
    Serial.println("Read integer " + String(i) + " :" + String(longArray[i]));
  }
  //display collected array
  Serial.print("Collected Array:");
  for(int j=0;j<=i-1;j++){
    Serial.print(String(longArray[j])+",");
  }
  Serial.println();
  //process the array
  intAvg = rawDataFilter(longArray,i);
  //print the result
  Serial.println("Closest Average of above numbers is :" + String(intAvg));
}
