#include<bits/stdc++.h>
using namespace std;
char rem[300005];
int main(){
	while (scanf("%s",rem)!=EOF){
		int l=strlen(rem);
		int x=l/3;
		vector<int>ans;
		for (int i=3;i<l;i++){
			if (x>0&&rem[i-3]==rem[i-2]&&rem[i-1]==rem[i]&&rem[i-2]!=rem[i]){
				rem[i-1]=(rem[i]-'0')^1+'0';
				rem[i-2]=(rem[i-2]-'0')^1+'0';
				x--;
				ans.push_back(i-1);
			}
		}
		for (int i=1;i<l-1&&x>0;i++){
			if (rem[i]==rem[i-1]&&x>0){
				rem[i]=(rem[i]-'0')^1+'0';
				rem[i+1]=(rem[i+1]-'0')^1+'0';
				x--;
				ans.push_back(i);
			}
		}
		printf ("%d\n",ans.size());
		if (ans.size()>0){
			for (int i=0;i<ans.size();i++){
				if (i>0)printf (" ");
				printf ("%d",ans[i]+1);
			}
			printf ("\n");
		}
	}
}