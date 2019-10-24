#include <bits/stdc++.h>
using namespace std;
int ar[5000000][4];
int sum[5000000];
int siz;
int no;
int bad;
int fin(int k){
	int lef;
	int rig;
	if (ar[k][0]==0){
		no++;
		lef=fin(no);
	}
	else{
		lef=ar[k][0];
	}
	if (ar[k][2]==0){
		no++;
		rig=fin(no);
	}
	else{
		rig=ar[k][2];
	}
	if (lef*ar[k][1]!=rig*ar[k][3]){
		bad=1;
	}
	return lef+rig;
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		char rem[500];
		int fir=0;
		int a,b,c,d;
		siz=1;
		int lim=1;
		while (lim--){
			cin>>a>>b>>c>>d;
			if (a==0)lim++;
			if (c==0)lim++;
			ar[siz][0]=a;
			ar[siz][1]=b;
			ar[siz][2]=c;
			ar[siz][3]=d;
			siz++;
		}
		for (int i=1;i<=siz;i++){
			sum[i]=0;
		}
		no=1;
		bad=0;
		fin(1);
		if (bad==0){
			printf ("YES\n");
		}
		else{
			printf ("NO\n");
		}
		if (tc>0)printf ("\n");
	}
}