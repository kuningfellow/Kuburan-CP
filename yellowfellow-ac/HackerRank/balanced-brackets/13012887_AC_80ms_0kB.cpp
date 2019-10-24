#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int l;
		char rem[50000];
		scanf("%s",rem);
		l=strlen(rem);
		if (l%2==1){
			printf ("NO\n");
		}
		else{
			stack<char>s;
			for (int i=0;i<l;i++){
				if (!s.empty()&&((s.top()=='{'&&rem[i]=='}')||(s.top()=='('&&rem[i]==')')||(s.top()=='['&&rem[i]==']'))){
					s.pop();
				}
				else{
					s.push(rem[i]);
				}
			}
			if (s.empty())printf ("YES\n");
			else printf ("NO\n");
		}
	}
}