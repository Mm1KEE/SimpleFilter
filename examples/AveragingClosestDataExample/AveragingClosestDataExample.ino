/*
   @Author: Mm1KEE
   @GitHub: https://github.com/Mm1KEE/ClosestAverage
   @Date: 2022-08-29 22:24:24
   @LastEditTime: 2022-08-29 22:32:07
   @Description: This demonstrates shows how to use ClosestAverage library.

   Copyright (c) 2022 by Mm1KEE, All Rights Reserved.
*/
#include <ClosestAverage.h>
int xArray[3] = { -16, 3, 1};
int yArray[3] = { -126, 2, 2 };
int xAvg, yAvg;
void setup() {
  Serial.begin(115200);
  while (!Serial);
  //pass the array
  rawDataFilter(xArray, yArray);
  //get results
  xAvg = getXAvg();
  yAvg = getYAvg();
  Serial.println("averaged x:" + String(xAvg));
  Serial.println("averaged y:" + String(yAvg));
}

void loop() {
  //read int form source,eg,serial,anolog inputs
  Serial.println("Input 3 integers for process.");
  for (int i = 0; i <= 2; i++) {
    while (!Serial.available());
    //store int in the array
    xArray[i] = Serial.parseInt(SKIP_ALL,10);
    Serial.println("Read int " + String(i) + " :" + String(xArray[i]));
  }
  //process the array
  rawDataFilter(xArray, yArray);
  //get result
  xAvg = getXAvg();
  Serial.println("Closest Average of above numbers is :" + String(xAvg));
}
