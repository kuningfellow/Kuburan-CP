//UVA 10013 Super long sums
#include <stdio.h>
int main()
{
    int tc;
    int ini=1;
    scanf("%d",&tc);
    while (tc--)
    {
        int n;
        scanf("%d",&n);
        int ar[n+1];
        for (int i=0;i<n+1;i++)ar[i]=0;
        int lr[n],rr[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&lr[i],&rr[i]);
        }
        for (int i=n-1;i>=0;i--)
        {
            ar[i+1]+=(lr[i]+rr[i]);
            ar[i]=ar[i+1]/10;
            ar[i+1]%=10;
        }
        int lead=0;
        if (tc>=0&&ini!=1)printf ("\n");
        for (int i=0;i<n+1;i++)
        {
            if (ar[i]!=0||lead==1)
            {
                lead=1;
                printf ("%d",ar[i]);
            }
        }
        ini=0;
        printf ("\n");
    }
}
