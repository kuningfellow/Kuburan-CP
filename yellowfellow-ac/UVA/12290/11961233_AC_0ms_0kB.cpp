//UVA 12290 Counting Game
#include <stdio.h>
#include <iostream>
using namespace std;
int has(int n)
{
    if (n%7==0)return 1;
    while (n>0)
    {
        if ((n%10)==7)return 1;
        n/=10;
    }
    return 0;
}
int main()
{
    int n,m,k;
    while (1<2)
    {
        cin>>n>>m>>k;
        if (n==0)break;
        int pas=0;
        int co=0;
        int po=1;
        int dir=0;
        while (k>0)
        {
            co++;
            if (po==m&&has(co))
            {
                k--;
            }
            if (k==0)
            {
                printf ("%d\n",co);
                break;
            }
            int mov=1;
            while (mov)
            {
                if (dir==1)
                {
                    if (po>1)
                    {
                        po--;
                        mov=0;
                    }
                    else dir=0;
                }
                if (dir==0)
                {
                    if (po<n)
                    {
                        po++;
                        mov=0;
                    }
                    else dir=1;
                }
            }
        }
    }
}
