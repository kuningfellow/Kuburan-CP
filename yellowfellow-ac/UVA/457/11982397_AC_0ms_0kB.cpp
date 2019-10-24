//UVA 457 Linear Cellular Automata
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int dna[10];
        for (int i=0;i<10;i++)
        {
            cin>>dna[i];
        }
        int cell[40];
        for (int i=0;i<40;i++)
        {
            cell[i]=0;
        }
        cell[19]=1;
        for (int i=0;i<40;i++)
        {
            if (cell[i]==0)printf (" ");
            else if (cell[i]==1)printf (".");
            else if (cell[i]==2)printf ("x");
            else if (cell[i]==3)printf ("W");
        }
        printf ("\n");
        int tempcel[40];
        int kay=49;
        int k;
        while (kay--)
        {
            for (int i=0;i<40;i++)
            {
                k=cell[i];
                if (i-1>=0)k+=cell[i-1];
                if (i+1<40)k+=cell[i+1];
                tempcel[i]=dna[k];
            }
            for (int i=0;i<40;i++)
            {
                cell[i]=tempcel[i];
                if (tempcel[i]==0)printf (" ");
                else if (tempcel[i]==1)printf (".");
                else if (tempcel[i]==2)printf ("x");
                else if (tempcel[i]==3)printf ("W");
            }
            printf ("\n");
        }
        if (tc>0)printf ("\n");
    }
}
