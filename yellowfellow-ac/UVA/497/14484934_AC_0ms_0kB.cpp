//UVA 497 Strategic Defense Initiative
#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	int ar[50000];
	int lis[50000];
	int bac[50000];
	while (tc--){
		int fir=1;
		int siz=0;
		int best=0;
		char rem[500];
		while (1<2){
			rem[0]='\0';
			scanf("%[^\n]",rem);
			getchar();
			if (strlen(rem)==0&&fir==0)break;
			else if (strlen(rem)!=0){
				fir=0;
				int tmp=0;
				for (int i=0;i<strlen(rem);i++){
					tmp=tmp*10+rem[i]-'0';
				}
				ar[siz++]=tmp;
			}
		}
		best=1;
		lis[1]=0;
		lis[0]=-1;
		bac[0]=-1;
		for (int i=1;i<siz;i++){
			int l=0,r=best,mid,ans=0;
			while (l<=r){
				mid=(l+r)/2;
				if (ar[lis[mid]]<ar[i]){
					ans=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			bac[i]=lis[ans];
			lis[ans+1]=i;
			best=max(best,ans+1);
		}
		printf ("Max hits: %d\n",best);
		stack<int>out;
		int pos=lis[best];
		while (pos!=-1){
			out.push(pos);
			pos=bac[pos];
		}
		while (!out.empty()){
			printf("%d\n",ar[out.top()]);
			out.pop();
		}
		if (tc!=0)printf("\n");
	}
}