//UVA 10650 Determinate Prime
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int primes[32500];
int main()
{
    primes[2]=1;
    for (int i=3;i<32500;i++)
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
        if (good==1)
        {
            primes[i]=1;
        }
    }
//    for (int i=0;i<60;i++)
//    {
//        if (primes[i]==1)printf ("%d\n",i);
//    }
    while (1<2)
    {
        int x,y;
        cin>>x>>y;
        if (x==0&&y==0)break;
        if (x>y)
        {
            int temp=y;
            y=x;
            x=temp;
        }
        vector<int>lis;
        int picked[32500];
        for (int i=0;i<32500;i++)
        {
            picked[i]=0;
        }
        for (int i=x;i<=y;i++)
        {
            if (primes[i]==1&&picked[i]==0)
            {
                lis.push_back(i);
                int del=-1;
                for (int j=i+1;j<=y;j++)
                {
                    if (primes[j]==1)
                    {
                        if (del==-1)
                        {
                            del=j-i;
                        }
                        else if (j-lis[lis.size()-1]!=del)
                        {
                            break;
                        }
                        lis.push_back(j);
                    }
                }
                int goodl=0;
                int goodr=0;
                for (int j=1;j<del;j++)
                {
                    if (i-j<0||primes[i-j]==1)
                    {
                        goodl=1;
                    }
                    if (primes[lis[lis.size()-1]+j]==1)
                    {
                        goodr=1;
                    }
                }
                if (goodl==0&&i-del>=0&&primes[i-del]==0)goodl=1;
                if (goodr==0&&primes[lis[lis.size()-1]+del]==0)goodr=1;
                if (lis.size()>2&&goodl==1&&goodr==1)
                {
                    for (int j=0;j<lis.size();j++)
                    {
                        printf ("%d",lis[j]);
                        if (j<lis.size()-1)printf (" ");
                        if (j!=0&&j!=lis.size()-1)
                        {
                            picked[lis[j]]=1;
                        }
                    }
                    printf ("\n");
                }
                lis.clear();
            }
        }
    }
}
