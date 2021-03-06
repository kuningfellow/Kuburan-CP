//UVA 10284 Chessboard in FEN
#include <bits/stdc++.h>
using namespace std;
int mark[8][8];
char rem[8][9];
int fil(int side, int x, int y, int t){
    if (t==1){
        if (side==1){
            if (x+1<8){
                if (y+1<8)mark[x+1][y+1]|=side;
                if (y-1>=0)mark[x+1][y-1]|=side;
            }
        }
        else{
            if (x-1>=0){
                if (y+1<8)mark[x-1][y+1]|=side;
                if (y-1>=0)mark[x-1][y-1]|=side;
            }
        }
    }
    if (t==2){
        if (x+2<8){
            if (y+1<8)mark[x+2][y+1]|=side;
            if (y-1>=0)mark[x+2][y-1]|=side;
        }
        if (x+1<8){
            if (y+2<8)mark[x+1][y+2]|=side;
            if (y-2>=0)mark[x+1][y-2]|=side;
        }
        if (x-2>=0){
            if (y+1<8)mark[x-2][y+1]|=side;
            if (y-1>=0)mark[x-2][y-1]|=side;
        }
        if (x-1>=0){
            if (y+2<8)mark[x-1][y+2]|=side;
            if (y-2>=0)mark[x-1][y-2]|=side;
        }
    }
    if (t==4||t==5){
        int px=x+1;
        int py=y;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px++;
        }
        px=x-1,py=y;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px--;
        }
        px=x,py=y+1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            py++;
        }
        px=x,py=y-1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            py--;
        }
    }
    if (t==3||t==5){
        int px=x+1;
        int py=y+1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px++;
            py++;
        }
        px=x-1,py=y+1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px--;
            py++;
        }
        px=x+1,py=y-1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px++;
            py--;
        }
        px=x-1,py=y-1;
        while (px<8&&px>=0&&py<8&&py>=0){
            mark[px][py]|=side;
            if (rem[px][py]!='.')break;
            px--;
            py--;
        }
    }
    if (t==6){
        if (x+1<8){
            mark[x+1][y]|=side;
            if (y+1<8)mark[x+1][y+1]|=side;
            if (y-1>=0)mark[x+1][y-1]|=side;
        }
        if (y+1<8)mark[x][y+1]|=side;
        if (y-1>=0)mark[x][y-1]|=side;
        if (x-1>=0){
            mark[x-1][y]|=side;
            if (y+1<8)mark[x-1][y+1]|=side;
            if (y-1>=0)mark[x-1][y-1]|=side;
        }
    }
}
int main(){
    char ram[500];
    while (scanf("%s",ram)!=EOF){
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                mark[i][j]=0;
                rem[i][j]='.';
            }
        }
        int x=0;
        int y=0;
        for (int i=0;i<strlen(ram);i++){
            if (ram[i]=='/'){
                x++;
                y=0;
            }
            else if (ram[i]>='0'&&ram[i]<='9'){
                for (int j=0;j<ram[i]-'0';j++){
                    rem[x][y]='.';
                    y++;
                }
            }
            else{
                rem[x][y]=ram[i];
                y++;
            }
        }
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (rem[i][j]=='p')fil(1,i,j,1);
                else if (rem[i][j]=='P')fil(2,i,j,1);
                else if (rem[i][j]=='n')fil(1,i,j,2);
                else if (rem[i][j]=='N')fil(2,i,j,2);
                else if (rem[i][j]=='b')fil(1,i,j,3);
                else if (rem[i][j]=='B')fil(2,i,j,3);
                else if (rem[i][j]=='r')fil(1,i,j,4);
                else if (rem[i][j]=='R')fil(2,i,j,4);
                else if (rem[i][j]=='q')fil(1,i,j,5);
                else if (rem[i][j]=='Q')fil(2,i,j,5);
                else if (rem[i][j]=='k')fil(1,i,j,6);
                else if (rem[i][j]=='K')fil(2,i,j,6);
            }
        }
        int cnt=0;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                if (rem[i][j]=='.'&&mark[i][j]==0)cnt++;
            }
        }
        printf ("%d\n",cnt);
    }
}