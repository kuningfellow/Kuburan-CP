#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int side,i,j,max,sum;
    for (j=0;j<t;j++)
    {
        sum=0;
        max=0;
        for (i=0;i<3;i++)
        {
            scanf("%d",&side);
            if (side>max)
            {
                max=side;
            }
            sum+=side;
        }
        if (sum-max>max)
        {
            printf ("OK\n");
        }
        else printf ("Wrong!!\n");
    }
    return 0;
}
