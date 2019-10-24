#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        char ch[n];
        int pri[n];
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%c%d",&ch[i],&pri[i]);
            getchar();
        }
        char c;
        int temp;
        for (i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if (ch[j]>ch[j+1])
                {
                    c=ch[j];
                    ch[j]=ch[j+1];
                    ch[j+1]=c;
                    temp=pri[j];
                    pri[j]=pri[j+1];
                    pri[j+1]=temp;
                }
            }
        }
        c='0';
        int x;
        scanf("%d",&x);
        getchar();
        int monet=0;
        while (x)
        {
            c='0';
            while (c!='\n')
            {
                c=getchar();
                for (i=0;i<n;i++)
                {
                    if (ch[i]==c)
                    {
                        monet+=pri[i];
                        break;
                    }
                    if (ch[i]>c)break;
                }
            }
            x--;
        }
        double price=(double)monet/100;
        printf ("%.2f$\n",price);
    }
    return 0;
}
