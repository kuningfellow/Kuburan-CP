#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,m,x=1,y=1;
        cin>>n>>m;
        n--;
        m--;
        long long int ar[n];
        long long int br[m];
        for (int i=0;i<n;i++){
            cin>>ar[i];
        }
        for (int i=0;i<m;i++){
            cin>>br[i];
        }
        long long int cost=0;
        int pa=n-1;
        int pb=m-1;
        sort(ar,ar+n);
        sort(br,br+m);
        while (pa>=0||pb>=0){
            if (pa<0){
                cost+=br[pb--]*x;
                y++;
            }
            else if (pb<0){
                cost+=ar[pa--]*y;
                x++;
            }
            else if (ar[pa]>br[pb]){
                cost+=ar[pa--]*y;
                x++;
            }
            else{
                cost+=br[pb--]*x;
                y++;
            }
        }
        printf ("%lld\n",cost);
    }
}