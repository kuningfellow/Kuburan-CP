//UVA 12376 As Long as I Learn, I Live
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    int kas=1;
    cin>>tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        int ar[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        int a,b;
        vector<int>con[n];
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            con[a].push_back(b);
        }
        int maxi=0;
        a=0;
        while (1<2)
        {
            maxi=max(maxi,maxi+ar[a]);
            b=-1;
            for (int i=0;i<con[a].size();i++)
            {
                if (b==-1)
                {
                    b=con[a][i];
                }
                else
                {
                    if (ar[b]<ar[con[a][i]])
                    {
                        b=con[a][i];
                    }
                }
            }
            if (b==-1)break;
            a=b;
        }
        printf ("Case %d: %d %d\n",kas++,maxi,a);
    }
}
