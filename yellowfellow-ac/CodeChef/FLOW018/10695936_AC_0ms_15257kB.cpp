#include<stdio.h>
int main()
{
    int i;
    int t;
    scanf("%d",&t);
    int w;
    int j=0;
    while (j<t)
    {
        i=0;
        w=1;
        scanf("%d",&i);
        //getchar();
        while (i>0)
        {
            w*=i;
            i--;
        }
        printf ("%i\n",w);
        j++;
    }
}
