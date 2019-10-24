//UVA 482 Permutation Arrays
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    getchar();
    while (tc--)
    {
        char temp[100000];
        vector<int>ar;
        temp[0]='\0';
        while (strlen(temp)==0)
        {
            scanf("%[^\n]s",temp);
            getchar();
        }
        ar.push_back(0);
        int j=0,siz=strlen(temp);
        for (int i=0;i<siz;i++)
        {
            if (temp[i]>='0'&&temp[i]<='9')
            {
                ar[j]*=10;
                ar[j]+=temp[i]-'0';
            }
            else
            {
                j++;
                ar.push_back(0);
            }
        }
        j++;
        char br[j][500];
        for (int i=0;i<j;i++) scanf("%s",&br[ar[i]-1]);
        for (int i=0;i<j;i++) printf ("%s\n",br[i]);
        if (tc>0)printf ("\n");
    }
}
