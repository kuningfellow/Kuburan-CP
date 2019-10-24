#include <stdio.h>
int fastex(int a, int b)
{
    int res=1;
    while (b>0)
    {
        if (b%2==1)
        {
            res*=a;
            res%=10;
        }
        a*=a;
        a%=100;
        b/=2;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf ("%i\n",fastex(a,b));
        t--;
    }
    return 0;
}
