#include<bits/stdc++.h>
using namespace std;

int data[55][55];

#define MAXX(a,b) (a>b) ? (a) : (b)

int main()
{
	long long has;
	int tc,n,m;
	scanf("%d",&tc);
	while(tc--){
		has = 0;
		scanf("%d%d",&n,&m);
		for(int i = 0 ; i < n ; i ++){
			for(int  j = 0 ; j < m ; j ++){
				scanf("%d",&data[i][j]);
			}
		}
		
		for(int i = 0 ; i < n ; i ++){
			for(int  j = 0 ; j < m ; j ++){
				//atas
				if(data[i][j]==0) continue;
				has++;
				if(i==0){
					has += data[i][j];
				}
				else{
					has += MAXX(data[i][j]-data[i-1][j],0);
				}
				//bawah
				if(i==n-1) has += data[i][j];
				else{
					has += MAXX(data[i][j]-data[i+1][j],0);
				}
				//kiri
				if(j==0) has += data[i][j];
				else{
					has += MAXX(data[i][j]-data[i][j-1],0);
				}
				//kanan
				if(j==m-1) has += data[i][j];
				else{
					has += MAXX(data[i][j]-data[i][j+1],0);
				}
			}
		}
		printf("%lld\n",has);
	}
	return 0;
}

