//UVA 11875 Brick Game
#include <stdio.h>
int main()
{
    int t,kase=0;
    scanf("%d",&t);
    int n;
    while (kase++<t)
    {
        scanf("%d",&n);
        int a[n];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int j=0;j<n;j++)
        {
            for (int i=0;i<n-1;i++)
            {
                if (a[i]>a[i+1])
                {
                    a[i]+=a[i+1];
                    a[i+1]=a[i]-a[i+1];
                    a[i]-=a[i+1];
                }
            }
        }
        printf ("Case %d: %d\n",kase,a[n/2]);
    }
}
