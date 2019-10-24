//UVA 793 Network Connections
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int forest[1000];
int n;
int root (int a)
{
    int ptr=forest[a];
    while (ptr!=forest[ptr])
    {
        ptr=forest[ptr];
    }
    return ptr;
}
void build(int a, int b)
{
    if (forest[b]!=0&&forest[a]!=0)
    {
        int rotb=root(b);
        int rota=root(a);
        for (int i=1;i<=n;i++)
        {
            if (root(i)==rotb)
            {
                forest[i]=rota;
            }
        }
        forest[b]=rota;
        forest[a]=rota;
    }
    else if ((forest[a]==0||forest[a]==a)&&forest[b]==0)
    {
        forest[a]=a;
        forest[b]=a;
    }
    else if ((forest[b]==0||forest[b]==b)&&forest[a]==0)
    {
        forest[b]=b;
        forest[a]=b;
    }
    else
    {
        int ptr;
        if (forest[b]==0)
            ptr=forest[a];
        else if (forest[a]==0)
            ptr=forest[b];
        while (forest[ptr]!=ptr)
        {
            ptr=forest[ptr];
        }
        forest[b]=ptr;
        forest[a]=ptr;
    }
}
int serc(int a, int b)
{
    int ptra=forest[a];
    int ptrb=forest[b];
    while (ptra!=forest[ptra])
    {
        ptra=forest[ptra];
    }
    while (ptrb!=forest[ptrb])
    {
        ptrb=forest[ptrb];
    }
    if (ptra==ptrb&&ptra!=0)return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        getchar();
        char c[500];
        c[0]='\0';
        int ans[2];
        ans[0]=0;
        ans[1]=0;
        while (1<2)
        {
            scanf("%[^\n]s",c);
            if (c[0]=='\0')break;
            getchar();
            int a[2];
            a[0]=0;
            a[1]=0;
            int w=0;
            for (int i=2;i<strlen(c);i++)
            {
                if (c[i]>='0'&&c[i]<='9')
                {
                    a[w]*=10;
                    a[w]+=c[i]-'0';
                }
                else
                {
                    w++;
                }
            }
            if (c[0]=='c')
                build(a[0],a[1]);
            else if (c[0]=='q')
            {
                if (a[0]==a[1])ans[1]++;
                else ans[serc(a[0],a[1])]++;
            }
            c[0]='\0';
        }
        printf ("%d,%d\n",ans[1],ans[0]);
        if (t>0)printf ("\n");
        for (int i=0;i<=n;i++)
        {
            forest[i]=0;
        }
    }
}
