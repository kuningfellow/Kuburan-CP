//UVA 947 Master Mind Helper
#include <bits/stdc++.h>
using namespace std;
int ar[9];
int br[9];
int cr[9];
int st,we,l;
int serc(int x){
    if (l==x){
        int tst=0;
        int twe=0;
        for (int i=0;i<l;i++)
            cr[i]=0;
        for (int i=0;i<l;i++){
            if (ar[i]==br[i]){
                cr[i]|=3;
                tst++;
            }
        }
        for (int i=0;i<l;i++){
            if ((cr[i]&2)>0)continue;
            for (int j=0;j<l;j++){
                if ((cr[j]&1)>0)continue;
                if (ar[j]==br[i]){
                    cr[j]|=1;
                    twe++;
                    break;
                }
            }
        }
        if (tst==st&&twe==we)
            return 1;
        return 0;
    }
    int ret=0;
    for (int i=0;i<9;i++){
        br[x]=i+1;
        ret+=serc(x+1);
    }
    return ret;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        char rem[6];
        scanf("%s",rem);
        l=strlen(rem);
        for (int i=0;i<l;i++){
            ar[i]=rem[i]-'0';
        }
        cin>>st>>we;
        cout<<serc(0)<<endl;
    }
}