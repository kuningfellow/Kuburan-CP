#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[66000];
vector<int>lis;
void sieve()
{
    for (int i=2;i<66000;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<66000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
vector<int>keep;
vector<int>deg;
long long int fen(long long int b)
{
    int co=0;
    for (int i=0;i<lis.size();i++)
    {
        co=0;
        while (b%lis[i]==0)
        {
            co++;
            b/=lis[i];
        }
        if (co>0)
        {
            keep.push_back(co);
            deg.push_back(lis[i]);
        }
    }
    return b;
}
int main()
{
    sieve();
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        keep.clear();
        deg.clear();
        if (a>=b)printf ("%d divides %d!\n",b,a);
        else if (a==0&&b==1)printf ("%d divides %d!\n",b,a);
        else
        {
            int ram=fen(b);
            int good=1;
            if (ram>a)good=0;
            int tem;
            int l=keep.size();
            for (int i=0;i<l;i++)
            {
                for (int j=deg[i];j<=a;j+=deg[i])
                {
                    tem=j;
                    while (tem%deg[i]==0)
                    {
                        tem/=deg[i];
                        keep[i]--;
                        if (keep[i]<=0)break;
                    }
                    if(keep[i]<=0) break;
                }
                if (keep[i]>0)
                {
                    good=0;
                    break;
                }
            }
            if (good==1)printf ("%d divides %d!\n",b,a);
            else printf ("%d does not divide %d!\n",b,a);
        }
    }
}
