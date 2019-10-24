#include <stdio.h>
#include <string.h>
int fac(int a)
{
    if (a==0||a==1)return 1;
    return a*fac(a-1);
}
int comb(int a, int b)
{
    return fac(a)/fac(b)/fac(a-b);
}
int main()
{
    int x, n;
    scanf("%d%d",&x,&n);
    char sel[500];
    int way=0;
    int temp;
    for (int i=0;i<n;i++)
    {
        scanf("%s",sel);
        int len=strlen(sel);
        temp=0;
        int co=0;
        for (int j=0;j<9;j++)
        {
            temp=0;
            for (int k=0;k<4;k++)
            {
                if (sel[j*4+k]=='0')
                {
                    temp++;
                }
            }
            if (sel[53-co*2]=='0')
            {
                temp++;
            }
            if (sel[53-co*2-1]=='0')
            {
                temp++;
            }
            co++;
            if (temp>=x)
            {
                way+=comb(temp,x);
            }
        }
    }
    printf ("%d\n",way);
}
