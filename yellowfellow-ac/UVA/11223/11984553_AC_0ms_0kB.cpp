//UVA 11223 O: dah dah dah!
#include <stdio.h>
#include <string.h>
int main()
{
    int tc,kas=1;
    scanf("%d",&tc);
    getchar();
    while (tc--)
    {
        char s[5000];
        scanf("%[^\n]s",s);
        getchar();
        char comp[50];
        int komp=0;
        int siz=strlen(s);
        int space=0;
        int ful=0;
        char prev;
        printf ("Message #%d\n",kas++);
        for (int i=0;i<siz;i++)
        {
            if (s[i]==' ')
            {
                if (!strcmp(comp,".-"))printf ("A");
                if (!strcmp(comp,"-..."))printf ("B");
                if (!strcmp(comp,"-.-."))printf ("C");
                if (!strcmp(comp,"-.."))printf ("D");
                if (!strcmp(comp,"."))printf ("E");
                if (!strcmp(comp,"..-."))printf ("F");
                if (!strcmp(comp,"--."))printf ("G");
                if (!strcmp(comp,"...."))printf ("H");
                if (!strcmp(comp,".."))printf ("I");
                if (!strcmp(comp,".---"))printf ("J");
                if (!strcmp(comp,"-.-"))printf ("K");
                if (!strcmp(comp,".-.."))printf ("L");
                if (!strcmp(comp,"--"))printf ("M");
                if (!strcmp(comp,"-."))printf ("N");
                if (!strcmp(comp,"---"))printf ("O");
                if (!strcmp(comp,".--."))printf ("P");
                if (!strcmp(comp,"--.-"))printf ("Q");
                if (!strcmp(comp,".-."))printf ("R");
                if (!strcmp(comp,"..."))printf ("S");
                if (!strcmp(comp,"-"))printf ("T");
                if (!strcmp(comp,"..-"))printf ("U");
                if (!strcmp(comp,"...-"))printf ("V");
                if (!strcmp(comp,".--"))printf ("W");
                if (!strcmp(comp,"-..-"))printf ("X");
                if (!strcmp(comp,"-.--"))printf ("Y");
                if (!strcmp(comp,"--.."))printf ("Z");
                if (!strcmp(comp,"-----"))printf ("0");
                if (!strcmp(comp,".----"))printf ("1");
                if (!strcmp(comp,"..---"))printf ("2");
                if (!strcmp(comp,"...--"))printf ("3");
                if (!strcmp(comp,"....-"))printf ("4");
                if (!strcmp(comp,"....."))printf ("5");
                if (!strcmp(comp,"-...."))printf ("6");
                if (!strcmp(comp,"--..."))printf ("7");
                if (!strcmp(comp,"---.."))printf ("8");
                if (!strcmp(comp,"----."))printf ("9");
                if (!strcmp(comp,".-.-.-"))printf (".");
                if (!strcmp(comp,"--..--"))printf (",");
                if (!strcmp(comp,"..--.."))printf ("?");
                if (!strcmp(comp,".----."))printf ("\'");
                if (!strcmp(comp,"-.-.--"))printf ("!");
                if (!strcmp(comp,"-..-."))printf ("/");
                if (!strcmp(comp,"-.--."))printf ("(");
                if (!strcmp(comp,"-.--.-"))printf (")");
                if (!strcmp(comp,".-..."))printf ("&");
                if (!strcmp(comp,"---..."))printf (":");
                if (!strcmp(comp,"-.-.-."))printf (";");
                if (!strcmp(comp,"-...-"))printf ("=");
                if (!strcmp(comp,".-.-."))printf ("+");
                if (!strcmp(comp,"-....-"))printf ("-");
                if (!strcmp(comp,"..--.-"))printf ("_");
                if (!strcmp(comp,".-..-."))printf ("\"");
                if (!strcmp(comp,".--.-."))printf ("@");
                space++;
                if (space>=2)
                {
                    space=0;
                    printf (" ");
                }
                komp=0;
                comp[0]='\0';
            }
            else if (s[i]!=' ')
            {
                space=0;
                comp[komp++]=s[i];
                comp[komp]='\0';
            }
        }
        if (komp!=0)
        {
                if (!strcmp(comp,".-"))printf ("A");
                if (!strcmp(comp,"-..."))printf ("B");
                if (!strcmp(comp,"-.-."))printf ("C");
                if (!strcmp(comp,"-.."))printf ("D");
                if (!strcmp(comp,"."))printf ("E");
                if (!strcmp(comp,"..-."))printf ("F");
                if (!strcmp(comp,"--."))printf ("G");
                if (!strcmp(comp,"...."))printf ("H");
                if (!strcmp(comp,".."))printf ("I");
                if (!strcmp(comp,".---"))printf ("J");
                if (!strcmp(comp,"-.-"))printf ("K");
                if (!strcmp(comp,".-.."))printf ("L");
                if (!strcmp(comp,"--"))printf ("M");
                if (!strcmp(comp,"-."))printf ("N");
                if (!strcmp(comp,"---"))printf ("O");
                if (!strcmp(comp,".--."))printf ("P");
                if (!strcmp(comp,"--.-"))printf ("Q");
                if (!strcmp(comp,".-."))printf ("R");
                if (!strcmp(comp,"..."))printf ("S");
                if (!strcmp(comp,"-"))printf ("T");
                if (!strcmp(comp,"..-"))printf ("U");
                if (!strcmp(comp,"...-"))printf ("V");
                if (!strcmp(comp,".--"))printf ("W");
                if (!strcmp(comp,"-..-"))printf ("X");
                if (!strcmp(comp,"-.--"))printf ("Y");
                if (!strcmp(comp,"--.."))printf ("Z");
                if (!strcmp(comp,"-----"))printf ("0");
                if (!strcmp(comp,".----"))printf ("1");
                if (!strcmp(comp,"..---"))printf ("2");
                if (!strcmp(comp,"...--"))printf ("3");
                if (!strcmp(comp,"....-"))printf ("4");
                if (!strcmp(comp,"....."))printf ("5");
                if (!strcmp(comp,"-...."))printf ("6");
                if (!strcmp(comp,"--..."))printf ("7");
                if (!strcmp(comp,"---.."))printf ("8");
                if (!strcmp(comp,"----."))printf ("9");
                if (!strcmp(comp,".-.-.-"))printf (".");
                if (!strcmp(comp,"--..--"))printf (",");
                if (!strcmp(comp,"..--.."))printf ("?");
                if (!strcmp(comp,".----."))printf ("\'");
                if (!strcmp(comp,"-.-.--"))printf ("!");
                if (!strcmp(comp,"-..-."))printf ("/");
                if (!strcmp(comp,"-.--."))printf ("(");
                if (!strcmp(comp,"-.--.-"))printf (")");
                if (!strcmp(comp,".-..."))printf ("&");
                if (!strcmp(comp,"---..."))printf (":");
                if (!strcmp(comp,"-.-.-."))printf (";");
                if (!strcmp(comp,"-...-"))printf ("=");
                if (!strcmp(comp,".-.-."))printf ("+");
                if (!strcmp(comp,"-....-"))printf ("-");
                if (!strcmp(comp,"..--.-"))printf ("_");
                if (!strcmp(comp,".-..-."))printf ("\"");
                if (!strcmp(comp,".--.-."))printf ("@");
                ful=0;
                komp=0;
                comp[komp]='\0';
        }
        printf ("\n");
        if (tc>0)printf ("\n");
        s[0]='\0';
    }
}
