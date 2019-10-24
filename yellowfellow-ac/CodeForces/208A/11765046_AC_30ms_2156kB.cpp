#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    char c[500];
    scanf("%s",c);
    int init=1;
    int first=0;
    for (int i=0;i<strlen(c);i++)
    {
        if (c[i]=='W'&&c[i+1]=='U'&&c[i+2]=='B')
        {
            init=1;
            i+=2;
        }
        else
        {
            if (init==1&&first!=0)printf (" ");
            init=0;
            first=1;
            printf ("%c",c[i]);
        }
    }
}
