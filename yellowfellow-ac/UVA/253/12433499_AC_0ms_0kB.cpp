//UVA 253 Cube painting
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int base[6][6]={0,1,2,3,4,5,
                1,0,3,2,5,4,
                2,0,1,4,5,3,
                3,0,4,1,5,2,
                4,0,2,3,5,1,
                5,1,3,2,4,0};
int phase[4][6]={0,1,2,3,4,5,
                0,2,4,1,3,5,
                0,4,3,2,1,5,
                0,3,1,4,2,5};
int main()
{
    char rem[7];
    char ram[7];
    while (scanf("%6s%6s",rem,ram)!=EOF)
    {
        int yes=0;
        int tem;
        int b=0;
        for (int i=0;i<24;i++)
        {
            tem=1;
            for (int j=0;j<6;j++)
            {
                if (rem[base[i/4][phase[i%4][j]]]!=ram[j])
                {
                    tem=0;
                    break;
                }
            }
            if (tem==1)
            {
                yes=1;
                break;
            }
        }
        if (yes==1)printf ("TRUE\n");
        else printf ("FALSE\n");
    }
}
