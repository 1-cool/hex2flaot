
#include "stdio.h"
 
int main(void)
{
    unsigned char pMem[] = {0xBF,0xCB,0x88,0x42};
    float *p = (float*)pMem;
    printf("%g\r\n",*p);
    return 0;
}
