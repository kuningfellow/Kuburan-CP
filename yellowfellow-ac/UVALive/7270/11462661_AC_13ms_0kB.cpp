#include<bits/stdc++.h>
using namespace std;

int main()
{
	int data;
	while(cin>>data)
	{
		char cmd;
		int num, pos;
		int count=0;
		for(int a=0;a<data;a++)
		{
			cin>>cmd;
			if(cmd!='S')
			{
				cin>>num;
				if(num==1) count++;
			}
			else if(cmd=='S') count++;
		}
		cout<<count<<endl;
	}
}