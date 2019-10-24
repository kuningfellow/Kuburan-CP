#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	if (n==1&&m==0){
		printf ("0 0\n");
		return 0;
	}
	int foun;
	int tm=m;
	vector<int>smal;
	vector<int>big;
	for (int i=0;i<n;i++){
		foun=0;
		for (int j=0;j<10;j++){
			if (i==0&&j==0)continue;
			if (tm-j<=9*(n-i-1)){
				smal.push_back(j);
				tm-=j;
				foun=1;
				break;
			}
		}
		if (foun==0){
			break;
		}
	}
	if (foun==0||tm!=0)printf ("-1");
	else{
		for (int i=0;i<n;i++){
			printf ("%d",smal[i]);
		}
	}
	printf (" ");
	tm=m;
	for (int i=0;i<n;i++){
		foun=0;
		for (int j=9;j>=0;j--){
			if (i==0&&j==0)continue;
			if (tm-j>=0){
				big.push_back(j);
				tm-=j;
				foun=1;
				break;
			}
		}
		if (foun==0){
			break;
		}
	}
	if (foun==0||tm!=0)printf ("-1");
	else{
		for (int i=0;i<n;i++){
			printf ("%d",big[i]);
		}
	}
	printf ("\n");
}