#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dif(int a, int b)
{
    if (a>b)return a-b;
    else return b-a;
}

int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            printf ("%c",i%26+'a');
        }
        printf ("\n");
    }
}
