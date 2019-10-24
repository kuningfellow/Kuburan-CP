//UVA 162 Beggar My Neighbour
#include <bits/stdc++.h>
using namespace std;
struct card{
	char num;
	char suit;
};
int main(){
	while (1<2){
		vector<card>cards;
		char rem[500];
		card dum;
		int done=0;
		while (cards.size()<52){
			scanf("%[^\n]",rem);
			getchar();
			if (rem[0]=='#'){
				done=1;
				break;
			}
			int l=strlen(rem);
			for (int i=0;i<l;i+=3){
				dum.suit=rem[i];
				dum.num=rem[i+1];
				cards.push_back(dum);
			}
		}
		if (done==1)break;
		queue<card>hand[2];
		for (int i=51;i>=0;i--){
			if (i%2==1)hand[0].push(cards[i]);
			else hand[1].push(cards[i]);
		}
		cards.clear();
		int turn=1;
		int winner=-1;
		while (1<2){
			if (hand[turn].empty()){
				winner=turn^1;
				break;
			}
			cards.push_back(hand[turn].front());
			hand[turn].pop();
			turn^=1;
			int loop=0;
			int c=cards[cards.size()-1].num;
			int combo=0;
			if (c=='J')combo=1;
			else if (c=='Q')combo=2;
			else if (c=='K')combo=3;
			else if (c=='A')combo=4;
			if (combo!=0)loop=1;
			while (combo>0){
				if (hand[turn].empty()){
					winner=turn^1;
					break;
				}
				cards.push_back(hand[turn].front());
				hand[turn].pop();
				combo--;
				c=cards[cards.size()-1].num;
				if (c=='J'){
					turn^=1;
					combo=1;
				}
				else if (c=='Q'){
					turn^=1;
					combo=2;
				}
				else if (c=='K'){
					turn^=1;
					combo=3;
				}
				else if (c=='A'){
					turn^=1;
					combo=4;
				}
			}
			if (winner!=-1)break;
			if (loop==1){
				turn^=1;
				for (int i=0;i<cards.size();i++){
					hand[turn].push(cards[i]);
				}
				cards.clear();
			}
		}
		printf ("%d%3d\n",winner+1,hand[winner].size());
	}
}