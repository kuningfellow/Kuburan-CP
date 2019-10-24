//UVA 11150 Cola
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int maxi=0;
        int bor=0,co,bot;
        while (bor<=3)
        {
            co=n;
            bot=n+bor;
            while (bot>=3)
            {
                co+=bot/3;
                bot=bot/3+bot%3;
            }
            if (co>maxi&&bot>=bor)maxi=co;
            bor++;
        }
        printf ("%d\n",maxi);
    }
}
