//UVA 161 Traffic Lights
#include <stdio.h>
int lig[101];
int t=0;
int main()
{
    int co=0;
    while (1<2)
    {
        t=0;
        while (1<2)
        {
            int n;
            scanf("%d",&n);
            if (n==0)
            {
                co++;
                break;
            }
            co=0;
            lig[t++]=n;
        }
        if (co==3)break;
        if (t==0)continue;
        int yes=0;
        int valid=0;
        for (int i=0;i<=5*3600;i++)
        {
            yes=1;
            for (int j=0;j<t;j++)
            {
                if ((i%(lig[j]*2))>=(lig[j]-5))
                {
                    yes=0;
                    valid=1;
                    break;
                }
            }
            if (yes==1&&valid==1)
            {
                printf ("%02d:%02d:%02d\n",(i/3600),(i/60)%60,(i%60));
                break;
            }
        }
        if (yes==0)printf ("Signals fail to synchronise in 5 hours\n");
    }
}
