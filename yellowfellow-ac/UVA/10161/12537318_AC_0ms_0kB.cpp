#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    while (1<2)
    {
        cin>>n;
        if (n==0)break;
        if (n<=4)
        {
            if (n==1)printf ("1 1\n");
            if (n==2)printf ("1 2\n");
            if (n==3)printf ("2 2\n");
            if (n==4)printf ("2 1\n");
        }
        else
        {
            n-=4;
            int dir=0;
            int k=5;
            while (n-k>0)
            {
                n-=k;
                k+=2;
                dir++;
            }
            int x;
            int y;
            if (dir%2==0)
            {
                x=dir+3;
                y=1;
                if (n>k/2)
                {
                    x=x-(n-(k/2))+1;
                    y=dir+3;
                }
                else
                {
                    y=n;
                }
            }
            else
            {
                x=1;
                y=dir+3;
                if (n>k/2)
                {
                    y=y-(n-(k/2))+1;
                    x=dir+3;
                }
                else
                {
                    x=n;
                }
            }
            printf ("%d %d\n",x,y);
        }
    }
}
