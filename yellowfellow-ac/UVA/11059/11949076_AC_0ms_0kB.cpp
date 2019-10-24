//UVA 11059 Maximum Product
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int kas=1;
    FILE *out;
    out=fopen("dbug.txt","w");
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        long long int ar[n];
        for (int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        long long int maxi=0;
        long long int temp;
        for (int i=0;i<n;i++)
        {
            temp=1;
            for (int j=i;j<n;j++)
            {
                temp*=ar[j];
                if (temp>maxi)
                {
                    maxi=temp;
                }
            }
        }
        printf ("Case #%d: The maximum product is %lld.\n\n",kas++,maxi);
    }
}
