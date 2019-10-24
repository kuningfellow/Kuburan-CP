#include <stdio.h>
_Bool pal(long long int a)
{
    int b[100];
    int i=0;
    int len=1;
    while (a>0)
    {
        b[i]=a%10;
        a/=10;
        i++;
    }
    i--;
    len=i;
    for (i=0;i<len+1;i++)
    {
        if (b[len-i]!=b[i])
        {
            return 0;
        }
    }
    return 1;
}
long long int rev(int a)
{
    int b[100];
    int i=0;
    int len=1;
    while (a>0)
    {
        b[i]=a%10;
        a/=10;
        i++;
    }
    i--;
    len=i;
    int mul=1;
    long long int sum=0;
    for(i=0;i<=len;i++)
    {
        sum+=(long long int)mul*(b[i]+b[len-i]);
        mul*=10;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        long long int a;
        scanf("%lld",&a);
        int i=0;
        while (1<2)
        {
            a=rev(a);
            i++;
            if (pal(a)==1)
                break;
        }
        printf ("%d %lld\n",i,a);
        t--;
    }
    return 0;
}
