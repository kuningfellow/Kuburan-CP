#include <stdio.h>
int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        int cig=0,but=0;
        cig+=n;
        but=n;
        while (but>=k)
        {
            but-=k;
            but++;
            cig++;
        }
        printf ("%d\n",cig);
    }
    return 0;
}
