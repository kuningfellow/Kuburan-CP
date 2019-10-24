#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isprime[1000000];
vector<int>lis;
void siev()
{
    for (int i=2;i<1000000;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<1000000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
int fac(int a)
{
    int co=0;
    for(int i=0;i<lis.size();i++)
    {
        if (a>0&&a%lis[i]==0)
        {
            co++;
            while (a>0&&a%lis[i]==0)
            {
                a/=lis[i];
            }
        }
        if (a==0)break;
    }
    return co;
}
int main()
{
    siev();
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        printf ("%d : %d\n",n,fac(n));
    }
}
