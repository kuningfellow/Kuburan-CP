#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
long long int pow(int b, int p)
{
    long long int res=1;
    while (p>0)
    {
        if (p%2==1)
        {
            res*=b;
        }
        b*=b;
        p/=2;
    }
    return res;
}
vector<int>lis;
bool isprime[50000];
void sieve()
{
    for (int i=2;i<50000;i++)
    {
        if (isprime[i]==0)
        {
            lis.push_back(i);
            for (int j=i*2;j<50000;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
}
vector<int>deg;
vector<int>coun;
int main()
{
    sieve();
    char rem[5000];
    while (1<2)
    {
        scanf("%[^\n]",rem);
        getchar();
        if (strlen(rem)==1&&rem[0]=='0')break;
        long long int ram=1;
        int flag=0;
        int a=0;
        int b=0;
        int l=strlen(rem);
        for (int i=0;i<l;i++)
        {
            if (rem[i]>='0'&&rem[i]<='9')
            {
                a*=10;
                a+=rem[i]-'0';
            }
            else
            {
                if (flag==0)
                    b=a;
                else if (flag==1)
                    ram*=pow(b,a);
                flag^=1;
                a=0;
            }
        }
        if (a>0)
        {
            ram*=pow(b,a);
        }
        l=lis.size();
        ram--;
        for (int i=0;i<l;i++)
        {
            a=0;
            while (ram%lis[i]==0)
            {
                a++;
                ram/=lis[i];
            }
            if (a>0)
            {
                deg.push_back(lis[i]);
                coun.push_back(a);
            }
            if (ram==1)break;
        }
        if (ram>1)
        {
            deg.push_back(ram);
            coun.push_back(1);
        }
        for (int i=deg.size()-1;i>=0;i--)
        {
            printf ("%d %d",deg[i],coun[i]);
            if (i>0)printf (" ");
        }
        printf ("\n");
        deg.clear();
        coun.clear();
    }
}
