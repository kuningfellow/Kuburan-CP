//UVA 10528 Major Scales
#include <bits/stdc++.h>
using namespace std;
int main(){
    char rem[50000];
    while (1<2){
        scanf("%[^\n]",rem);
        getchar();
        char out[12][3]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
        int check[12]={1,0,1,0,1,1,0,1,0,1,0,1};
        if (!strcmp(rem,"END"))break;
        int vis[12]={};
        int l=strlen(rem);
        for (int i=0;i<l;i++){
            if (rem[i]=='C'&&(i+1==l||rem[i+1]==' '))vis[0]=1;
            else if (rem[i]=='C'&&(i+1<l&&rem[i+1]=='#'))vis[1]=1;
            else if (rem[i]=='D'&&(i+1==l||rem[i+1]==' '))vis[2]=1;
            else if (rem[i]=='D'&&(i+1<l&&rem[i+1]=='#'))vis[3]=1;
            else if (rem[i]=='E')vis[4]=1;
            else if (rem[i]=='F'&&(i+1==l||rem[i+1]==' '))vis[5]=1;
            else if (rem[i]=='F'&&(i+1<l&&rem[i+1]=='#'))vis[6]=1;
            else if (rem[i]=='G'&&(i+1==l||rem[i+1]==' '))vis[7]=1;
            else if (rem[i]=='G'&&(i+1<l&&rem[i+1]=='#'))vis[8]=1;
            else if (rem[i]=='A'&&(i+1==l||rem[i+1]==' '))vis[9]=1;
            else if (rem[i]=='A'&&(i+1<l&&rem[i+1]=='#'))vis[10]=1;
            else if (rem[i]=='B')vis[11]=1;
        }
        int fir=1;
        for (int i=0;i<12;i++){
            int mat=1;
            for (int j=0;j<12;j++){
                if (vis[(i+j)%12]>check[j]){
                    mat=0;
                    break;
                }
            }
            if (mat==1){
                if (fir==0)printf (" ");
                fir=0;
                printf ("%s",out[i]);
            }
        }
        printf ("\n");
    }
}