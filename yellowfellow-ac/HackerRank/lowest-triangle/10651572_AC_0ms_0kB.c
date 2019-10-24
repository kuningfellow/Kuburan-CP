#include <stdio.h>
int main()
{
    int a,b,h;
    scanf("%d %d",&b,&a);
    h=a*2/b;
    if (a-(b*h/2)>0)
    {
        h++;
    }
    printf ("%i",h);
}
