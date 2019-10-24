//UVA 10315 Poker Hands
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >hand[2];
int sflush(int h){
	int ret=-1;
	for (int i=1;i<5;i++){
		if (hand[h][0].first+i!=hand[h][i].first||hand[h][0].second!=hand[h][i].second){
			return -1;
		}
		ret=max(ret,hand[h][i].first);
	}
	return ret;
}
int fokind(int h){
	int ret=-1;
	int cnt[15];
	for (int i=0;i<15;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].first]++;
	}
	for (int i=0;i<15;i++){
		if (cnt[i]==4)ret=i;
	}
	return ret;
}
int fhouse(int h){
	int ret=-1;
	int cnt[15];
	for (int i=0;i<15;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].first]++;
	}
	int three=-1,two=-1;
	for (int i=0;i<15;i++){
		if (cnt[i]==3){
			three=i;
		}
		if (cnt[i]==2){
			two=i;
		}
	}
	if (three>0&&two>0)return three;
	return -1;
}
int flush(int h){
	int ret=-1;
	int cnt[5];
	for (int i=0;i<5;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].second]++;
	}
	for (int i=0;i<5;i++){
		if (cnt[i]==5)ret=1;
	}
	return ret;
}
int strait(int h){
	int maxi=0;
	for (int i=1;i<5;i++){
		if (hand[h][0].first+i!=hand[h][i].first){
			return -1;
		}
		maxi=hand[h][0].first+i;
	}
	return maxi;
}
int threkind(int h){
	int ret=-1;
	int cnt[15];
	for (int i=0;i<15;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].first]++;
	}
	for (int i=0;i<15;i++){
		if (cnt[i]==3){
			ret=i;
		}
	}
	return ret;
}
int twopair(int h){
	int ret=-1;
	int cnt[15];
	int twos=0;
	int trail=0;
	for (int i=0;i<15;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].first]++;
	}
	int bef=0;
	for (int i=0;i<15;i++){
		if (cnt[i]==2){
			twos++;
			bef=ret;
			ret=i;
		}
		if (cnt[i]==1){
			trail=i;
		}
	}
	if (twos==2)return ret*10000+bef*100+trail;
	return -1;
}
int pairs(int h){
	int ret=-1;
	int cnt[15];
	for (int i=0;i<15;i++)cnt[i]=0;
	for (int i=0;i<5;i++){
		cnt[hand[h][i].first]++;
	}
	vector<int>temp;
	for (int i=0;i<15;i++){
		if (cnt[i]==2){
			ret=i;
		}
		else if (cnt[i]==1){
			temp.push_back(i);
		}
	}
	if (ret==-1)return -1;
	sort(temp.begin(),temp.end());
	return ret*14*14*14+temp[2]*14*14+temp[1]*14+temp[0];
}
int highcard(){
	priority_queue<int>compa[2];
	int ret=0;
	for (int i=0;i<5;i++){
		compa[0].push(hand[0][i].first);
		compa[1].push(hand[1][i].first);
	}
	while (!compa[0].empty()&&!compa[1].empty()){
		if (compa[0].top()>compa[1].top()){
			ret=1;
			break;
		}
		else if (compa[0].top()<compa[1].top()){
			ret=-1;
			break;
		}
		compa[0].pop();
		compa[1].pop();
	}
	while (!compa[0].empty())compa[0].pop();
	while (!compa[1].empty())compa[1].pop();
	return ret;
}
int main(){
	char rem[500];
	while (scanf("%[^\n]",rem)!=EOF){
		getchar();
		hand[0].clear();
		hand[1].clear();
		for (int i=0;i<10;i++){
			int x=rem[i*3]-'0';
			if (rem[i*3]=='T')x=10;
			else if (rem[i*3]=='J')x=11;
			else if (rem[i*3]=='Q')x=12;
			else if (rem[i*3]=='K')x=13;
			else if (rem[i*3]=='A')x=14;
			int y;
			if (rem[i*3+1]=='C')y=1;
			else if (rem[i*3+1]=='D')y=2;
			else if (rem[i*3+1]=='H')y=3;
			else if (rem[i*3+1]=='S')y=4;
			if (i<5){
				hand[0].push_back(pair<int,int>(x,y));
			}
			else{
				hand[1].push_back(pair<int,int>(x,y));
			}
		}
		sort(hand[0].begin(),hand[0].end());
		sort(hand[1].begin(),hand[1].end());
		int phase0=sflush(0);
		int phase1=sflush(1);
		int win=0;
		if (phase0==-1&&phase1==-1){
			phase0=fokind(0);
			phase1=fokind(1);
			if (phase0==-1&&phase1==-1){
				phase0=fhouse(0);
				phase1=fhouse(1);
				if (phase0==-1&&phase1==-1){
					phase0=flush(0);
					phase1=flush(1);
					if (phase0==-1&&phase1==-1){
						phase0=strait(0);
						phase1=strait(1);
						if (phase0==-1&&phase1==-1){
							phase0=threkind(0);
							phase1=threkind(1);
							if (phase0==-1&&phase1==-1){
								phase0=twopair(0);
								phase1=twopair(1);
								if (phase0==-1&&phase1==-1){
									phase0=pairs(0);
									phase1=pairs(1);
									if (phase0==-1&&phase1==-1){
										win=highcard();
									}
									else if (phase0>phase1)win=1;
									else if (phase0<phase1)win=-1;
									else win=0;
								}
								else if (phase0>phase1)win=1;
								else if (phase0<phase1)win=-1;
								else win=0;
							}
							else if (phase0>phase1)win=1;
							else if (phase0<phase1)win=-1;
							else{
								win=0;
							}
						}
						else if (phase0>phase1)win=1;
						else if (phase0<phase1)win=-1;
						else win=0;
					}
					else if (phase0>phase1)win=1;
					else if (phase0<phase1)win=-1;
					else win=highcard();
				}
				else if (phase0>phase1)win=1;
				else if (phase0<phase1)win=-1;
				else win=0;
			}
			else if (phase0>phase1)win=1;
			else if (phase0<phase1)win=-1;
			else win=0;
		}
		else if (phase0>phase1)win=1;
		else if (phase0<phase1)win=-1;
		else win=0;
		
		if (win==-1)printf ("White wins.\n");
		else if (win==0)printf ("Tie.\n");
		else if (win==1)printf ("Black wins.\n");
	}
}