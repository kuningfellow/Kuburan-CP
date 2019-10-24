#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct bignum
{
    int ar[5000];
    int siz=0;
    void operator *(int a)
    {
        int rem=a;
        int ram=0;
        while (rem>0)
        {
            ram++;
            rem/=10;
        }
        int temp[5000];
        siz+=ram;
        for (int i=0;i<siz;i++)
        {
            temp[i]=0;
        }
        for (int i=0;i<siz;i++)
        {
            temp[i+1]+=ar[i]*a/10;
            ar[i]=(ar[i]*a)%10;
        }
        for (int i=0;i<siz;i++)
        {
            ar[i]+=temp[i];
            temp[i+1]+=ar[i]/10;
            ar[i]%=10;
        }
        while (ar[siz-1]==0)
        {
            siz--;
        }
    }
    void operator /(int a)
    {
        int temp[5000];
        for (int i=0;i<5000;i++)temp[i]=0;
        int rem=0;
        for (int i=siz-1;i>=0;i--)
        {
            rem*=10;
            rem+=ar[i];
            if (rem>=a)
            {
                temp[i]=rem/a;
                rem=rem%a;
            }
        }
        for (int i=0;i<siz;i++)
        {
            ar[i]=temp[i];
        }
    }
    void print()
    {
        int flag=0;
        for (int i=siz-1;i>=0;i--)
        {
            if (ar[i]==0)
            {
                if (flag==1)printf ("%d",ar[i]);
            }
            else
            {
                flag=1;
                printf ("%d",ar[i]);
            }
        }
    }
};
int main()
{
    bignum test;
    char inp[5000];
    int cou[52];
    while (scanf("%s",inp)!=EOF)
    {
        for (int i=0;i<5000;i++)
        {
            test.ar[i]=0;
        }
        for (int i=0;i<52;i++)cou[i]=0;
        for (int i=0;i<strlen(inp);i++)
        {
            if (inp[i]>='a'&&inp[i]<='z')
            {
                cou[inp[i]-'a']++;
            }
            else cou[inp[i]-'A'+26]++;
        }
        test.ar[0]=1;
        test.siz=1;
        for (int i=1;i<=strlen(inp);i++)
        {
            test*i;
        }
        for (int j=0;j<52;j++)
        {
            if (cou[j]>0)
            for (int i=1;i<=cou[j];i++)
            {
                test/i;
            }
        }
        test.print();
        printf ("\n");
    }
}
