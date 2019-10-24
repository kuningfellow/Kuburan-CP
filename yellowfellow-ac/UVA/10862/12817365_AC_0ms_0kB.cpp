//UVA 10862 Connect the Cable Wires
#include <bits/stdc++.h>
using namespace std;
int sav[4001][1005];
int main()
{
    sav[0][0]=1;
    sav[1][0]=1;
    int rem;
    for (int i=2;i<4001;i++)
    {
        rem=0;
        for (int j=0;j<1004;j++)
        {
            sav[i][j]+=sav[i-1][j]+sav[i-2][j]+rem;
            rem=sav[i][j]/10;
            sav[i][j]%=10;
        }
    }
    while (1<2)
    {
        int n,p=1003;
        cin>>n;
        if (n==0)break;
        n=n*2-1;
        while (p>0&&sav[n][p]==0)p--;
        for (int i=p;i>=0;i--)
            printf ("%d",sav[n][i]);
        printf ("\n");
    }
}
