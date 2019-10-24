//UVA 11110 Equidivisions
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ar[105][105];
int n;
int serc(int x, int y, int m)
{
    if (x<0||y<0||x>=n||y>=n)return 0;
    if (ar[x][y]!=m)return 0;
    ar[x][y]=-1;
    return 1+serc(x+1,y,m)+serc(x,y+1,m)+serc(x,y-1,m)+serc(x-1,y,m);
}
int main()
{
    while (1<2)
    {
        int a,b;
        cin>>n;
        getchar();
        if (n==0)break;
        int bad=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                ar[i][j]=0;
            }
        }
        int len;
        char s[10000];
        for (int i=0;i<n-1;i++)
        {
            scanf("%[^\n]s",s);
            getchar();
            len=strlen(s);
            s[len]=' ';
            s[len+1]='\0';
            len=strlen(s);
            int two=0;
            a=0;
            b=0;
            int kepa,kepb;
            int mid=0;
            for (int j=0;j<len;j++)
            {
                if (s[j]>='0'&&s[j]<='9')
                {
                    mid=1;
                    b*=10;
                    b+=s[j]-'0';
                }
                else if (mid==1)
                {
                    mid=0;
                    two++;
                    if (two==2)
                    {
                        two=0;
                        ar[a-1][b-1]=i+1;
                        kepa=a-1;
                        kepb=b-1;
                    }
                    a=b;
                    b=0;
                }
            }
            int res=serc(kepa,kepb,i+1);
            if (res!=n)bad=1;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (ar[i][j]==0)
                {
                    int res=serc(i,j,0);
                    if (res!=n)
                    {
                        bad=1;
                        break;
                    }
                }
            }
            if (bad==1)break;
        }
        if (bad==1)printf ("wrong\n");
        else printf ("good\n");
    }
}
