#include <bits/stdc++.h>
using namespace std;
map<string,int>clubh;
map<string,int>personh;
map<string,int>partyh;
map<int,string>serpon;
map<int,string>bluc;
int flow[3005][3005];
int vis[3005];
int bac[3005];
int node;
void bfs(){
	for (int i=0;i<=node;i++){
		vis[i]=0;
	}
	queue<int>q;
	q.push(0);
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			for (int j=0;j<=node;j++){
				if (flow[q.front()][j]>0&&vis[j]==0){
					vis[j]=1;
					bac[j]=q.front();
					q.push(j);
				}
			}
			q.pop();
		}
	}
}
int maxflow(){
	int ret=0;
	while (1<2){
		bfs();
		if (vis[node]==0)break;
		for (int i=0;i<=node;i++){
			vis[i]=0;
		}
		int maxi=(1<<28);
		int pos=node;
		while (pos!=0){
			maxi=min(maxi,flow[bac[pos]][pos]);
			pos=bac[pos];
		}
		pos=node;
		while (pos!=0){
			flow[bac[pos]][pos]-=maxi;
			flow[pos][bac[pos]]+=maxi;
			pos=bac[pos];
		}
		ret+=maxi;
	}
	return ret;
}
int main(){
	int tc;
	cin>>tc;
	getchar();
	while (tc--){
		clubh.clear();
		personh.clear();
		partyh.clear();
		serpon.clear();
		bluc.clear();
		int fir=1;
		int clubc=1;
		int personc=1;
		int partyc=1;
		char rem[1005][85];
		vector<int>ppl;
		vector<int>clubs;
		int j=0;
		while (fir||strlen(rem[j])!=0){
			rem[j][0]='\0';
			scanf("%[^\n]",rem[j]);
			getchar();
			if (strlen(rem[j])!=0){
				fir=0;
				string ram="";
				int phase=0;
				int l=strlen(rem[j]);
				for (int i=0;i<l;i++){
					if (rem[j][i]!=' '){
						ram+=rem[j][i];
					}
					else{
						if (phase==0){
							if (personh[ram]==0){
								ppl.push_back(personc);
								personh[ram]=personc;
								serpon[personc]=ram;
								personc++;
							}
						}
						else if (phase==1){
							if (partyh[ram]==0){
								partyh[ram]=partyc;
								partyc++;
							}
						}
						else if (phase>1){
							if (clubh[ram]==0){
								clubs.push_back(clubc);
								clubh[ram]=clubc;
								bluc[clubc]=ram;
								clubc++;
							}
						}
						ram="";
						phase++;
					}
				}
				if (clubh[ram]==0&&phase>1){
					clubs.push_back(clubc);
					clubh[ram]=clubc;
					bluc[clubc]=ram;
					clubc++;
				}
				else if (partyh[ram]==0&&phase==1){
					partyh[ram]=partyc;
					partyc++;
				}
				j++;
				rem[j][0]=' ';
				rem[j][1]='\0';
			}
			else{
				if (fir==1)continue;
				break;
			}
		}
		node=personc+clubc+partyc-3+1;
		for (int i=0;i<=node;i++){
			for (int j=0;j<=node;j++){
				flow[i][j]=0;
			}
		}
		int lim=(clubc)/2-1;
		for (int i=0;i<j;i++){
			int l=strlen(rem[i]);
			string ram="";
			int phase=0;
			int person;
			int party;
			for (int j=0;j<l;j++){
				if (rem[i][j]!=' '){
					ram+=rem[i][j];
				}
				else{
					if (phase==0){
						person=personh[ram];
					}
					else if (phase==1){
						party=partyh[ram]+personc-1;
						flow[person][party]=1;
						flow[party][node]=lim;
					}
					else{
						flow[0][clubh[ram]+personc+partyc-2]=1;
						flow[clubh[ram]+personc+partyc-2][person]=1;
					}
					phase++;
					ram="";
				}
			}
			if (phase>1){
				flow[0][clubh[ram]+personc+partyc-2]=1;
				flow[clubh[ram]+personc+partyc-2][person]=1;
			}
			else if (phase==1){
				party=partyh[ram]+personc-1;
				flow[person][party]=1;
				flow[party][node]=lim;
			}
		}
		int sum=maxflow();
		if (sum<clubc-1){
			printf ("Impossible.\n");
		}
		else{
			for (int i=0;i<ppl.size();i++){
				for (int j=0;j<clubs.size();j++){
					if (flow[ppl[i]][clubs[j]+personc+partyc-2]==1){
						cout<<serpon[ppl[i]]<<" "<<bluc[clubs[j]]<<endl;
					}
				}
			}
		}
		if (tc!=0)printf ("\n");
	}
}