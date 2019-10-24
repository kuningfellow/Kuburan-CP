//UVA 148 Anagram checker
#include <bits/stdc++.h>
using namespace std;
struct data{
	int cnt[26];
	bool valid(){
		for(int i=0;i<26;i++){
			if (cnt[i]<0)return 0;
		}
		return 1;
	}
	bool done(){
		for (int i=0;i<26;i++){
			if (cnt[i]!=0)return 0;
		}
		return 1;
	}
};
char rem[2001][21];
char ram[30];
data red[2001];
data cur;
int n;
vector<int>bak;
bool instr(int x){
	int l1=strlen(rem[x]);
	int kmp[l1];
	kmp[0]=0;
	int j=0;
	for (int i=1;i<l1;i++){
		while (j-1>=0&&rem[x][j]!=rem[x][i]){
			j=kmp[j-1];
		}
		if (rem[x][j]==rem[x][i])j++;
		kmp[i]=j;
	}
	j=0;
	int l2=strlen(ram);
	for (int i=0;i<l2;i++){
		while (j-1>=0&&rem[x][j]!=ram[i]){
			j=kmp[j-1];
		}
		if (rem[x][j]==ram[i])j++;
		if (j==l1&&(i+1==l2||ram[i+1]==' ')&&(i-l1<0||ram[i-l1]==' ')){
			return 1;
		}
		if (j==l1){
			j=kmp[j-1];
		}
	}
	return 0;
}
void serc(int x){
	if (cur.done()){
		printf("%s =",ram);
		for (int i=0;i<bak.size();i++){
			printf(" %s",rem[bak[i]]);
		}
		printf("\n");
		return;
	}
	if (x==n)return;
	for (int i=0;i<26;i++){
		cur.cnt[i]-=red[x].cnt[i];
	}
	bak.push_back(x);
	if (cur.valid()&&!instr(x)){
		serc(x+1);
	}
	bak.pop_back();
	for (int i=0;i<26;i++){
		cur.cnt[i]+=red[x].cnt[i];
	}
	serc(x+1);
}
int main(){
	while (1<2){
		scanf("%[^\n]",rem[n]);
		getchar();
		if (rem[n][0]=='#')break;
		int l=strlen(rem[n]);
		for (int i=0;i<26;i++)red[n].cnt[i]=0;
		for (int i=0;i<l;i++){
			red[n].cnt[rem[n][i]-'A']++;
		}
		n++;
	}
	while (1<2){
		scanf("%[^\n]",ram);
		getchar();
		if (ram[0]=='#')break;
		int l=strlen(ram);
		for (int i=0;i<26;i++)cur.cnt[i]=0;
		for (int i=0;i<l;i++){
			if (ram[i]!=' ')cur.cnt[ram[i]-'A']++;
		}
		serc(0);
	}
}