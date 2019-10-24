//UVA 10055 Hazmat the Brave Warrior
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf ("%lld\n",(a>b)?(a-b):(b-a));
    }
}
