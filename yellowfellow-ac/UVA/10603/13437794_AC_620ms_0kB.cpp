#include <bits/stdc++.h>
using namespace std;
int vis[205][205][205];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc;
    cin>>tc;
    while(tc--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for (int i=0;i<=a;i++){
            for (int j=0;j<=b;j++){
                for (int k=0;k<=c;k++){
                    vis[i][j][k]=0;
                }
            }
        }
        int x,y,z;
        priority_queue<pair<int,pair<int,pair<int,int> > > >pq;
        pq.push(pair<int,pair<int,pair<int,int > > >(0,pair<int,pair<int,int> >(0,pair<int,int>(0,c))));
        int temp=0;
        int ans=0;
        while (!pq.empty()){
            while (!pq.empty()&&vis[pq.top().second.first][pq.top().second.second.first][pq.top().second.second.second]==1){
                pq.pop();
            }
            if (!pq.empty()){
                int A=pq.top().second.first;
                int B=pq.top().second.second.first;
                int C=pq.top().second.second.second;
                int cur=pq.top().first;
                pq.pop();
                vis[A][B][C]=1;
                if (A>ans&&A<=d){
                    ans=A;
                    temp=cur;
                }
                if (B>ans&&B<=d){
                    ans=B;
                    temp=cur;
                }
                if (C>ans&&C<=d){
                    ans=C;
                    temp=cur;
                }
                if (ans==d){
                    break;
                }
                int pour=min(C,a-A);
                if (vis[A+pour][B][C-pour]==0){
                    x=A+pour;
                    y=B;
                    z=C-pour;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
                pour=min(C,b-B);
                if (vis[A][B+pour][C-pour]==0){
                    x=A;
                    y=B+pour;
                    z=C-pour;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
                pour=min(B,a-A);
                if (vis[A+pour][B-pour][C]==0){
                    x=A+pour;
                    y=B-pour;
                    z=C;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
                pour=min(B,c-C);
                if (vis[A][B-pour][C+pour]==0){
                    x=A;
                    y=B-pour;
                    z=C+pour;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
                pour=min(A,b-B);
                if (vis[A-pour][B+pour][C]==0){
                    x=A-pour;
                    y=B+pour;
                    z=C;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
                pour=min(A,c-C);
                if (vis[A-pour][B][C+pour]==0){
                    x=A-pour;
                    y=B;
                    z=C+pour;
                    pq.push(pair<int,pair<int,pair<int,int> > >(cur-pour,pair<int,pair<int,int> >(x,pair<int,int>(y,z))));
                }
            }
        }
        printf ("%d %d\n",-temp,ans);
    }
}