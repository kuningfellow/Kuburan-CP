#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
long long int pow(int a, int b)
{
    long long int res=1;
    long long int pow=a;
    while (b>0)
    {
        if (b%2==1)
        {
            res*=pow;
        }
        pow*=pow;
        b/=2;
    }
    return res;
}
int main()
{
    char rem[500];
    char ram[500];
    while (scanf("%s %s",rem,ram)!=EOF)
    {
        long long a,b;
        int A=-1,B=-1;
        for (int i=2;i<=36;i++)
        {
            a=0;
            for (int j=0;j<strlen(rem);j++)
            {
                if (rem[j]>='A'&&rem[j]<='Z')
                {
                    if ((rem[j]-'A'+10)>=i)
                    {
                        a=-3;
                        break;
                    }
                    a+=(rem[j]-'A'+10)*pow(i,strlen(rem)-j-1);
                }
                else
                {
                    if ((rem[j]-'0')>=i)
                    {
                        a=-3;
                        break;
                    }
                    a+=(rem[j]-'0')*pow(i,strlen(rem)-j-1);
                }
            }
            for (int k=2;k<=36;k++)
            {
                b=0;
                for (int j=0;j<strlen(ram);j++)
                {
                    if (ram[j]>='A'&&ram[j]<='Z')
                    {
                        if ((ram[j]-'A'+10)>=k)
                        {
                            b=-2;
                            break;
                        }
                        b+=(ram[j]-'A'+10)*pow(k,strlen(ram)-j-1);
                    }
                    else
                    {
                        if ((ram[j]-'0')>=k)
                        {
                            b=-2;
                            break;
                        }
                        b+=(ram[j]-'0')*pow(k,strlen(ram)-j-1);
                    }
                }
                if(a==b)
                {
                    A=i;
                    B=k;
                    break;
                }
            }
            if (A!=-1)break;
        }
        if (A==-1)printf ("%s is not equal to %s in any base 2..36\n",rem,ram);
        else printf ("%s (base %d) = %s (base %d)\n",rem,A,ram,B);
    }
}
