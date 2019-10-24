#include <bits/stdc++.h>
using namespace std;
char rem[105][105][105];
int vis[105][105][105];
pair<int,pair<int,int> >triplet(int x, int y, int z){
    return pair<int,pair<int,int> >(x,pair<int,int>(y,z));
}
int dp[105][10005];
int ar[105][2];
int n;
int serc(int x, int t){
    if (t<0){
        return -(1<<30);
    }
    if (x==n)return 0;
    if (dp[x][t]!=-1){
        return dp[x][t];
    }
    return dp[x][t]=max(serc(x+1,t),ar[x][1]+serc(x+1,t-ar[x][0]));
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int l,h,w,s,a,b,c,d;
        cin>>l>>h>>w>>n>>s;
        for (int i=0;i<n;i++){
            for (int j=0;j<=s;j++){
                dp[i][j]=-1;
            }
        }
        int x0,y0,z0;
        for (int i=0;i<l;i++){
            for (int j=0;j<h;j++){
                scanf("%s",rem[i][j]);
                for (int k=0;k<w;k++){
                    if (rem[i][j][k]=='S'){
                        x0=i;
                        y0=j;
                        z0=k;
                    }
                }
            }
        }
        for (int i=0;i<105;i++){
            for (int j=0;j<105;j++){
                for (int k=0;k<105;k++){
                    vis[i][j][k]=(1<<28);
                }
            }
        }
        queue<pair<int,pair<int,int> > >q;
        q.push(triplet(x0,y0,z0));
        int x,y,z;
        vis[q.front().first][q.front().second.first][q.front().second.second]=0;
        int cost=0;
        while (!q.empty()){
            int siz=q.size();
            cost++;
            for (int i=0;i<siz;i++){
                x=q.front().first;
                y=q.front().second.first;
                z=q.front().second.second;
                if (y+1<h&&rem[x][y+1][z]!='X'&&vis[x][y+1][z]==(1<<28)){
                    vis[x][y+1][z]=cost;
                    q.push(triplet(x,y+1,z));
                }
                if (y-1>=0&&rem[x][y-1][z]!='X'&&vis[x][y-1][z]==(1<<28)){
                    vis[x][y-1][z]=cost;
                    q.push(triplet(x,y-1,z));
                }
                if (z+1<w&&rem[x][y][z+1]!='X'&&vis[x][y][z+1]==(1<<28)){
                    vis[x][y][z+1]=cost;
                    q.push(triplet(x,y,z+1));
                }
                if (z-1>=0&&rem[x][y][z-1]!='X'&&vis[x][y][z-1]==(1<<28)){
                    vis[x][y][z-1]=cost;
                    q.push(triplet(x,y,z-1));
                }
                if (rem[x][y][z]=='U'&&vis[x+1][y][z]==(1<<28)){
                    vis[x+1][y][z]=cost;
                    q.push(triplet(x+1,y,z));
                }
                if (rem[x][y][z]=='D'&&vis[x-1][y][z]==(1<<28)){
                    vis[x-1][y][z]=cost;
                    q.push(triplet(x-1,y,z));
                }
                q.pop();
            }
        }
        for (int i=0;i<n;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            ar[i][0]=vis[a-1][b-1][c-1]*3;
            ar[i][1]=d;
        }
        printf ("%d\n",serc(0,s));
    }
}