//UVA 414 Machined Surfaces
#include <stdio.h>
#include <string.h>
int main()
{
    while (1<2)
    {
        int n;
        scanf("%d",&n);
        getchar();
        if (n==0)break;
        int siz,gap=25,res=0,tamp,fir,whi=0;
        char temp[26];
        int sum[n];
        for (int i=0;i<n;i++)
        {
            scanf("%[^\n]s",temp);
            getchar();
            siz=strlen(temp);
            tamp=0;
            for (int j=0;j<siz;j++)
            {
                if (temp[j]!='X')tamp++;
            }
            sum[i]=tamp;
            if (tamp<gap)gap=tamp;
        }
        for (int i=0;i<n;i++)
        {
            sum[i]-=gap;
            res+=sum[i];
        }
        printf ("%d\n",res);
    }
}
