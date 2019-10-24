#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

map <LL, int> hash2, hash1;
vector <int> adj[100001];
int indeg[100001];
LL de[100001];
int lis[100001];

int main(){
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	LL A, B;
	int h=1;
	for(int i=1; i<=n; i++){
		indeg[i]=0;
	}
	
	for(int i=0; i<m; i++){
		scanf("%lld%lld", &A, &B);
		if(hash1.count(A)==0){
			hash1[A]=h;
			de[h]=A;
			h++;
		}
		if(hash1.count(B)==0){
			hash1[B]=h;
			de[h]=B;
			h++;
		}
		adj[hash1[B]].push_back(hash1[A]);
		indeg[hash1[A]]++;
	}
	
	queue <int> q;
	
	for(int i=1; i<=n; i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	int rnk=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		hash2[now]=rnk;
		rnk++;
		for(int i=0; i<adj[now].size(); i++){
			indeg[adj[now][i]]--;
			if(indeg[adj[now][i]]==0){
				q.push(adj[now][i]);
			}
		}
	}
	
	
	
	vector <int> soal;
	LL temp;
	int ans=0;
	
	for(int i=0; i<n; i++){
		scanf("%lld", &temp);
		if(hash1.count(temp)==1){
			soal.push_back(hash2[hash1[temp]]);
		}
	}
	lis[0]=(-1)^(1<<31);
	int MAXL=0;
	for (int i=0;i<soal.size();i++){
		int l=0;
		int r=MAXL;
		int fin=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (lis[mid]>soal[i]){
				l=mid+1;
				fin=mid;
			}
			else{
				r=mid-1;
			}
		}
		lis[fin+1]=soal[i];
		MAXL=max(MAXL,fin+1);
	}
	printf("%d\n",(n-MAXL)*2);
	
	return 0;
}