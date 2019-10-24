#include <bits/stdc++.h>
using namespace std;
int par[50000];
int finpar(int x){
	if (par[x]==x){
		return x;
	}
	return par[x]=finpar(par[x]);
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		for (int i=0;i<=n;i++){
			par[i]=i;
		}
		int fir=1;
		int succ=0;
		int phail=0;
		while (1<2){
			char rem[5000];
			rem[0]='\0';
			if (fir==1){
				while (strlen(rem)==0){
					scanf("%[^\n]",rem);
					getchar();
				}
			}
			else{
				scanf("%[^\n]",rem);
				getchar();
				if (strlen(rem)==0)break;
			}
			fir=0;
			int a=0,b=0;
			int* ptr=&a;
			int mode=0;
			int temp=0;
			if (rem[0]=='q')mode=1;
			for (int i=1;i<strlen(rem);i++){
				if (rem[i]>='0'&&rem[i]<='9'){
					temp=temp*10+rem[i]-'0';
				}
				else{
					if (temp!=0){
						*ptr=temp;
						ptr=&b;
					}
					temp=0;
				}
			}
			if (temp!=0){
				*ptr=temp;
			}
			if (mode==0){
				par[finpar(a)]=finpar(b);
			}
			else{
				if (finpar(a)==finpar(b)){
					succ++;
				}
				else{
					phail++;
				}
			}
		}
		printf ("%d,%d\n",succ,phail);
		if (tc!=0)printf ("\n");
	}
}