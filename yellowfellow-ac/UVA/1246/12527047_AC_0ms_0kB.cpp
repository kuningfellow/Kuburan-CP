#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
bool notprime[10005];
bool yes[10005];
int adj[2005];
int siz;
void siev()
{
    for (int i=2;i<10005;i++)
    {
        if (notprime[i]==0)
        {
            adj[siz++]=i;
            for (int j=i*2;j<10005;j+=i)
            {
                notprime[j]=1;
            }
        }
    }
}
void serc()
{
    for (int i=2;i<10005;i++)
    {
        int co=1;
        int temp=i;
        if (notprime[i]==0)
        {
            yes[i]=1;
            continue;
        }
        int rem;
        for (int j=0;j<siz;j++)
        {
            if (temp%adj[j]==0&&temp>1)
            {
                rem=1;
                while (temp%adj[j]==0&&temp>0)
                {
                    rem++;
                    temp/=adj[j];
                }
                co*=rem;
            }
            if (temp==1)break;
        }
        if (notprime[co]==0)
        {
            yes[i]=1;
        }
    }
}
int main()
{
    siev();
    serc();
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b;
        cin>>a>>b;
        int cou=0;
        vector<int>lis;
        for (int i=a;i<=b;i++)
        {
            if (yes[i]==1)
            {
                cou++;
                lis.push_back(i);
            }
        }
        if (cou==0)printf ("-1\n");
        else
        {
            for (int i=0;i<lis.size();i++)
            {
                printf ("%d",lis[i]);
                cou--;
                if (cou>0)printf (" ");
            }
            printf ("\n");
        }
    }
}
