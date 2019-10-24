//UVA 10260 Soundex
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
int main()
{
    map<char,int>ar;
    ar['B']=1;
    ar['F']=1;
    ar['P']=1;
    ar['V']=1;
    ar['C']=2;
    ar['G']=2;
    ar['J']=2;
    ar['K']=2;
    ar['Q']=2;
    ar['S']=2;
    ar['X']=2;
    ar['Z']=2;
    ar['D']=3;
    ar['T']=3;
    ar['L']=4;
    ar['M']=5;
    ar['N']=5;
    ar['R']=6;
    char in[5000];
    while (scanf("%s",in)!=EOF)
    {
        int len=strlen(in),sum=0,p=0;
        for (int i=0;i<len;i++)
        {
            if (p!=ar[in[i]]&&ar[in[i]]!=0)
                printf ("%d",ar[in[i]]);
            p=ar[in[i]];
        }
        printf ("\n");
    }
}
