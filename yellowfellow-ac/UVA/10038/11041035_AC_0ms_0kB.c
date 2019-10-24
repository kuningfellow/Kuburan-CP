#include <stdio.h>
int abs(int a, int b)
{
    if (a>b)
    {
        return a-b;
    }
    return b-a;
}
int main()
{
    while (1<2)
    {
        int n;
        if (scanf("%d",&n)==EOF)break;
        int a[n],b[n];
        int i;
        int x;
        for (i=0;i<n;i++)
        {
            b[i]=0;
            scanf("%d",&a[i]);
        }
        if (i==1)
        {
            printf ("Jolly\n");
            continue;
        }
        for (i=0;i<n-1;i++)
        {
            b[abs(a[i],a[i+1])]=1;
        }
        for (i=1;i<n;i++)
        {
            if (b[i]!=1)
            {
                printf ("Not jolly\n");
                break;
            }
            if (i==n-1)
            {
                printf ("Jolly\n");
                break;
            }
        }
    }
    return 0;
}
