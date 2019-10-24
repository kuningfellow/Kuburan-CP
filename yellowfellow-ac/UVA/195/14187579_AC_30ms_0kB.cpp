//UVA 195 Anagram
#include <bits/stdc++.h>
using namespace std;
int cnt[52];
char out[500000];
int l;
void fin(int x, int val, int cur){
    if (x==l){
        if (val==1){
            for (int i=0;i<l;i++){
                printf ("%c",out[i]);
            }
            printf ("\n");
        }
        return;
    }
    int fir=1;
    for (int i=0;i<52;i++){
        if (cnt[i]==0)continue;
        cnt[i]--;
        out[x]=i/2+((i%2==0)?'A':'a');
        if (i==cur){
            fin(x+1,max(val,fir),i);
            fir=0;
        }
        else{
            fin(x+1,1,i);
        }
        cnt[i]++;
    }
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        scanf("%s",out);
        for (int i=0;i<52;i++)
            cnt[i]=0;
        l=strlen(out);
        for (int i=0;i<l;i++){
            if (out[i]>='A'&&out[i]<='Z'){
                cnt[(out[i]-'A')*2]++;
            }
            else{
                cnt[(out[i]-'a')*2+1]++;
            }
        }
        fin(0,0,-1);
    }
}