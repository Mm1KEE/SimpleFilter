# ClosestAverage
Simple denoising algorithm for my touch library , which (in theory) could also be used to process other raw inputs.Based on the "Averaging the Closest Data" in this doc by Wendy Fang from TI.
https://www.ti.com/lit/an/sbaa155a/sbaa155a.pdf
# Usage
Create one (or two) array containing 3 integers.

```
int xArray[3] = { -16, 3, 1};
int yArray[3] = { -126, 2, 2 };
```

Pass your int array to this library , use `getXAvg()` and `getYAvg()` to get return value.

```
int xAvg=getXAvg();
int yAvg=getYAvg();
```

Above example will get a result of `2` and `2`.