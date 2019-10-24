#include <bits/stdc++.h>
using namespace std;
bool vis[205][205][205];
struct data{
    int a;
    int b;
    int c;
    bool operator < ( const data &other) const {
        if (a==other.a){
            if (b==other.b){
                return c<other.c;
            }
            else return b<other.b;
        }
        else{
            return a<other.a;
        }
    }
};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        for (int i=0;i<205;i++){
            for (int j=0;j<205;j++){
                for (int k=0;k<205;k++){
                    vis[i][j][k]=0;
                }
            }
        }
        data dat;
        dat.a=0;
        dat.b=0;
        dat.c=c;
        priority_queue<pair<int,data> >pq;
        pq.push(pair<int,data>(0,dat));
        int temp=0;
        int ans=0;
        while (!pq.empty()){
            while (!pq.empty()&&vis[pq.top().second.a][pq.top().second.b][pq.top().second.c]==1){
                pq.pop();
            }
            if (!pq.empty()){
                int A=pq.top().second.a;
                int B=pq.top().second.b;
                int C=pq.top().second.c;
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
                    dat.a=A+pour;
                    dat.b=B;
                    dat.c=C-pour;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
                pour=min(C,b-B);
                if (vis[A][B+pour][C-pour]==0){
                    dat.a=A;
                    dat.b=B+pour;
                    dat.c=C-pour;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
                pour=min(B,a-A);
                if (vis[A+pour][B-pour][C]==0){
                    dat.a=A+pour;
                    dat.b=B-pour;
                    dat.c=C;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
                pour=min(B,c-C);
                if (vis[A][B-pour][C+pour]==0){
                    dat.a=A;
                    dat.b=B-pour;
                    dat.c=C+pour;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
                pour=min(A,b-B);
                if (vis[A-pour][B+pour][C]==0){
                    dat.a=A-pour;
                    dat.b=B+pour;
                    dat.c=C;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
                pour=min(A,c-C);
                if (vis[A-pour][B][C+pour]==0){
                    dat.a=A-pour;
                    dat.b=B;
                    dat.c=C+pour;
                    pq.push(pair<int,data>(cur-pour,dat));
                }
            }
        }
        printf ("%d %d\n",-temp,ans);
    }
}