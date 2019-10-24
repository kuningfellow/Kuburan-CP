#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int r,c;
        cin>>r>>c;
        char rem[r][c+1];
        int vis[r][c];
        queue<pair<int,int> >q;
        for (int i=0;i<r;i++){
            scanf("%s",rem[i]);
            for (int j=0;j<c;j++){
                vis[i][j]=0;
                if (i==0||i==r-1){
                    if (rem[i][j]=='.'){
                        q.push(pair<int,int>(i,j));
                    }
                }
                else{
                    if (j==0||j==c-1){
                        if (rem[i][j]=='.'){
                            q.push(pair<int,int>(i,j));
                        }
                    }
                }
            }
        }
        if (q.size()!=2){
            printf ("invalid\n");
        }
        else{
            int tx=q.front().first;
            int ty=q.front().second;
            int x,y;
            q.pop();
            while (!q.empty()){
                int siz=q.size();
                for (int i=0;i<siz;i++){
                    x=q.front().first;
                    y=q.front().second;
                    if (x+1<r&&vis[x+1][y]==0&&rem[x+1][y]=='.'){
                        vis[x+1][y]=1;
                        q.push(pair<int,int>(x+1,y));
                    }
                    if (y+1<c&&vis[x][y+1]==0&&rem[x][y+1]=='.'){
                        vis[x][y+1]=1;
                        q.push(pair<int,int>(x,y+1));
                    }
                    if (x-1>=0&&vis[x-1][y]==0&&rem[x-1][y]=='.'){
                        vis[x-1][y]=1;
                        q.push(pair<int,int>(x-1,y));
                    }
                    if (y-1>=0&&vis[x][y-1]==0&&rem[x][y-1]=='.'){
                        vis[x][y-1]=1;
                        q.push(pair<int,int>(x,y-1));
                    }
                    q.pop();
                }
            }
            if (vis[tx][ty]==0){
                printf ("invalid\n");
            }
            else printf ("valid\n");
        }
    }
}
