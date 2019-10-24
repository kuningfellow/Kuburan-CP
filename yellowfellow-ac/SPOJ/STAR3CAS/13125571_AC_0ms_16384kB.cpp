#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        int ar[n];
        int vis[n+1];
        for (int i=0;i<n;i++){
            vis[i+1]=0;
            cin>>ar[i];
        }
        vis[0]=0;
        queue<int>q;
        q.push(0);
        int st=0;
        while(!q.empty()&&vis[n]==0){
            int siz=q.size();
            for (int i=0;i<siz;i++){
                if (q.front()+ar[q.front()]>=0&&q.front()+ar[q.front()]<=n&&vis[q.front()+ar[q.front()]]==0){
                    vis[q.front()+ar[q.front()]]=1;
                    q.push(q.front()+ar[q.front()]);
                }
                if (q.front()+1<=n&&vis[q.front()+1]==0){
                    vis[q.front()+1]=1;
                    q.push(q.front()+1);
                }
                q.pop();
            }
            st++;
        }
        printf ("%d\n",st);
    }
}
