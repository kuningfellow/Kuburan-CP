#include <stdio.h>
int main()
{
    while (1<2)
    {
        char a[27],b[27];
        int end=0;
        int i=0,j;
        char c='0';
        while (c!='\n')
        {
            c=getchar();
            if (c==EOF)
            {
                end=1;
                break;
            }
            a[i]=c;
            i++;
        }
        int l=i-1;
        c='0';
        i=0;
        while (c!='\n')
        {
            c=getchar();
            if (c==EOF)
            {
                end=1;
                break;
            }
            b[i]=c;
            i++;
        }
        int L=i-1;
        if (end==1)break;
        int A=0,B=0;
        for (i=0;i<l;i++)
        {
            if (a[i]>='A'&&a[i]<='Z')
                A+=a[i]-'A'+1;
            else if (a[i]>='a'&&a[i]<='z')
                A+=a[i]-'a'+1;
        }
        for (i=0;i<L;i++)
        {
            if (b[i]>='A'&&b[i]<='Z')
                B+=b[i]-'A'+1;
            else if (b[i]>='a'&&b[i]<='z')
                B+=b[i]-'a'+1;
        }
        int temp=A;
        while (temp>=10)
        {
            A=temp;
            temp=0;
            while (A>0)
            {
                temp+=A%10;
                A/=10;
            }
        }
        A=temp;
        temp=B;
        while (temp>=10)
        {
            B=temp;
            temp=0;
            while (B>0)
            {
                temp+=B%10;
                B/=10;
            }
        }
        B=temp;
        L=A>B?A:B;
        l=A<B?A:B;
        double rat=(double)l/L;
        rat*=100;
        printf ("%.2f %%\n",rat);
    }
    return 0;
}
