#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int tc;
    int kas=1;
    cin>>tc;
    getchar();
    getchar();
    while (tc--)
    {
        char rem[5000];
        int l;
        if (kas!=1)printf ("\n");
        printf ("Case #%d:\n",kas++);
        while (1<2)
        {
            rem[0]='\0';
            scanf("%[^\n]",rem);
            getchar();
            if (strlen(rem)==0)break;
            l=strlen(rem);
            int flag=0;
            int j=0;
            int co=0;
            for (int i=0;i<l;i++)
            {
                if ((rem[i]>='a'&&rem[i]<='z')||(rem[i]>='A'&&rem[i]<='Z'))
                {
                    if (co==j)
                    {
                        flag=1;
                        printf ("%c",rem[i]);
                    }
                    co++;
                }
                else
                {
                    if (flag==1)
                    {
                        j++;
                        flag=0;
                    }
                    co=0;
                }
            }
            printf ("\n");
        }
    }
}
