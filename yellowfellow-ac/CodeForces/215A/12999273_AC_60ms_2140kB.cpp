#include<bits/stdc++.h>
using namespace std;
int g1[55], g2[55];
int main()
{
	int data1, data2;
	scanf("%d", &data1);
	for(int a=0;a<data1;a++)
	{
		cin>>g1[a];
	}
	cin>>data2;
	for(int a=0;a<data2;a++)
	{
		cin>>g2[a];
	}
	int maxi=-1, num=0;
	for(int a=0;a<data1;a++)
	{
		for(int b=0;b<data2;b++)
		{
			if(g2[b]%g1[a]==0)
			{
				int tmp=g2[b]/g1[a];
				if(maxi < tmp)
				{
					maxi=tmp;
					num=1;
				}
				else if(maxi==tmp)
				{
					num++;
				}
			}
		}
	}
	cout<<num<<endl;
	return 0;
}