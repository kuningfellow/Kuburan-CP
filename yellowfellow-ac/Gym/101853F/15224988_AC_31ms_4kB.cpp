#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        int tot=0;
        for (int i=0;i<n;i++){
            char rem[50];
            scanf("%s",rem);
            int fir=((rem[0]-'0')*10+rem[1]-'0')*60+((rem[3]-'0')*10+rem[4]-'0');
            scanf("%s",rem);
            int sec=((rem[0]-'0')*10+rem[1]-'0')*60+((rem[3]-'0')*10+rem[4]-'0');
            tot+=sec-fir;
        }
        if (tot/60>=m){
            printf ("YES\n");
        }
        else printf ("NO\n");
    }
}