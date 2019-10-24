#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b)
{
    if (a==0||b==0)return -1;
    if (a<0)a=-a;
    if (b<0)b=-b;
    int rem=1;
    if (a<b)
    {
        rem=a;
        a=b;
        b=rem;
    }
    while (rem>0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
vector<int>lis;
vector<int>ram;
int main()
{
    while (1<2)
    {
        int a;
        int maxi=0;
        while (1<2)
        {
            cin>>a;
            if (-a>maxi)maxi=a;
            if (a>maxi)maxi=a;
            if (a==0)break;
            lis.push_back(a);
        }
        if (lis.size()==0)break;
        int l=lis.size();
        for (int i=1;i<l;i++)
        {
            ram.push_back(lis[0]-lis[i]);
        }
        l=ram.size();
        int ans=ram[0];
        for (int i=1;i<l;i++)
        {
            ans=gcd(ram[i],ans);
        }
        if(ans<0) ans*=-1;
        printf ("%d\n",ans);
        ram.clear();
        lis.clear();
    }
}
