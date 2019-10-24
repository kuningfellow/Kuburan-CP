#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char rem[10];
    while (1<2)
    {
        scanf("%s",rem);
        if (rem[0]=='e')break;
        char top[10][50]={"+---+","    +","+---+","+---+","+   +","+---+","+---+","+---+","+---+","+---+"};
        char up[10][50]={"|   |","    |","    |","    |","|   |","|    ","|    ","    |","|   |","|   |"};
        char mid[10][50]={"+   +","    +","+---+","+---+","+---+","+---+","+---+","    +","+---+","+---+"};
        char down[10][50]={"|   |","    |","|    ","    |","    |","    |","|   |","    |","|   |","    |"};
        char low[10][50]={"+---+","    +","+---+","+---+","    +","+---+","+---+","    +","+---+","+---+"};
        int z=0;
        for (int i=0;i<4;i++)
        {
            printf ("%s",top[rem[z++]-'0']);
            if (z==2)z++;
            if (i==1)printf ("     ");
            else if (i<3)printf ("  ");
        }
        printf ("\n");
        for (int i=0;i<2;i++)
        {
            z=0;
            for (int j=0;j<4;j++)
            {
                printf ("%s",up[rem[z++]-'0']);
                if (z==2)z++;
                if (j==1&&i==0)printf ("     ");
                else if (j==1&&i==1)printf ("  o  ");
                else if (j<3)printf ("  ");
            }
            printf ("\n");
        }
        z=0;
        for (int i=0;i<4;i++)
        {
            printf ("%s",mid[rem[z++]-'0']);
            if (z==2)z++;
            if (i==1)printf ("     ");
            else if (i<3)printf ("  ");
        }
        printf ("\n");
        for (int i=0;i<2;i++)
        {
            z=0;
            for (int j=0;j<4;j++)
            {
                printf ("%s",down[rem[z++]-'0']);
                if (z==2)z++;
                if (j==1&&i==1)printf ("     ");
                else if (j==1&&i==0)printf ("  o  ");
                else if (j<3)printf ("  ");
            }
            printf ("\n");
        }
        z=0;
        for (int i=0;i<4;i++)
        {
            printf ("%s",low[rem[z++]-'0']);
            if (z==2)z++;
            if (i==1)printf ("     ");
            else if (i<3)printf ("  ");
        }
        printf ("\n\n\n");
    }
    printf ("end\n");
}
