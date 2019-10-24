#include <stdio.h>
int main()
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if (((c-a)/b)%2==1)printf ("Unlucky Chef\n");
else printf ("Lucky Chef\n");
}