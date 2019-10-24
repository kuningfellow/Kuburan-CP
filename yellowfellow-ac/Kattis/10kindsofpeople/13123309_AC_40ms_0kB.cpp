#include <bits/stdc++.h>
using namespace std;
int ter[1005][1005];
char rem[1005][1005];
int r,c;
void fil(int x, int y, int co){
    ter[x][y]=co;
    if (x+1<r&&ter[x+1][y]==0&&rem[x+1][y]==rem[x][y]){
        fil(x+1,y,co);
    }
    if (x-1>=0&&ter[x-1][y]==0&&rem[x-1][y]==rem[x][y]){
        fil(x-1,y,co);
    }
    if (y+1<c&&ter[x][y+1]==0&&rem[x][y+1]==rem[x][y]){
        fil(x,y+1,co);
    }
    if (y-1>=0&&ter[x][y-1]==0&&rem[x][y-1]==rem[x][y]){
        fil(x,y-1,co);
    }
}
int main(){
    cin>>r>>c;
    for (int i=0;i<r;i++){
        scanf("%s",rem[i]);
    }
    int n=1;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (ter[i][j]==0){
                fil(i,j,n++);
            }
        }
    }
    cin>>n;
    int a,b,c,d;
    for (int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        if (ter[a-1][b-1]==ter[c-1][d-1]){
            if (rem[a-1][b-1]=='0'){
                printf ("binary\n");
            }
            else printf ("decimal\n");
        }
        else printf ("neither\n");
    }
}
