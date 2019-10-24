#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int i;
    int c[a];
    for(i=0;i<a;i++)
    {
        scanf("%d",&c[i]);
    }
    int j,z=b;
    for (i=0;i<=b;i++)
    {
        for(j=0;j<a;j++)
        {
            if(c[j]==b)
            {
                z++;
                c[j]=0;
            }
            else if(c[j]==i)
            {
                z--;
            }
        }
    }
    printf ("%i",z);
    return 0;
}
