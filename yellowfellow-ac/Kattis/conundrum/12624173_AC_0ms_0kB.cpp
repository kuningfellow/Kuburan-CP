#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    char rem[500];
    scanf("%s",rem);
    int co=0;
    for (int i=0;i<strlen(rem);i++)
    {
        if (i%3==0&&rem[i]!='p'&&rem[i]!='P')co++;
        if (i%3==1&&rem[i]!='e'&&rem[i]!='E')co++;
        if (i%3==2&&rem[i]!='r'&&rem[i]!='R')co++;
    }
    printf ("%d\n",co);
}
