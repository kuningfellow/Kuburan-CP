#include<bits/stdc++.h>
using namespace std;

string forbid="13";
string S;

bool checker()
{
	if(S.size() < 2) return 0;
	for(int a=0;a<=S.size()-2;a++)
	{
		if(S.substr(a, 2)==forbid)
		{
			S.erase(a, 2);
			return 1;
		}
	}
	return 0;
}

int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	
	cin>>S;
	int mov=0;
	while(checker())
	{
		mov++;
	}
	printf("%d", mov);
}