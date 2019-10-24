//UVA 459 Graph Connectivity
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ma[26];
int siz;
int serc(int i)
{
    while (ma[i]!=i)
    {
        i=ma[i];
    }
    return i;
}
int update(int i, int n)
{
    for (int j=0;j<siz;j++)
    {
        if (ma[j]==i)
        {
            ma[j]=n;
        }
    }
}
int link(char a, char b)
{
    int x=a-'A';
    int y=b-'A';
    if (ma[x]==-1&&ma[y]==-1)
    {
        ma[x]=x;
        ma[y]=x;
    }
    else if (ma[x]!=-1&&ma[y]==-1)
    {
        ma[y]=x;
    }
    else if (ma[x]==-1&&ma[y]!=-1)
    {
        ma[x]=y;
    }
    else if (ma[x]!=-1&&ma[y]!=-1)
    {
        int tx=serc(x);
        int ty=serc(y);
        ma[x]=ty;
        ma[y]=ty;
        update(tx,ty);
    }
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        char c[5];
        scanf("%s",c);
        getchar();
        siz=c[0]-'A'+1;
        for (int i=0;i<siz;i++)ma[i]=-1;
        while (1<2)
        {
            c[0]='\0';
            scanf("%[^\n]s",c);
            getchar();
            if (c[0]=='\0')break;
            link(c[0],c[1]);
        }
        int co=0;
        for (int i=0;i<siz;i++)
        {
            if (ma[i]==i||ma[i]==-1)co++;
        }
        printf ("%d\n",co);
        if (tc>0)printf ("\n");
    }
}
