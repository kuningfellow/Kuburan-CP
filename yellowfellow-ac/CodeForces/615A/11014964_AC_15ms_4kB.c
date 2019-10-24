#include <stdio.h>
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int i;
    int a[s];
    for (i=0;i<n;i++)
    {
        int w,q,j;
        scanf("%d",&q);
        for (j=0;j<q;j++)
        {
            scanf("%d",&w);
            a[w-1]=1;
        }
    }
    int su=0;
    for (i=0;i<s;i++)
    {
        su+=a[i];
    }
    if (su==s)printf ("YES\n");
    else printf ("NO\n");
    return 0;
}
