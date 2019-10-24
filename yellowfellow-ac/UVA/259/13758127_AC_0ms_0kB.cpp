#include <bits/stdc++.h>
using namespace std;
int shift;
int node[250];
int color[250];
int vis[250];
int match[250];
vector<int>con[250];
void bip(int x, int c){
	color[x]=c;
	vis[x]=1;
	for (int i=0;i<con[x].size();i++){
		if (vis[con[x][i]]==0){
			bip(con[x][i],c^1);
		}
	}
}
vector<int>hop[250];
stack<int>eval;
void bfs(){
	queue<int>q;
	for (int i=0;i<250;i++){
		hop[i].clear();
		vis[i]=0;
		if (color[i]==0&&con[i].size()!=0&&match[i]==-1){
			q.push(i);
		}
	}
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			int node=q.front();
			q.pop();
			if (vis[node]==1)continue;
			vis[node]=1;
			if (color[node]==1&&match[node]==-1){
				eval.push(node);
				continue;
			}
			if (color[node]==1){
				hop[match[node]].push_back(node);
				q.push(match[node]);
			}
			else{
				for (int j=0;j<con[node].size();j++){
					if (vis[con[node][j]]==0){
						hop[con[node][j]].push_back(node);
						q.push(con[node][j]);
					}
				}
			}
		}
	}
	for (int i=0;i<250;i++){
		vis[i]=0;
	}
}
int dfs(int x){
	vis[x]=1;
	if (color[x]==0&&match[x]==-1){
		return 1;
	}
	for (int i=0;i<hop[x].size();i++){
		int ret=0;
		if (vis[hop[x][i]]==0){
			ret=dfs(hop[x][i]);
		}
		if (ret==1){
			if (color[x]==1){
				match[x]=hop[x][i];
				match[hop[x][i]]=x;
			}
			return 1;
		}
	}
	return 0;
}
int main(){
	shift=26*9;
	char rem[50];
	rem[0]='\0';
	while (scanf("%[^\n]",&rem)!=EOF){
		getchar();
		int type=rem[0]-'A';
		int coun=rem[1]-'0';
		int l=strlen(rem);
		for (int i=0;i<250;i++){
			con[i].clear();
			match[i]=-1;
			vis[i]=0;
			color[i]=0;
		}
		for (int i=3;i<l;i++){
			if (rem[i]>='0'&&rem[i]<='9'){
				for (int j=0;j<coun;j++){
					con[j+type*9].push_back(rem[i]-'0'+shift);
					con[rem[i]-'0'+shift].push_back(j+type*9);
				}
			}
		}
		while (strlen(rem)!=0){
			rem[0]='\0';
			scanf("%[^\n]",rem);
			getchar();
			if (strlen(rem)==0){
				break;
			}
			type=rem[0]-'A';
			coun=rem[1]-'0';
			l=strlen(rem);
			for (int i=3;i<l;i++){
				if (rem[i]>='0'&&rem[i]<='9'){
					for (int j=0;j<coun;j++){
						con[j+type*9].push_back(rem[i]-'0'+shift);
						con[rem[i]-'0'+shift].push_back(j+type*9);
					}
				}
			}
		}
		for (int i=0;i<shift;i++){
			if (vis[i]==0&&con[i].size()!=0){
				bip(i,0);
			}
		}
		while (1<2){
			bfs();
			if (eval.empty())break;
			while (!eval.empty()){
				dfs(eval.top());
				eval.pop();
			}
		}
		int check=1;
		for (int i=0;i<shift;i++){
			if (con[i].size()!=0&&match[i]==-1){
				check=0;
				break;
			}
		}
		if (check==0)printf ("!\n");
		else{
			for (int i=shift;i<shift+10;i++){
				if (match[i]==-1)printf ("_");
				else{
					int cnt=0;
					int tmp=match[i];
					while (tmp>=9){
						tmp-=9;
						cnt++;
					}
					printf ("%c",cnt+'A');
				}
			}
			printf ("\n");
		}
	}
}