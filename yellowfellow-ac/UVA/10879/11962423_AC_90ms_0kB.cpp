//UVA 10879 Code Refactoring
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc,kas=1;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        printf ("Case #%d: %d = ",kas++,n);
        int mod=0;
        int use[2];
        for (int i=2;i<n;i++)
        {
            if (n%i==0&&use[0]!=i&&use[0]!=n/i&&use[1]!=i&&use[1]!=n/i&&i<10000000&&n/i<10000000)
            {
                printf ("%d * %d",i,n/i);
                use[0]=i;
                use[1]=n/i;
                if (mod==0)printf (" = ");
                if (mod==1)break;
                mod=1;
            }
        }
        printf ("\n");
    }
}
