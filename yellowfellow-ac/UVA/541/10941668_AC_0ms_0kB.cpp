#include <stdio.h>
int main()
{
    int t;
    while (scanf("%d",&t)!=EOF)
    {
        if (t==0)break;
        int a[t][t];
        int c[t];
        int i,j;
        int r[t];
        int C[t];
        int R[t];
        for (i=0;i<t;i++)
        {
            c[i]=0;
            C[i]=0;
            r[i]=0;
            R[i]=0;
        }
        for (i=0;i<t;i++)
        {
            for (j=0;j<t;j++)
            {
                scanf("%d",&a[i][j]);
                r[i]+=a[i][j];
            }
        }
        for (i=0;i<t;i++)
        {
            for (j=0;j<t;j++)
            {
                c[i]+=a[j][i];
            }
        }
        int x,y;
        int rcount=0,ccount=0;
        for (i=0;i<t;i++)
        {
            if (r[i]%2!=0)
            {
                R[i]++;
                rcount++;
                x=i;
            }
            if (c[i]%2!=0)
            {
                C[i]++;
                ccount++;
                y=i;
            }
        }
        if (rcount==0&&ccount==0)
        {
            printf ("OK\n");
        }
        else if (rcount==1&&ccount==1)
        {
            printf ("Change bit (%d,%d)\n",x+1,y+1);
        }
        else printf ("Corrupt\n");
    }
    return 0;
}
