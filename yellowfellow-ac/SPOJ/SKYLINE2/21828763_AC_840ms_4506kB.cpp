#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>>lis, ans;
int main(){int tc; scanf("%d",&tc);while(tc--){
lis.clear(),ans.clear();
int n; scanf("%d",&n);
for(int i=0;i<n;i++){int a,b; scanf("%d %d",&a,&b);
lis.push_back(pair<int,int>(-a,-b));}
sort(lis.begin(),lis.end());
int prev,prev2;
for(int i=0;i<n;i++){
if (i==0)prev=lis[i].second,prev2=lis[i].first;
else{
if(lis[i].second>prev||(lis[i].first>prev2&&lis[i].second==prev))continue;
else prev=lis[i].second,prev2=lis[i].first;}
ans.push_back(lis[i]);}
printf("%d\n",ans.size());
for(int i=0;i<ans.size();i++)printf("%d %d\n", -ans[i].first,-ans[i].second);
}
return 0;
}