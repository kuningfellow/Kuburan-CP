#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
long long int comb(int a, int b)
{
    long long int ret=1;
    for (long long int i=a;i>b;i--)
    {
        ret*=i;
    }
    for (long long int i=1;i<=(a-b);i++)
    {
        ret/=i;
    }
    return ret;
}
int main()
{
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        char rem[500];
        int coun[26];
        scanf("%s",rem);
        int l=strlen(rem);
        for (int i=0;i<26;i++)coun[i]=0;
        for (int i=0;i<l;i++)
        {
            coun[rem[i]-'A']++;
        }
        long long int ways=1;
        for (int i=0;i<26;i++)
        {
            if (coun[i]>0)
            {
                ways*=comb(l,coun[i]);
                l-=coun[i];
            }
        }
        printf ("Data set %d: %lld\n",kas++,ways);
    }
}
