#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for (int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    map<int,int>m1;
    map<int,int>m2;
    map<int,int>m3;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            m1[ar[i]*ar[j]]++;
            m2[ar[i]+ar[j]]++;
        }
    }
    long long int co=0;
    for (map<int, int>::iterator it = m1.begin();it != m1.end() ;it++ )
    {
        for (int i=0;i<n;i++)
        {
            m3[it->first+ar[i]]+=it->second;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (ar[i]==0)continue;
        for (map<int,int>::iterator bt=m2.begin();bt!=m2.end();bt++)
        {
            co+=(long long)bt->second*m3[ar[i]*bt->first];
        }
    }
    printf ("%lld\n",co);
}
