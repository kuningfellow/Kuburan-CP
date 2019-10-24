#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int fir=0;
    char rem[500000];
    while (1<2)
    {
        int n,a;
        cin>>n;
        if (n==0)break;
        int ar[n];
        for (int i=0;i<n;i++)
        {
            cin>>a;
            ar[a-1]=i;
        }
        getchar();
        rem[0]='\0';
        scanf("%[^\n]",rem);
        getchar();
        int l=strlen(rem);
        while (l%n!=0)
        {
            rem[l]=' ';
            rem[l+1]='\0';
            l++;
        }
        char ram[500000];
        for (int i=0;i<l;i++)
        {
            ram[i/n*n+ar[i%n]]=rem[i];
        }
        printf ("'");
        for (int i=0;i<l;i++)
        {
            printf ("%c",ram[i]);
        }
        printf ("'");
        printf ("\n");
    }
}
