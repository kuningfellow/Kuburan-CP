//UVA 154 Recycling
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
char mat[105][5];
int dif[105];
int main()
{
    int done=0;
    while (1<2)
    {
        char temp[500];
        int cit=0;
        while (1<2)
        {
            scanf("%s",temp);
            if (temp[0]=='e')break;
            if (temp[0]=='#')
            {
                done=1;
                break;
            }
            int siz=strlen(temp);
            for (int i=0;i<siz;i++)
            {
                if (temp[i]=='r')
                {
                    mat[cit][0]=temp[i+2];
                }
                else if (temp[i]=='o')
                {
                    mat[cit][1]=temp[i+2];
                }
                else if (temp[i]=='y')
                {
                    mat[cit][2]=temp[i+2];
                }
                else if (temp[i]=='g')
                {
                    mat[cit][3]=temp[i+2];
                }
                else if (temp[i]=='b')
                {
                    mat[cit][4]=temp[i+2];
                }
            }
            cit++;
        }
        for (int i=0;i<cit;i++)dif[i]=0;
        if (done==1)break;
        int mini=(1<<30)-1;
        int win;
        for (int i=0;i<cit;i++)
        {
            for (int j=0;j<cit;j++)
            {
                if (j==i)continue;
                for (int k=0;k<5;k++)
                {
                    if (mat[i][k]!=mat[j][k])
                    {
                        dif[i]++;
                    }
                }
            }
            if (dif[i]<mini)
            {
                mini=dif[i];
                win=i;
            }
        }
        printf ("%d\n",win+1);
    }
}
