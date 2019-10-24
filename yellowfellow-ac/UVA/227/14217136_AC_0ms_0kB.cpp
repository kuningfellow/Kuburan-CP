//UVA 227 Puzzle
#include <bits/stdc++.h>
using namespace std;
char ram[50000];
int main(){
    int kas=1;
    while (1<2){
        int done=0;
        char rem[5][7];
        int x=-1,y=-1;
        for (int i=0;i<5;i++){
            scanf("%[^\n]",rem[i]);
            getchar();
            if (strlen(rem[i])<4&&rem[i][0]=='Z'){
                done=1;
                break;
            }
            if (strlen(rem[i])<5&&x==-1){
                x=i;
                y=4;
            }
            for (int j=0;j<5;j++){
                if (rem[i][j]==' '){
                    x=i;
                    y=j;
                }
            }
        }
        if (done)break;
        int val=1;
        while (1<2){
            char c;
            scanf("%[^\n]",ram);
            getchar();
            int l=strlen(ram);
            for (int i=0;i<l;i++){
                c=ram[i];
                if (c=='0'){
                    l=-1;
                    break;
                }
                if (val==0)continue;
                if (c=='A'){
                    if (x-1<0){
                        val=0;
                        continue;
                    }
                    rem[x][y]=rem[x-1][y];
                    rem[x-1][y]=' ';
                    x--;
                }
                else if (c=='B'){
                    if (x+1>4){
                        val=0;
                        continue;
                    }
                    rem[x][y]=rem[x+1][y];
                    rem[x+1][y]=' ';
                    x++;
                }
                else if (c=='R'){
                    if (y+1>4){
                        val=0;
                        continue;
                    }
                    rem[x][y]=rem[x][y+1];
                    rem[x][y+1]=' ';
                    y++;
                }
                else if (c=='L'){
                    if (y-1<0){
                        val=0;
                        continue;
                    }
                    rem[x][y]=rem[x][y-1];
                    rem[x][y-1]=' ';
                    y--;
                }
                else{
                    val=0;
                }
            }
            if (l==-1)break;
        }
        if (kas!=1)printf ("\n");
        printf ("Puzzle #%d:\n",kas++);
        if (val==0)printf ("This puzzle has no final configuration.\n");
        else{
            for (int i=0;i<5;i++){
                for (int j=0;j<5;j++){
                    if (j!=0)printf (" ");
                    printf ("%c",rem[i][j]);
                }
                printf ("\n");
            }
        }
    }
}