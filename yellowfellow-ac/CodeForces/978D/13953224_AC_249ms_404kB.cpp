#include <bits/stdc++.h>

namespace nico_nico_nii{
	int progress(int ar[], int n, int a, int b ){
		int delta=ar[1]+a-ar[0]-b;
		int current=ar[0]+b+delta+delta;
		int count=(a!=0)+(b!=0);
		for (int i=2;i<n;i++){
			if (ar[i]-1<=current&&current<=ar[i]+1){
				count++;
				if (ar[i]==current){
					count--;
				}
			}
			else{
				count=-1;
				break;
			}
			current+=delta;
		}
		return count;
	}
	int search(int ar[], int n){
		if (n==1||n==2){
			return 0;
		}
		int best=-1;
		int res;
		for (int i=-1;i<2;i++){
			for (int j=-1;j<2;j++){
				res=progress(ar,n,i,j);
				if (res!=-1&&(best==-1||best>res)){
					best=res;
				}
			}
		}
		return best;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	std::cin>>n;
	int ar[n];
	for (int i=0;i<n;i++){
		std::cin>>ar[i];
	}
	std::cout<<nico_nico_nii::search(ar,n)<<std::endl;
}