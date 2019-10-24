//UVA 12992 Huatuo's Medicine
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int kas=1;
    while (tc--)
    {
        int n;
        cin>>n;
        if (n==1)
            printf ("Case #%d: %d\n",kas++,1);
        else
            printf ("Case #%d: %d\n",kas++,1+(n-1)*2);
    }
}
