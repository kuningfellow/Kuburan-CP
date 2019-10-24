//UVA 492 Pig Latin
#include <stdio.h>
#include <string.h>
int main()
{
    char temp[1000000];
    int mode;
    char sa;
    int start;
    int siz;
    while (scanf("%[^\n]s",temp)!=EOF)
    {
        start=1;
        getchar();
        mode=0;
        siz=strlen(temp);
        for (int i=0;i<siz;i++)
        {
            if ((temp[i]=='A'||temp[i]=='E'||temp[i]=='I'||temp[i]=='O'||temp[i]=='U'||
                temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u')&&start==1)
            {
                start=0;
                mode=1;
                printf ("%c",temp[i]);
            }
            else if (((temp[i]>='a'&&temp[i]<='z')||(temp[i]>='A'&&temp[i]<='Z'))&&start==1)
            {
                start=0;
                sa=temp[i];
                mode=2;
            }
            else if (start==0&&((temp[i]>='a'&&temp[i]<='z')||(temp[i]>='A'&&temp[i]<='Z')))
            {
                printf ("%c",temp[i]);
            }
            else
            {
                if (mode==1)
                {
                    printf ("ay");
                }
                else if (mode==2)
                {
                    printf ("%cay",sa);
                }
                mode=0;
                start=1;
                printf ("%c",temp[i]);
            }
        }
        if (mode==1)
        {
            printf ("ay");
        }
        else if (mode==2)
        {
            printf ("%cay",sa);
        }
        if (strlen(temp))
            printf ("\n");
        temp[0]='\0';
    }
}
