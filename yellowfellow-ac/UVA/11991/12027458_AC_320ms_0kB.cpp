//UVA 11991 Easy Problem from Rujia Liu?
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,a,b;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        vector<int>ar[1000005];
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ar[a].push_back(i);
        }
        for (int i=0;i<m;i++)
        {
            cin>>b>>a;
            if (ar[a].size()<b)printf ("0\n");
            else printf ("%d\n",ar[a][b-1]+1);
        }
    }
}
