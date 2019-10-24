//UVA 386 Perfect Cubes
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<int,int>cube;
    vector<pair<int,pair<int,int> > >lis[205];
    for (int i=1;i<=200;i++)
    {
        cube[i*i*i]=i;
    }
    for (int i=2;i<=200;i++)
    {
        for (int j=i;j<=200;j++)
        {
            for (int k=j;k<=200;k++)
            {
                if (cube[i*i*i+j*j*j+k*k*k]>1)
                {
                    lis[cube[i*i*i+j*j*j+k*k*k]].push_back(pair<int,pair<int,int> >(i,pair<int,int>(j,k)));
                }
            }
        }
    }
    for (int i=0;i<=200;i++)
    {
        for (int j=0;j<lis[i].size();j++)
        {
            printf ("Cube = %d, Triple = (%d,%d,%d)\n",i,lis[i][j].first,lis[i][j].second.first,lis[i][j].second.second);
        }
    }
    return 0;
}
