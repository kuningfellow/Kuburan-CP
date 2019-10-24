#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        int n;
        scanf("%d",&n);
        n=180-n;
        if ((180-n)>=60&&360%n==0)
        {
            printf ("YES\n");
        }
        else printf ("NO\n");
        t--;
    }
    return 0;
}
