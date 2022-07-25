#include "swapFloat.h"
void swapFloat(float* xp, float* yp){  /*Function to Swap Float*/
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
