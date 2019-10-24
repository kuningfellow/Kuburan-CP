#include<bits/stdc++.h>
using namespace std;

map<string, int>  isi1, isi2;

int main()
{
	int n;
	cin>>n;
	string awal;
	cin>>awal;
	bool check=0;
	for(int a=0;a<n;a++)
	{
		string S;
		cin>>S;
		isi2[S.substr(S.length()-3, 3)]++;
		isi1[S.substr(0, 3)]++;
	}
	if(isi1[awal]==isi2[awal]) check=1;
	if(check) cout<<"home";
	else cout<<"contest";
	cout<<endl;
	return 0;
}