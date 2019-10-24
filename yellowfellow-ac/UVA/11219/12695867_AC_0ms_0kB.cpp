#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int kas=1;
    int tc;
    cin>>tc;
    while (tc--)
    {
        int d1,m1,y1,d2,m2,y2;
        scanf("%d/%d/%d",&d2,&m2,&y2);
        scanf("%d/%d/%d",&d1,&m1,&y1);
        printf ("Case #%d: ",kas++);
        int delta=y2-y1-1+(m2>m1)+((m2==m1)*(d2>=d1));
        if (delta<0)
            printf ("Invalid birth date\n");
        else if (delta>130)
            printf ("Check birth date\n");
        else printf ("%d\n",delta);
    }
}