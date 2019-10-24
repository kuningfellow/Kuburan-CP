//UVA 10062 Tell me the frequencies!
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int ar[256];
    char temp[1005];
    int kas=0;
    temp[0]='\0';
    while (scanf("%[^\r\n]s",temp)!=EOF)
    {
        getchar();
        for (int i=0;i<256;i++)
        {
            ar[i]=0;
        }
        for (int i=0;i<strlen(temp);i++)
        {
            ar[(int)temp[i]]++;
        }
        int perm[256];
        for (int i=0;i<256;i++)
        {
            perm[i]=i;
        }
        for (int i=0;i<256;i++)
        {
            for (int j=0;j<255;j++)
            {
                if (ar[perm[j]]>ar[perm[j+1]]||(ar[perm[j]]==ar[perm[j+1]]&&perm[j]<perm[j+1]))
                {
                    int temp=perm[j];
                    perm[j]=perm[j+1];
                    perm[j+1]=temp;
                }
            }
        }
        if (kas>0)printf ("\n");
        for (int i=0;i<256;i++)
        {
            if (ar[perm[i]]>0)
            {
                printf ("%d %d\n",perm[i],ar[perm[i]]);
            }
        }
        kas=1;
        temp[0]='\0';
    }
}
