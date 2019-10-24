#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int h=0;
    while (a-b>=0)
    {
        h+=b;
        a=a-b+1;
    }
    h+=a;
    printf ("%i",h);
}
