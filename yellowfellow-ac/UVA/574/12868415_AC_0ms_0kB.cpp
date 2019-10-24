#include <bits/stdc++.h>
using namespace std;
int num[13];
int t;
int n;
vector<int>lis;
map<string,int>tak;
int serc(int x, int s){
    if (s==t){
        string tmp;
        int rem;
        for (int i=lis.size()-1;i>=0;i--){
            rem=lis[i];
            while (rem>0){
                tmp+=(char)(rem%10+'0');
                rem/=10;
            }
            if (i>0)tmp+='+';
        }
        if (tak[tmp]==0){
            for (int i=tmp.size()-1;i>=0;i--){
                printf ("%c",tmp[i]);
            }
            printf ("\n");
        }
        tak[tmp]=1;
        return 1;
    }
    int ret=0;
    if (x>=n)return 0;
    lis.push_back(num[x]);
    ret=max(ret,serc(x+1,s+num[x]));
    lis.pop_back();
    ret=max(ret,serc(x+1,s));
    return ret;
}
int main(){
    while (1<2){
        cin>>t;
        cin>>n;
        if (t==0&&n==0)break;
        for (int i=0;i<n;i++){
            cin>>num[i];
        }
        printf ("Sums of %d:\n",t);
        if(!serc(0,0))printf ("NONE\n");
        tak.clear();
    }
}
