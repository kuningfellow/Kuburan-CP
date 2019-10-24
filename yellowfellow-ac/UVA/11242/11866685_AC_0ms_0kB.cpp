//UVA 11242 Tour de France
#include <stdio.h>
int main()
{
    while (1<2)
    {
        int f,r;
        scanf("%d",&f);
        if (f==0)break;
        scanf("%d",&r);
        int i,j;
        int siz=f*r;
        int ar[f];
        int ir[r];
        double rat[siz+1];
        int in=0;
        for (i=0;i<f;i++)
        {
            scanf("%d",&ar[i]);
        }
        for (i=0;i<r;i++)
        {
            scanf("%d",&ir[i]);
        }
        for (i=0;i<f;i++)
        {
            for (j=0;j<r;j++)
            {
                rat[in++]=(double)ir[j]/ar[i];
            }
        }
        double temp;
        for (i=0;i<siz;i++)
        {
            for (j=0;j<siz-1;j++)
            {
                if (rat[j]<rat[j+1])
                {
                    temp=rat[j];
                    rat[j]=rat[j+1];
                    rat[j+1]=temp;
                }
            }
        }
        temp=rat[0]/rat[1];
        for (i=1;i<siz-1;i++)
        {
            if (temp<(rat[i]/rat[i+1]))
            {
                temp=(rat[i]/rat[i+1]);
            }
        }
        printf ("%.2f\n",temp);
    }
}
