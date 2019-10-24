//UVA 11877 The Coco-Cola Store
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    while (1<2)
    {
        int n,a;
        cin>>n;
        if (n==0)break;
        int bot=0;
        int maxi=0;
        int bor=0;
        while (bor<=3)
        {
            a=n+bor;
            bot=0;
            while (a>=3)
            {
                bot+=a/3;
                a=a/3+a%3;
            }
            if (a>=bor&&bot>maxi)
            {
                maxi=bot;
            }
            bor++;
        }
        printf ("%d\n",maxi);
    }
}
