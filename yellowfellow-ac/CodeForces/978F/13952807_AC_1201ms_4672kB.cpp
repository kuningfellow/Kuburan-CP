#include <bits/stdc++.h>

struct data{
	int val;
	int idx;
	bool operator<(data a){
		if (val!=a.val)return val<a.val;
		return idx<a.idx;
	}
};

namespace hime_hime{
	int count[200005];
	void reset(){
		for (int i=0;i<200005;i++){
			count[i]=0;
		}
	}
	void suki_suki_daisuki_hime(int ar[], int n, int br[][2], int m){
		data process[n];
		for (int i=0;i<n;i++){
			process[i].val=ar[i];
			process[i].idx=i;
		}
		std::sort(process,process+n);
		int carry=0;
		int prev=-1;
		for (int i=0;i<n;i++){
			if (process[i].val==prev){
				carry++;
			}
			if (process[i].val>prev){
				carry=0;
			}
			prev=process[i].val;
			count[process[i].idx]+=i-carry;
		}
		for (int i=0;i<m;i++){
			if (ar[br[i][0]-1]<ar[br[i][1]-1]){
				count[br[i][1]-1]--;
			}
			else if (ar[br[i][0]-1]>ar[br[i][1]-1]){
				count[br[i][0]-1]--;
			}
		}
		for (int i=0;i<n;i++){
			if (i!=0)printf (" ");
			printf ("%d",count[i]);
		}
		printf ("\n");
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	std::cin>>n>>m;
	int ar[n];
	int br[m][2];
	for (int i=0;i<n;i++){
		std::cin>>ar[i];
	}
	for (int i=0;i<m;i++){
		std::cin>>br[i][0]>>br[i][1];
	}
	hime_hime::suki_suki_daisuki_hime(ar,n,br,m);
}