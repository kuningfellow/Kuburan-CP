//UVA 1225 Digit Counting
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        cin>>a;
        int co[10];
        for (int i=0;i<10;i++)co[i]=0;
        for (int i=1;i<=a;i++)
        {
            b=i;
            while (b>0)
            {
                co[b%10]++;
                b/=10;
            }
        }
        for (int i=0;i<10;i++)
        {
            printf ("%d",co[i]);
            if (i<9)printf (" ");
        }
        printf ("\n");
    }
}
