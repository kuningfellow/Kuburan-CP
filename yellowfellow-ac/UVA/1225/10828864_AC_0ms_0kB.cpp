#include <stdio.h>
int main()
{
    int A[10]={0,0,0,0,0,0,0,0,0,0};
    char c='a';
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int i,j;
        scanf("%d",&i);
        for (j=1;j<=i;j++)
        {
            int a=j;
            while (a>0)
            {
                A[a%10]++;
                a/=10;
            }
        }
        for (i=0;i<10;i++)
        {
            printf ("%i",A[i]);
            if (i<9)
            {
                printf (" ");
            }
            A[i]=0;
        }
//        if (t>1)
        {
            printf ("\n");
        }
        t--;
    }
    return 0;
}
