#include <stdio.h>
int main()
{
    int factorial(int n)
    {
        if (n==0)
        {
            return 0;
        }
        return n+factorial(n-1);
    }
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        int n;
        int a;
        scanf ("%d",&n);
        a=factorial (n-1);
        printf ("%i\n",a);
    }
}
