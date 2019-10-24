#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        t--;
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int ar[n];
        int i,j,min=-1,max=-1;
        for (i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if (ar[i]<=r&&ar[i]>=l)
            {
                if (min<0)min=i;
                if (max<0)max=i;
                if (ar[min]>ar[i])min=i;
                if (ar[max]<ar[i])max=i;
            }
        }
        if (r==l)
        {
            printf ("-1\n");
            continue;
        }
        else if (max>=0&&ar[max]>l)
        {
            ar[max]=l;
        }
        else if (max>=0&&ar[max]==l)
        {
            ar[max]=l+1;
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n-1;j++)
            {
                if (ar[j]>ar[j+1])
                {
                    int temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
        }
        for (i=0;i<n;i++)
        {
            printf ("%i ",ar[i]);
        }
        printf ("\n");
    }
    return 0;
}
