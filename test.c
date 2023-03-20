
#include "stdio.h"

int main(void)
{
    // 指针强制转换
    unsigned char pMem[] = {0xBF, 0xCB, 0x88, 0x42};
    float *p = (float *)pMem;
    printf("%g\r\n", *p);
    
    // union共用体
    union data
    {
        unsigned char tmp[4];
        float t;
    };
    union data a;
    a.tmp[0] = 0xBF;
    a.tmp[1] = 0xCB;
    a.tmp[2] = 0x88;
    a.tmp[3] = 0x42;
    printf("%f\n", a.t);
    return 0;
}
