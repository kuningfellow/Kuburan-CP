//UVA 541 Error Correction
#include <stdio.h>
int main()
{
    while (1<2)
    {
        int n;
        scanf("%d",&n);
        if (n==0)break;
        int ar[n][n];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)scanf("%d",&ar[i][j]);
        int sumx;
        int sumy;
        int bad=0;
        int corx=-1;
        int cory=-1;
        for (int i=0;i<n;i++)
        {
            sumx=0;
            sumy=0;
            for (int j=0;j<n;j++)
            {
                sumx+=ar[i][j];
                sumy+=ar[j][i];
            }
            if (sumx%2==1)
            {
                if (corx!=-1)
                    bad=1;
                corx=i;
            }
            if (sumy%2==1)
            {
                if (cory!=-1)
                    bad=1;
                cory=i;
            }
        }
        if (corx==-1&&cory==-1&&bad==0)printf ("OK\n");
        else if (bad==1)printf ("Corrupt\n");
        else printf ("Change bit (%d,%d)\n",corx+1,cory+1);
    }
}
