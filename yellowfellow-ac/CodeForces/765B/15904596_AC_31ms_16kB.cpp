#include<bits/stdc++.h>
using namespace std;

int cnt[35];
int ix[35];
int main()
{
	string S;
	cin>>S;
	int maxi=0;
	memset(ix, -1, sizeof(ix));
	for(int a=0;a<S.length();a++)
	{
		maxi=max(maxi, S[a]-'a');
		if(ix[S[a]-'a']==-1) ix[S[a]-'a']=a;
		cnt[S[a]-'a']++;
	}
	bool check=1;
	for(int a=0;a<=maxi;a++)
	{
		if(cnt[a]==0||(a>0&&ix[a]<ix[a-1])) check=0;
	}
	if(check) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	return 0;
}