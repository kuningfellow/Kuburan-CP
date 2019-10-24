//UVA 10659 Fitting Text into Slides
#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int p;
		cin>>p;
		getchar();
		char rem[p][5000];
		for (int i=0;i<p;i++){
			scanf("%[^\n]",rem[i]);
			getchar();
		}
		int x,y;
		cin>>x>>y;
		int best=-1;
		for (int i=8;i<=28;i++){
			int ht=0,vt=0;
			int val=1;
			for (int j=0;j<p;j++){
				ht=0;
				vt++;
				int l=strlen(rem[j]);
				int temp=0;
				int spac=0;
				for (int k=0;k<l;k++){
					if (rem[j][k]!=' '){
						temp+=i;
					}
					if (temp+spac+ht>x){
						spac=0;
						vt++;
						ht=0;
					}
					if (rem[j][k]==' '){
						ht+=temp+spac;
						temp=0;
						spac=i;
					}
				}
				ht+=temp+spac;
				if (ht>x){
					val=0;
					break;
				}
			}
			if (vt*i>y)val=0;
			if (val==1)best=i;
		}
		if (best==-1)printf ("No solution\n");
		else printf ("%d\n",best);
	}
}