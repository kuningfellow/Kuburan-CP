#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int pow(int i)
{
    if (i==0)return 1;
    return 2*pow(i-1);
}
vector<int>dp[21];
vector<int>tre;
int i=524288;
int main()
{
    for (int k=0;k<pow(21);k++)
    {
        tre.push_back(0);
    }
    int siz=pow(20);
    int pos=1;
    int j=0;
    int lev=1;
    while (j<i)
    {
        if (pos>=siz)
        {
            j++;
            lev=1;
            pos=1;
        }
        else if (tre[pos]==0)
        {
            dp[lev].push_back(pos);
            tre[pos]=1;
            pos*=2;
            lev++;
        }
        else if (tre[pos]==1)
        {
            dp[lev].push_back(pos);
            tre[pos]=0;
            pos*=2;
            pos++;
            lev++;
        }
    }
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf ("%d\n",dp[a][b-1]);
    }
    scanf("%d",&n);
}
