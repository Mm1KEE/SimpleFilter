# SimpleFilter
Simple denoising filter for touch library , which (in theory) could also be used to process other anolog inputs.Based on the "Averaging the Closest Data" in this doc by Wendy Fang from TI.
https://www.ti.com/lit/an/sbaa155a/sbaa155a.pdf
# Usage
0.Install this library from Arduino IDE's library manager or manually clone this repository to your Arduino library folder.  
1.Create one (or two) array containing 3 integers.

```
int intArray[3] = { -16, 3, 1};
```

2.Pass your int array and its length as arguments to this library.This function will return the result as integer.

```
int result=rawDataFilter(intArray,3);
```

3.Above example will get a result of `2`.
# How this filter works
This filter will take arrays of 3 integers,choose the closest two then return the average.  
For example, if your touch screen reads a series of inputs `{20,22,0}`,this filter will return a result of `21`.  