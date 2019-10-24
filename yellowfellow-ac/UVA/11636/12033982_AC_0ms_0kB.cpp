//UVA 11636 Hello World
#include <stdio.h>
int main()
{
    int n,kas=1;
    while (1<2)
    {
        scanf("%d",&n);
        if (n<0)break;
        int no=1,k=0;
        while (no<n)
        {
            k++;
            no*=2;
        }
        printf ("Case %d: %d\n",kas++,k);
    }
}
