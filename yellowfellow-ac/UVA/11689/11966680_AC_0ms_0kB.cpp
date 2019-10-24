//UVA 11689 Soda Surpler
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a=a+b;
        int bot=0;
        while (a>=c)
        {
            bot+=a/c;
            a=a/c+a%c;
        }
        printf ("%d\n",bot);
    }
}
