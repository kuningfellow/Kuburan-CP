//UVA 12019 Doom's Day Algorithm
#include <stdio.h>
#include <iostream>
using namespace std;
int mont[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const char days[7][50]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int m,d;
        cin>>m>>d;
        int dis=0;
        if (m<=4)
        {
            while (m<4)
            {
                while (d<=mont[m-1])
                {
                    dis++;
                    d++;
                }
                d=1;
                m++;
            }
            dis+=4-d;
        }
        else if (m>4&&m<=6)
        {
            while (m<6)
            {
                while (d<=mont[m-1])
                {
                    dis++;
                    d++;
                }
                d=1;
                m++;
            }
            dis+=6-d;
        }
        else if (m>6&&m<=8)
        {
            while (m<8)
            {
                while (d<=mont[m-1])
                {
                    dis++;
                    d++;
                }
                d=1;
                m++;
            }
            dis+=8-d;
        }
        else if(m>8&&m<=10)
        {
            while (m<10)
            {
                while (d<=mont[m-1])
                {
                    dis++;
                    d++;
                }
                d=1;
                m++;
            }
            dis+=10-d;
        }
        else if (m<=12)
        {
            while (m<12)
            {
                while (d<=mont[m-1])
                {
                    dis++;
                    d++;
                }
                d=1;
                m++;
            }
            dis+=12-d;
        }
        dis=-dis;
        while (dis<0)
        {
            dis+=7;
        }
        dis%=7;
        printf ("%s\n",days[dis]);
    }
}
