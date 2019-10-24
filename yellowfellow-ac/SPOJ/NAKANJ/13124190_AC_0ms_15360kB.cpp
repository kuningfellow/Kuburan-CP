#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        char rem[5];
        char ram[5];
        scanf("%s",rem);
        scanf("%s",ram);
        int vis[8][8];
        int x1=rem[0]-'a',y1=rem[1]-'1',x2=ram[0]-'a',y2=ram[1]-'1',x,y;
        for (int i=0;i<8;i++){
            for (int j=0;j<8;j++){
                vis[i][j]=0;
            }
        }
        queue<pair<int,int> >q;
        q.push(pair<int,int>(x1,y1));
        vis[x1][y1]=1;
        int mov=0;
        while (!q.empty()&&vis[x2][y2]==0){
            int siz=q.size();
            for (int i=0;i<siz;i++){
                x=q.front().first;
                y=q.front().second;
                if (x+2<8&&y+1<8&&vis[x+2][y+1]==0){
                    vis[x+2][y+1]=1;
                    q.push(pair<int,int>(x+2,y+1));
                }
                if (x+2<8&&y-1>=0&&vis[x+2][y-1]==0){
                    vis[x+2][y-1]=1;
                    q.push(pair<int,int>(x+2,y-1));
                }
                if (x+1<8&&y+2<8&&vis[x+1][y+2]==0){
                    vis[x+1][y+2]=1;
                    q.push(pair<int,int>(x+1,y+2));
                }
                if (x+1<8&&y-2>=0&&vis[x+1][y-2]==0){
                    vis[x+1][y-2]=1;
                    q.push(pair<int,int>(x+1,y-2));
                }
                if (x-1>=0&&y+2<8&&vis[x-1][y+2]==0){
                    vis[x-1][y+2]=1;
                    q.push(pair<int,int>(x-1,y+2));
                }
                if (x-1>=0&&y-2>=0&&vis[x-1][y-2]==0){
                    vis[x-1][y-2]=1;
                    q.push(pair<int,int>(x-1,y-2));
                }
                if (x-2>=0&&y+1<8&&vis[x-2][y+1]==0){
                    vis[x-2][y+1]=1;
                    q.push(pair<int,int>(x-2,y+1));
                }
                if (x-2>=0&&y-1>=0&&vis[x-2][y-1]==0){
                    vis[x-2][y-1]=1;
                    q.push(pair<int,int>(x-2,y-1));
                }
                q.pop();
            }
            mov++;
        }
        printf ("%d\n",mov);
    }
}
