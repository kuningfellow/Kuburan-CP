//UVA 111 History Grading
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int cor[22];
int ar[22];
int dp[22][22];
int lim;
int serc(int x, int p)
{
    if (x==lim)return 0;
    if (dp[x][p]!=-1)return dp[x][p];
    if (p<=cor[ar[x]])
        dp[x][p]=max(dp[x][p],1+serc(x+1,cor[ar[x]]));
    return dp[x][p]=max(dp[x][p],serc(x+1,p));
}
int main()
{
    int done=0;
    cor[0]=0;
    scanf("%d",&lim);
    getchar();
    while (1<2)
    {
        char temp[500];
        if (scanf("%[^\n]s",temp)==EOF)break;
        getchar();
        int siz=0,cap=strlen(temp),cat=0,co=1;
        for (int i=0;i<cap;i++)
        {
            if (temp[i]>='0'&&temp[i]<='9')
            {
                cat*=10;
                cat+=temp[i]-'0';
            }
            else
            {
                cor[co++]=cat;
                cat=0;
            }
        }
        cor[co++]=cat;
        while (1<2)
        {
            if (scanf("%[^\n]s",temp)==EOF)
            {
                done=1;
                break;
            }
            getchar();
            cap=strlen(temp);
            cat=0;
            co=1;
            for (int i=0;i<cap;i++)
            {
                if (temp[i]>='0'&&temp[i]<='9')
                {
                    cat*=10;
                    cat+=temp[i]-'0';
                }
                else
                {
                    ar[cat-1]=co++;
                    cat=0;
                }
            }
            ar[cat-1]=co;
            if (co==1)
            {
                lim=cat;
                break;
            }
            for (int i=0;i<22;i++)
            {
                for (int j=0;j<22;j++)
                {
                    dp[i][j]=-1;
                }
            }
            printf ("%d\n",serc(0,0));
        }
        if (done==1)break;
    }
}
