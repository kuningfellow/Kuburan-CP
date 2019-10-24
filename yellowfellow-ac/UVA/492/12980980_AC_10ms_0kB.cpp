#include <bits/stdc++.h>
using namespace std;
bool alphacheck(char a){
    if (a>='a'&&a<='z')return 1;
    else if (a>='A'&&a<='Z')return 1;
    return 0;
}
bool vowel(char a){
    if (a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U')return 1;
    return 0;
}
char rem[1000000];
int main(){
    char c;
    int l=0;
    while (1<2){
        c=getchar();
        if (c==EOF)break;
        rem[l++]=c;
    }
    int flag=0;
    int mode=0;
    char sav;
    int fir=0;
    for (int i=0;i<l;i++){
        if (alphacheck(rem[i])){
            if (fir==0&&vowel(rem[i])){
                printf ("%c",rem[i]);
                mode=1;
            }
            else if (fir==0){
                mode=-1;
                sav=rem[i];
            }
            else printf ("%c",rem[i]);
            fir=1;
        }
        else{
            fir=0;
            if (mode==1)printf ("ay");
            else if (mode==-1)printf ("%cay",sav);
            mode=0;
            printf ("%c",rem[i]);
        }
    }
}
