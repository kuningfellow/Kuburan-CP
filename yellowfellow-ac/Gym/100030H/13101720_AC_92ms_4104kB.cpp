#include<bits/stdc++.h>
using namespace std;
map<char,int> data;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	int k;
	scanf("%d",&k);
	int hasl=0,hasr=0,l=0,r=0;
	string s;
	cin>>s;
	int leng=s.size();
	int var=0;
	for(int i=0;i<leng;i++){
//		cout<<l<<" "<<r<<" "<<i<<" "<<var<<endl;
		if(data[s[i]]==0){
			data[s[i]]++;
			var++;
		}
		else data[s[i]]++;
		if(var<=k){
			r=i;
			if(r-l > hasr-hasl){
				hasl=l;
				hasr=r;
			}
		}
		else{
//			cout<<"data "<<data[s[l]]<<endl;
			data[s[l]]--;
			if(data[s[l]]==0)var--;
			l+=1;
		}
	}
	printf("%d %d\n",hasl+1,hasr+1);
}