#include <bits/stdc++.h>
using namespace std;
vector<int>con[40010];
vector<int>nlist[40010];
vector<int>dag;
vector<int>component[40010];
stack<int>tarst;
int state[40010],num[40010],low[40010],vis[40010],take[40010];
int lv;
char land[105][105];
int mark[105][105];
int r,c;
int cnt,perp,neg,phase;
int valid;
bool inrange(int x, int y){
	if (x>=0&&x<r&&y>=0&&y<c)return 1;
	return 0;
}
int check(int x, int y, int dir){
	int dx=0,dy=0,found=-1;
	if (dir==0)dx++;
	else if (dir==1)dx--;
	else if (dir==2)dy++;
	else if (dir==3)dy--;
	for (int i=1;inrange(x+dx*i,y+dy*i);i++){
		if (land[x+dx*i][y+dy*i]=='#')break;
		if (land[x+dx*i][y+dy*i]=='T'){
			found=mark[x+dx*i][y+dy*i];
			break;
		}
	}
	return found;
}
int nonono(int x){
	if (x<neg)return x+neg;
	return x-neg;
}
void construct(){
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			mark[i][j]=-1;
			if (land[i][j]=='T')mark[i][j]=cnt++;
		}
	}
	perp=cnt;
	neg=cnt*2;
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			if (land[i][j]=='T'){
				int res[4];
				for (int k=0;k<4;k++)res[k]=check(i,j,k);
				if ((res[0]!=-1&&res[1]!=-1)||(res[2]!=-1&&res[3]!=-1)){
					valid=0;
					break;
				}
				int v=mark[i][j];
				if (res[0]!=-1)con[v].push_back(v+neg);
				else if (res[1]!=-1)con[v+neg].push_back(v);
				if (res[2]!=-1)con[v+perp].push_back(v+perp+neg);
				else if (res[3]!=-1)con[v+perp+neg].push_back(v+perp);
			}
			else if (land[i][j]=='n'){
				int res[4];
				for (int k=0;k<4;k++)res[k]=check(i,j,k);
				if (res[0]+res[1]+res[2]+res[3]==-4){
					valid=0;
					break;
				}
				int vert=-1,hori=-1;
				if (res[0]!=-1)vert=res[0]+neg;
				else if (res[1]!=-1)vert=res[1];
				if (res[2]!=-1)hori=res[2]+perp+neg;
				else if (res[3]!=-1)hori=res[3]+perp;
				if (vert==-1)con[nonono(hori)].push_back(hori);
				else if (hori==-1)con[nonono(vert)].push_back(vert);
				else{
					con[nonono(hori)].push_back(vert);
					con[nonono(vert)].push_back(hori);
				}
			}
		}
		if (valid==0)break;
	}
}
void tarjan(int x){
	vis[x]=1;
	num[x]=low[x]=lv++;
	tarst.push(x);
	for (int i=0;i<con[x].size();i++){
		if (num[con[x][i]]==-1){
			tarjan(con[x][i]);
		}
		if (vis[con[x][i]]==1){
			low[x]=min(low[x],low[con[x][i]]);
		}
	}
	if (low[x]==num[x]){
		dag.push_back(x);
		phase++;
		while (1<2){
			int v=tarst.top();
			low[v]=x;
			tarst.pop();
			vis[v]=0;
			if (v<neg&&take[v+neg]==phase){
				valid=0;
				break;
			}
			if (v>=neg&&take[v-neg]==phase){
				valid=0;
				break;
			}
			take[v]=phase;
			if (v==x)break;
		}
	}
}
void newgraph(){
	int a,b;
	for (int i=0;i<cnt*4;i++){
		take[i]=0;
	}
	for (int i=0;i<cnt*4;i++){
		vis[i]=0;
		state[i]=-1;
		a=low[i];
		component[a].push_back(i);
		for (int j=0;j<con[i].size();j++){
			b=low[con[i][j]];
			if (a==b)continue;
			nlist[b].push_back(a);
			take[a]++;
		}
	}
}
void solve(){
	queue<pair<int,int> >q;
	for (int i=0;i<dag.size();i++){
		if (take[dag[i]]==0){
			q.push(pair<int,int>(dag[i],1));
		}
	}
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			int v=q.front().first;
			int col=q.front().second;
			q.pop();
			for (int j=0;j<component[v].size();j++){
				int p=component[v][j];
				if (p>=neg)p-=neg;
				if (col==1&&state[p]!=-1&&state[p]!=col){
					col=0;
				}
			}
			for (int j=0;j<component[v].size();j++){
				int p=component[v][j];
				if (p>=neg)p-=neg;
				if (state[p]==-1){
					if (component[v][j]<neg)state[p]=col;
					else state[p]=col^1;
				}
			}
			for (int j=0;j<nlist[v].size();j++){
				take[nlist[v][j]]--;
				if (take[nlist[v][j]]==0){
					q.push(pair<int,int>(nlist[v][j],1));
				}
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>r>>c;
	for (int i=0;i<r;i++){
		scanf("%s",land[i]);
	}
	valid=1;
	construct();
	int coun=0;
	for (int i=0;i<cnt*4;i++){
		num[i]=-1;
		low[i]=-1;
		take[i]=0;
	}
	for (int i=0;i<cnt*4;i++){
		if (num[i]==-1){
			tarjan(i);
		}
	}
	newgraph();
	solve();
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			if (land[i][j]=='T'){
				int p=mark[i][j];
				if (state[p]==1){
					if (state[p+perp]==1){
						printf ("2");
					}
					else printf ("1");
				}
				else{
					if (state[p+perp]==1){
						printf ("3");
					}
					else printf ("4");
				}
			}
			else printf ("%c",land[i][j]);
		}
		printf ("\n");
	}
}