//UVA 11958 Coming Home
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int k,h,m;
        scanf("%d%d:%d\n",&k,&h,&m);
        m+=h*60;
        int best=(1<<20);
        int one=24*60;
        for (int i=0;i<k;i++){
            int h1,m1,d;
            scanf("%d:%d%d",&h1,&m1,&d);
            m1+=h1*60;
            if (m1<m)
                m1+=one;
            best=min(best,m1-m+d);
        }
        printf ("Case %d: %d\n",kas++,best);
    }
}