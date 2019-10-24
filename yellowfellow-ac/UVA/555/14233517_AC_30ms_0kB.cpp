//UVA 555 Bridge Hands
#include <bits/stdc++.h>
using namespace std;
int ord(char num){
	if (num>='2'&&num<='9')return num-'0';
	else if (num=='T')return 10;
	else if (num=='J')return 11;
	else if (num=='Q')return 12;
	else if (num=='K')return 13;
	else if (num=='A')return 14;
}
int ord2(char suit){
	if (suit=='C')return 1;
	else if (suit=='D')return 2;
	else if (suit=='S')return 3;
	else if (suit=='H')return 4;
}
struct card{
	char num;
	char suit;
	bool operator<(const card& a)const{
		if (suit!=a.suit)return ord2(suit)<ord2(a.suit);
		else return ord(num)<ord(a.num);
	}
};
int main(){
	while (1<2){
		char rem[4];
		char ram[500];
		scanf("%s",rem);
		if (rem[0]=='#')break;
		vector<card>hand[4];
		int turn;
		card dum;
		if (rem[0]=='N')turn=3;
		else if (rem[0]=='E')turn=0;
		else if (rem[0]=='S')turn=1;
		else if (rem[0]=='W')turn=2;
		while (hand[0].size()+hand[1].size()+hand[2].size()+hand[3].size()<52){
			scanf("%s",ram);
			int l=strlen(ram);
			for (int i=0;i<l;i+=2){
				dum.suit=ram[i];
				dum.num=ram[i+1];
				hand[turn].push_back(dum);
				turn=(turn+1)%4;
			}
		}
		for (int i=0;i<4;i++){
			sort(hand[i].begin(),hand[i].end());
			if (i==0)printf ("S:");
			else if (i==1)printf ("W:");
			else if (i==2)printf ("N:");
			else if (i==3)printf ("E:");
			for (int j=0;j<13;j++){
				printf (" %c%c",hand[i][j].suit,hand[i][j].num);
			}
			printf ("\n");
		}
	}
}