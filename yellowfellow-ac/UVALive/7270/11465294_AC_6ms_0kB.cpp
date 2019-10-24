#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main ()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        char s[100000];
        int j=0;
        char c='0';
        int combo=0;
        for (int i=0;i<n;i++)
        {
        	getchar();
            scanf("%c",&c);
            if (c=='S')combo++;
            else
            {
                scanf("%d",&j);
                if (j==1)
                {
                    combo++;
                }
            }
        }
        printf ("%d\n",combo);
    }
}
