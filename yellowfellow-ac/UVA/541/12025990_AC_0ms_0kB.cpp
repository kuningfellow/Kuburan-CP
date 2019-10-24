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
        int sumx[n];
        int sumy[n];
        int corx=0;
        int cory=0;
        for (int i=0;i<n;i++)
        {
            sumx[i]=0;
            sumy[i]=0;
            for (int j=0;j<n;j++)
            {
                sumx[i]+=ar[i][j];
                sumy[i]+=ar[j][i];
            }
            if (sumx[i]%2==1)corx++;
            if (sumy[i]%2==1)cory++;
        }
        if (corx==0&&cory==0)printf ("OK\n");
        else if (corx>1||cory>1)printf ("Corrupt\n");
        else
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if (sumx[i]%2==1&&sumy[j]%2==1)
                    {
                        printf ("Change bit (%d,%d)\n",i+1,j+1);
                    }
                }
            }
        }
    }
}
