//UVA 371 Ackerman Functions
#include <stdio.h>
#include <iostream>
using namespace std;
int ack(long long int a)
{
    if (a==1)return 1;
    else if (a%2==0)return 1+ack(a/2);
    else return 1+ack(3*a+1);
}
int main()
{
    while (1<2)
    {
        long long int a,b;
        cin>>a>>b;
        if (a==0&&b==0)break;
        if (a>b)
        {
            int temp=b;
            b=a;
            a=temp;
        }
        int ac=0;
        long long int mi;
        int res;
        for (long long int i=a;i<=b;i++)
        {
            if (i==1)
                res=4;
            else res=ack(i);
            if (res>ac)
            {
                ac=res;
                mi=i;
            }
        }
        printf ("Between %lld and %lld, %lld generates the longest sequence of %d values.\n",a,b,mi,ac-1);
    }
}
