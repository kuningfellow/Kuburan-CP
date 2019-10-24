#include <stdio.h>
void operate(char s[],int n)
{
    if (s[0]=='+')
    {
        if (s[n-1]=='-')s[n-1]='+';
        else if (s[n-1]=='+')s[n-1]='-';
    }
    char temp=s[0];
    if (temp=='+')temp='-';
    else if (temp=='-')temp='+';
    int i;
    for (i=0;i<n-1;i++)
    {
        s[i]=s[i+1];
    }
    s[n-1]=temp;
}
int main()
{
    int t,kase=1;
    scanf("%d",&t);
    while (t>0)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        char sam[16];
        scanf("%s",sam);
        int i,j,s,l;
        char tempo[16];
        int q;
        printf ("Experiment #%i:\n",kase);
        kase++;
        for (i=0;i<k;i++)
        {
            int mul;
            int yes=0;
            for (j=0;j<n;j++)
            {
                tempo[j]=sam[j];
            }
            scanf("%d",&q);
            for (s=0;s<q;s++)
            {
                operate(tempo,n);
                yes=0;
                for (l=0;l<n;l++)
                {
                    if (tempo[l]==sam[l])
                        yes++;
                    else break;
                }
                if (yes==n)
                {
                    for (j=0;j<n;j++)
                    {
                        tempo[j]=sam[j];
                    }
                    mul=s+1;
                    break;
                }
            }
            if (yes==n)
                for (s=0;s<(q%mul);s++)
                {
                    operate(tempo,n);
                }
            for (j=0;j<n;j++)
            {
                printf ("%c",tempo[j]);
            }
            printf ("\n");
        }
        t--;
    }
    return 0;
}
