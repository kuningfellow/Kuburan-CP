//UVA 108 Maximum Sum
#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ar[n][n];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&ar[i][j]);
            }
        }
        int temp[n];
        for (int i=0;i<n;i++)
        {
            temp[i]=0;
        }
        int sum;
        int maxum=-(1<<31);
        for (int i=0;i<n;i++)
        {
            for (int j=n;j>i;j--)
            {
                temp[0]=0;
                for (int k=i;k<j;k++)
                {
                    temp[0]+=ar[0][k];
                }
                sum=temp[0];
                int take=1;
                int tempmax=sum;
                for (int r=1;r<n;r++)
                {
                    temp[r]=0;
                    for (int k=i;k<j;k++)
                    {
                        temp[r]+=ar[r][k];
                    }
                    int take=1;
                    if (sum+temp[r]<temp[r])
                    {
                        sum=temp[r];
                    }
                    else
                    {
                        sum+=temp[r];
                    }
                    if (tempmax<sum)tempmax=sum;
                }
                if (tempmax>maxum)
                {
                    maxum=tempmax;
                }
            }
        }
        printf ("%d\n",maxum);
    }
}
