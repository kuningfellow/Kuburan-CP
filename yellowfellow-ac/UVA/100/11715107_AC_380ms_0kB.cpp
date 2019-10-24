//UVA 100 The 3n + 1 Problem
#include <stdio.h>
int funx(int a)
{
    int i=0;
    while(1<2)
    {
        i++;
        if (a==1)return i;
        if (a%2==1)a=3*a+1;
        else a=a/2;
    }
}
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        int h;
        int ma=0;
        int low=a<b?a:b;
        int high=a>b?a:b;
        for (int i=low;i<=high;i++)
        {
            h=funx(i);
            if (h>ma)ma=h;
        }
        printf ("%d %d %d\n",a,b,ma);
    }
}
