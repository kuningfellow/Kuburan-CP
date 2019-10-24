//UVA 836 Largest Submatrix
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int tc,fir=0;
    cin>>tc;
    while (tc--)
    {
        char rem[500];
        scanf("%s",rem);
        int l=strlen(rem);
        int ar[l+1][l+1];
        for (int i=0;i<l+1;i++)
        {
            ar[i][0]=0;
            ar[0][i]=0;
        }
        int sum=0;
        for (int i=0;i<l;i++)
        {
            sum+=rem[i]-'0';
            ar[1][i+1]=sum;
        }
        for (int i=1;i<l;i++)
        {
            scanf("%s",rem);
            sum=0;
            for (int j=0;j<l;j++)
            {
                sum+=rem[j]-'0';
                ar[i+1][j+1]=sum;
            }
        }
        int x,y;
        sum=0;
        for (int i=0;i<l;i++)
        {
            for (int j=0;j<l;j++)
            {
                y=1;
                if (ar[i+1][j+y]==ar[i+1][j])continue;
                while (j+y<l+1)
                {
                    x=0;
                    while(i+x<l+1&&ar[i+x+1][j+y]-ar[i+x+1][j]==y)
                        x++;
                    if (x*y>sum)
                        sum=x*y;
                    y++;
                }
            }
        }
        if (fir==1)printf ("\n");
        fir=1;
        printf ("%d\n",sum);
    }
}
