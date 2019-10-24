#include<bits/stdc++.h>
using namespace std;

int r[1000005],c[1000005],lr[1000005],lc[1000005];
pair<int,int> ar[1000005];

int main(){
    int n,m,x,hit = 0 ;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j <m ;j ++){
            scanf("%d",&x);
            ar[hit].first = x;
            ar[hit++].second = i*m+j;
        }
    }
    sort(ar,ar+hit);
    for(int i = 0; i <= hit ; i ++){
        r[i] = c [i] = 0;
        lr[i] = lc[i] = -1;
    }
    int ro,co,v;
    for(int i = 0 ; i < hit ; i ++){
        v = ar[i].first;
        ro = ar[i].second;
        co = ro%m;
        ro /= m;
        if(v == lr[ro]){
            if(r[ro] >= c[co]){
                    c[co] = r[ro];
            }
            else{
                r[ro] = ++c[co] ;
            }
        }
        else if(v == lc[co]){
            if(c[co] >= r[ro]){
                    r[ro] = c[co];
            }
            else{
                c[co] = ++r[ro] ;
            }
        }
        else{
            r[ro] = c[co] = max(r[ro],c[co])+1;
        }
        lr[ro] = lc[co] = v;
    }
    int ans = 0 ;
    for(int i = 0 ; i < n ; i ++) ans = max(ans , r[i]);
    for(int i = 0 ; i < m ; i ++) ans = max(ans, c[i]);
    printf("%d\n",ans);
    return 0;
}
