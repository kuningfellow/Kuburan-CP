//UVA 220 Othello
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >moves;
char rem[8][9];
int dir[8][2]={-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};
int prog(int x, int y, int d, int c, int mode){
	if (x>7||x<0||y<0||y>7)return 0;
	if (rem[x][y]=='-')return 0;
	int ret=0;
	if (c==0&&rem[x][y]=='B'){
		ret=1;
		ret|=prog(x+dir[d][0],y+dir[d][1],d,c,mode);
		if (ret==3&&mode==1)rem[x][y]='W';
		return ret;
	}
	else if (c==0&&rem[x][y]=='W'){
		return 2;
	}
	else if (c==1&&rem[x][y]=='W'){
		ret=1;
		ret|=prog(x+dir[d][0],y+dir[d][1],d,c,mode);
		if (ret==3&&mode==1)rem[x][y]='B';
		return ret;
	}
	else if (c==1&&rem[x][y]=='B'){
		return 2;
	}
}
int fin(int x, int y, int turn){
	int val=0;
	for (int i=0;i<8;i++){
		if (prog(x+dir[i][0],y+dir[i][1],i,turn,0)==3){
			val=1;
		}
	}
	return val;
}
void fill(int x, int y, int turn){
	if (turn==0)rem[x][y]='W';
	else rem[x][y]='B';
	for (int i=0;i<8;i++){
		prog(x+dir[i][0],y+dir[i][1],i,turn,1);
	}
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		for (int i=0;i<8;i++){
			scanf("%s",rem[i]);
		}
		char ram[50];
		scanf("%s",ram);
		int turn;
		if (ram[0]=='W')turn=0;
		else turn=1;
		while (1<2){
			moves.clear();
			scanf("%s",ram);
			for (int i=0;i<8;i++){
				for (int j=0;j<8;j++){
					if (rem[i][j]=='-'){
						if (fin(i,j,turn)){
							moves.push_back(pair<int,int>(i,j));
						}
					}
				}
			}
			if (ram[0]=='L'){
				if (moves.size()==0){
					printf ("No legal move.");
				}
				for (int i=0;i<moves.size();i++){
					if (i!=0)printf (" ");
					printf ("(%d,%d)",moves[i].first+1,moves[i].second+1);
				}
				printf ("\n");
			}
			else if (ram[0]=='M'){
				if (moves.size()==0){
					turn^=1;
				}
				fill(ram[1]-'0'-1,ram[2]-'0'-1,turn);
				turn^=1;
				int b=0,w=0;
				for (int i=0;i<8;i++){
					for (int j=0;j<8;j++){
						if (rem[i][j]=='B')b++;
						else if (rem[i][j]=='W')w++;
					}
				}
				printf ("Black - %2d White - %2d\n",b,w);
			}
			else if (ram[0]=='Q'){
				break;
			}
		}
		for (int i=0;i<8;i++){
			printf ("%s\n",rem[i]);
		}
		if (tc!=0)printf ("\n");
	}
}