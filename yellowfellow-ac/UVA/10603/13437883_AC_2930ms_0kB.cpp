#include <bits/stdc++.h>
using namespace std;
bool vis[205][205][205];
struct data{
    int a;
    int b;
    int c;
    int wat;
    bool operator < ( const data &other) const {
        return wat>other.wat;
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
        for (int i=0;i<201;i++){
            for (int j=0;j<201;j++){
                for (int k=0;k<201;k++){
                    vis[i][j][k]=0;
                }
            }
        }
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        data dat;
        dat.a=0;
        dat.b=0;
        dat.c=c;
        dat.wat=0;
        priority_queue<data>pq;
        pq.push(dat);
        int temp=0;
        int ans=0;
        while (!pq.empty()){
            int A=pq.top().a;
            int B=pq.top().b;
            int C=pq.top().c;
            int cur=pq.top().wat;
            int pour;
            pq.pop();
            if (vis[A][B][C]==1)continue;
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
            pour=min(C,a-A);
            if (vis[A+pour][B][C-pour]==0){
                dat.a=A+pour;
                dat.b=B;
                dat.c=C-pour;
                dat.wat=cur+pour;
                pq.push(dat);
            }
            pour=min(C,b-B);
            if (vis[A][B+pour][C-pour]==0){
                dat.a=A;
                dat.b=B+pour;
                dat.c=C-pour;
                dat.wat=cur+pour;
                pq.push(dat);
            }
            pour=min(B,a-A);
            if (vis[A+pour][B-pour][C]==0){
                dat.a=A+pour;
                dat.b=B-pour;
                dat.c=C;
                dat.wat=cur+pour;
                pq.push(dat);
            }
            pour=min(B,c-C);
            if (vis[A][B-pour][C+pour]==0){
                dat.a=A;
                dat.b=B-pour;
                dat.c=C+pour;
                dat.wat=cur+pour;
                pq.push(dat);
            }
            pour=min(A,b-B);
            if (vis[A-pour][B+pour][C]==0){
                dat.a=A-pour;
                dat.b=B+pour;
                dat.c=C;
                dat.wat=cur+pour;
                pq.push(dat);
            }
            pour=min(A,c-C);
            if (vis[A-pour][B][C+pour]==0){
                dat.a=A-pour;
                dat.b=B;
                dat.c=C+pour;
                dat.wat=cur+pour;
                pq.push(dat);
            }
        }
        printf ("%d %d\n",temp,ans);
    }
}