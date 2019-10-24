#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while (t>0)
    {
        int n;
        scanf("%d",&n);
        getchar();
        int a[n];
        int  i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            getchar();
        }
        int b=0;
        int j;
        for (j=1;j<n;j++)
        {
            for (i=0;i<j;i++)
            {
                if (a[i]<=a[j]) b++;
            }
        }
        printf ("%i\n",b);
        t--;
    }
    return 0;
}
