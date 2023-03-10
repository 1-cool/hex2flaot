#include <stdio.h>
#include <string.h>
char name[41][25] = {"H2峰点", "H2峰高", "油中H2浓度", "CO峰点", "CO峰高", "油中CO浓度", "CH4峰点", "CH4峰高", "油中CH4浓度", "C2H4峰点", "C2H4峰高", "油中C2H4浓度", "C2H6峰点", "C2H6峰高", "C2H6浓度", "C2H2峰点", "C2H2峰高", "C2H2浓度", "CO2峰点", "CO2峰高", "CO2浓度", "O2峰点", "O2峰高", "O2浓度", "O2气体浓度", "油罐温度", "柱箱温度", "柜内温度", "柜外温度", "真空泵温度", "定量管压力", "油罐压力", "秒:分:时: 日-月-年", "温度", "湿度", "铁心大电流", "铁心小电流", "ppm", "微水油温", "微水水活性", "微水水含量"};
// 将十六进制转成浮点型，cnt是几位转一个数
float *hex(int cnt)
{
    unsigned char str[4] = "";
    for (int i = 0; i < cnt; ++i)
    {
        int t;
        scanf("%x", &t);
        str[i] = t;
    }
    float *p = (float *)str;
    return p;
}

int main()
{
    int w = 0;
    // 去掉前面的
    for (int i = 0; i < 5; i++)
    {
        hex(3);
    }

    // 气体
    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("%s：", name[w++]);
            float *h = hex(4);
            printf("%g\r\n", *h);
        }
        hex(4);
    }
    // 氧气
    for (int i = 0; i < 4; i++)
    {
        printf("%s：", name[w++]);
        float *h = hex(4);
        printf("%g\r\n", *h);
    }
    // 温度和压力
    for (int i = 0; i < 7; i++)
    {
        printf("%s：", name[w++]);
        float *h = hex(4);
        printf("%g\r\n", *h);
    }
    // 日期  秒:分:时: 日-月-年
    printf("%s：", name[w++]);
    for (int i = 0; i < 6; i++)
    {
        int t;
        scanf("%x", &t);
        printf("%d ", t);
    }
    printf("\n");
    // 温湿度
    for (int i = 0; i < 2; i++)
    {
        printf("%s：", name[w++]);
        float *h = hex(4);
        printf("%g\r\n", *h);
    }
    // 铁芯和ppm
    for (int i = 0; i < 3; i++)
    {
        printf("%s：", name[w++]);
        float *h = hex(4);
        printf("%g\r\n", *h);
    }
    // 微水
    for (int i = 0; i < 3; i++)
    {
        printf("%s：", name[w++]);
        int t;
        scanf("%x", &t);
        hex(1);
        float tmp;
        if (i == 1)
            tmp = t * 0.001;
        else
            tmp = t * 0.1;
        printf("%.3f\n", tmp);
    }
    // 去掉校验码和尾
    hex(3);
    return 0;
}