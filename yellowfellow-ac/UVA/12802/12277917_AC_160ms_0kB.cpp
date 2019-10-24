//UVA 12802 Gift From the Gods
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ter[1000005];
int pal(int a)
{
    int temp=a;
    int num[10];
    int dig=0;
    while (temp>0)
    {
        num[dig++]=temp%10;
        temp/=10;
    }
    int good=1;
    for (int i=dig-1;i>=0;i--)
    {
        if (num[i]!=a%10)
        {
            good=0;
        }
        a/=10;
    }
    return good;
}
int main()
{
    ter[1]=1;
    for (int i=2;i<1000005;i++)
    {
        int good=1;
        for (int j=2;j*j<=i;j++)
        {
            if (i%j==0)
            {
                good=0;
                break;
            }
        }
        if (good==1&&pal(i))
        {
            ter[i]=1;
        }
    }
    while (1<2)
    {
        int n;
        cin>>n;
        printf ("%d\n",2*n);
        if (ter[n])break;
    }
}
