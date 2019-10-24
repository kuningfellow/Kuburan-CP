//UVA 11313 Gourmet Games
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n,m;
        cin>>n>>m;
        if (n<m)
        {
            printf ("cannot do this\n");
            continue;
        }
        int sho=0;
        while (n>=m)
        {
            sho+=n/m;
            n=n/m+n%m;
        }
        if (n!=1)printf ("cannot do this\n");
        else printf ("%d\n",sho);
    }
}
