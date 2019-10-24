//UVA 255 Correct Move
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ma[9][9];
int serc(int k ,int q, int nq)
{
    int x=k/8,y=k%8;
    int xq=q/8,yq=q%8;
    int xnq=nq/8,ynq=nq%8;
    if (xnq!=xq&&ynq!=yq)
    {
        return 1;
    }
    if (xnq==xq&&ynq==yq)
    {
        return 1;
    }
    int allow=1;
    int legal=1;
    if (ynq==yq)
    {
        if (xnq>xq)
        {
            for (int i=xq+1;i<=xnq;i++)
            {
                if (yq==y&&i==x)
                {
                    legal=0;
                }
            }
            if (ma[xnq][yq]==1)
            {
                allow=0;
            }
        }
        else
        {
            for (int i=xnq;i<xq;i++)
            {
                if (yq==y&&i==x)
                {
                    legal=0;
                }
            }
            if (ma[xnq][yq]==1)
            {
                allow=0;
            }
        }
    }
    else if (xnq==xq)
    {
        if (ynq>yq)
        {
            for (int i=yq+1;i<=ynq;i++)
            {
                if (xq==x&&i==y)
                {
                    legal=0;
                }
            }
            if (ma[xq][ynq]==1)
            {
                allow=0;
            }
        }
        else
        {
            for (int i=ynq;i<yq;i++)
            {
                if (xq==x&&i==y)
                {
                    legal=0;
                }
            }
            if (ma[xq][ynq]==1)
            {
                allow=0;
            }
        }
    }
    if (legal==0)return 1;
    else if (allow==0)return 2;
    for (int i=0;i<8;i++)
    {
        ma[xnq][i]++;
        ma[i][ynq]++;
    }
    int con=0;
    if (x+1<8&&ma[x+1][y]==1)con=1;
    if (x-1>=0&&ma[x-1][y]==1)con=1;
    if (y+1<8&&ma[x][y+1]==1)con=1;
    if (y-1<8&&ma[x][y-1]==1)con=1;
    if (con==0)return 3;
    else if (con==1)return 4;
}
int main()
{
    while (1<2)
    {
        int a[3];
        char s[50];
        if (scanf("%[^\n]",s)==EOF)break;
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                ma[i][j]=0;
            }
        }
        getchar();
        int bo=0;
        for (int i=0;i<3;i++)a[i]=0;
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                a[bo]*=10;
                a[bo]+=s[i]-'0';
            }
            else
            {
                bo++;
            }
        }
        int x=a[0]/8;
        int y=a[0]%8;
        ma[x][y]=1;
        if (x+1<8)ma[x+1][y]=1;
        if (x-1>=0)ma[x-1][y]=1;
        if (y+1<8)ma[x][y+1]=1;
        if (y-1>=0)ma[x][y-1]=1;
        if (a[0]==a[1])
        {
            printf ("Illegal state\n");
            continue;
        }
        int res=serc(a[0],a[1],a[2]);
        if (res==1)
        {
            printf ("Illegal move\n");
            continue;
        }
        else if (res==2)
        {
            printf ("Move not allowed\n");
            continue;
        }
        else if (res==3)
        {
            printf ("Stop\n");
            continue;
        }
        else if (res==4)
        {
            printf ("Continue\n");
            continue;
        }
    }
}
