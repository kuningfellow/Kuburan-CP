//UVA 10191 Longest Nap
#include <bits/stdc++.h>
using namespace std;
struct data{
	int cor;
	int flag;
	bool operator<(const data& a)const{
		if (cor!=a.cor)return cor<a.cor;
		return flag<a.flag;
	}
};
int main(){
	int n,kas=1;
	char rem[50000];
	while (scanf("%d",&n)!=EOF){
		getchar();
		int q=n;
		data ar[2*n];
		int idx=0;
		while (q--){
			scanf("%[^\n]",rem);
			getchar();
			int m=((rem[0]-'0')*10+(rem[1]-'0'))*60+(rem[3]-'0')*10+(rem[4]-'0');
			ar[idx].cor=m;
			ar[idx++].flag=1;
			m=((rem[6]-'0')*10+(rem[7]-'0'))*60+(rem[9]-'0')*10+(rem[10]-'0');
			ar[idx].cor=m;
			ar[idx++].flag=0;
		}
		sort(ar,ar+n*2);
		int best=0;
		int tmp=0;
		int prev=10*60;
		stack<int>st;
		for (int i=0;i<n*2;i++){
			if (ar[i].flag==1){
				if (best<ar[i].cor-prev&&st.size()==0){
					tmp=prev;
					best=ar[i].cor-prev;
				}
				st.push(1);
			}
			else{
				st.pop();
				prev=ar[i].cor;
			}
		}
		if (best<18*60-prev){
			tmp=prev;
			best=18*60-prev;
		}
		int d=0;
		while (best>=60){
			d++;
			best-=60;
		}
		int h=0,m=0;
		while (tmp>=60){
			h++;
			tmp-=60;
		}
		m=tmp;
		printf ("Day #%d: the longest nap starts at %02d:%02d and will last for ",kas++,h,m);
		if (d!=0){
			printf ("%d hours and %d minutes.\n",d,best);
		}
		else{
			printf ("%d minutes.\n",best);
		}
	}
}