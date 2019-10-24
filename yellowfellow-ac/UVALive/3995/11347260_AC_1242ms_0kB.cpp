#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int ma[16][16];
int dp[1<<17][16][16];
int X,Y;
int serc(int mask, int x, int y)
{
    mask&=((1<<17)-1);
    if (x==0&&y==Y)
    {
        return 0;
    }
    if (dp[mask][x][y]>0)
    {
        return dp[mask][x][y];
    }
    int tamp;
    int temp=0;
    if (x-1>=0&&x+1<X&&(mask&1)==0&&(mask&2)==0&&(mask&(1<<X))==0&&(mask&(1<<(X+1)))==0&&(mask&(1<<(X-1)))==0)
    {
        temp=ma[x][y]+serc((mask|1)<<1,x+1,y);
    }
    else if (x==0&&x+1<X&&(mask&1)==0&&(mask&(1<<X))==0&&(mask&(1<<(X-1)))==0)
    {
        temp=ma[x][y]+serc((mask|1)<<1,x+1,y);
    }
    else if (x+1==X&&x-1>=0&&(mask&1)==0&&(mask&2)==0&&(mask&(1<<X))==0&&(mask&(1<<(X+1)))==0)
    {
        temp=ma[x][y]+serc((mask|1)<<1,0,y+1);
    }
    else if (x==0&&x+1==X&&(mask&1)==0&&(mask&(1<<X))==0)
    {
        temp=ma[x][y]+serc((mask|1)<<1,0,y+1);
    }
    int timp;
    if (x+1==X)
    {
        timp=serc(mask<<1,0,y+1);
    }
    else if (x+1<X)
    {
        timp=serc(mask<<1,x+1,y);
    }
    tamp=max(temp,timp);
    dp[mask][x][y]=tamp;
    return tamp;
}
int main()
{
    while (1<2)
    {
        char s[105];
        int t=1;
        char c='\n';
        int i=0;
        int done=0;
        while (c=='\n')
        {
            c=getchar();
            if (c==EOF)
            {
                done=1;
                break;
            }
        }
        if (done==1)
        {
            break;
        }
        s[0]=c;
        i=1;
        while (c!='\n')
        {
            c=getchar();
            s[i]=c;
            if (c=='\0')
                done=1;
            i++;
        }
        X=0;
        for (int j=0;j<i;j++)
        {
            if (s[j]>='0'&&s[j]<='9')
            {
                ma[0][X]=10*(s[j]-'0')+s[j+1]-'0';
                s[j+1]='s';
                X++;
            }
        }
        Y=X;
        t=1;
        while (t<X)
        {
            for (int j=0;j<X;j++)
            {
                scanf("%d",&ma[t][j]);
            }
            t++;
        }
        fflush(stdin);
        for (int z=0;z<(1<<17);z++)
            for (int j=0;j<X;j++)
                for (int k=0;k<Y+1;k++)
                    dp[z][j][k]=0;
        cout<<serc(0,0,0)<<endl;
        getchar();
    }
}
