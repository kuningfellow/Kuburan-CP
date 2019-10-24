#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    char c[500];
    scanf("%s",c);
    char a=c[0];
    for (int i=0;i<strlen(c);i++)
    {
        if (c[i]>a)a=c[i];
    }
    for (int i=0;i<strlen(c);i++)
    {
        if (c[i]==a)printf ("%c",a);
    }
}
