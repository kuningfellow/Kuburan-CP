//UVA 11723 Numbering Roads
#include <stdio.h>
int main()
{
    int r,n,let;
    int kase=0;
    while (1<2)
    {
        scanf("%d%d",&r,&n);
        if (r==0&&n==0)break;
        printf ("Case %d: ",++kase);
        let=r/n+(r%n>0);
        let--;
        if (let>26)printf ("impossible\n");
        else printf ("%d\n",let);
    }
}
