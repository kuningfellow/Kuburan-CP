//UVA 11503 Virtual Friends
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
map<string,int>name;
int net[100005];
int par[100005];
int siz=0;
int finpar(int x)
{
    if (par[x]==x)
    {
        return x;
    }
    else return par[x]=finpar(par[x]);
}
int update(int x, int y)
{
    int X=finpar(x);
    int Y=finpar(y);
    if (Y!=X)
    {
        net[Y]+=net[X];
        net[X]=0;
        par[X]=Y;
        return net[Y];
    }
    else if (Y==X)
    {
        return net[Y];
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        scanf("%d",&n);
        int stretch=0;
        siz=1;
        char temp[25];
        char tamp[25];
        int one;
        int two;
        int res;
        for (int i=0;i<n;i++)
        {
            scanf("%s%s",temp,tamp);
            if (name[temp]==0)
            {
                one=siz;
                name[temp]=siz++;
            }
            else one=name[temp];
            if (name[tamp]==0)
            {
                two=siz;
                name[tamp]=siz++;
            }
            else two=name[tamp];
            if (stretch<siz)
            {
                for (int j=stretch;j<siz;j++)
                {
                    net[j]=1;
                    par[j]=j;
                }
                stretch=siz;
            }
            res=update(one,two);
            printf ("%d\n",res);
        }
        name.clear();
    }
}
