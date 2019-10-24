#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trie{
	int cnt;
	int las;
	struct trie* next[26];
};
typedef struct trie trie;

void add(trie* now, const char* str, int idx, int phase){
	if (now->las<phase){
		now->las=phase;
		now->cnt++;
	}
	if (str[idx]=='\0'){
		return;
	}
	int t=str[idx]-'a';
	if (now->next[t]==NULL){
		trie* node=(trie*)malloc(sizeof(trie));
		node->cnt=0;
		node->las=0;
		for (int i=0;i<26;i++){
			node->next[i]=NULL;
		}
		now->next[t]=node;
	}
	add(now->next[t],str,idx+1,phase);
}

int query(trie* now, const char* str, int idx){
	if (str[idx]=='\0'){
		return now->cnt;
	}
	int t=str[idx]-'a';
	if (now->next[t]!=NULL){
		return query(now->next[t],str,idx+1);
	}
	return 0;
}
char rem[25];
int main(){
	int n;
	trie* head=(trie*)malloc(sizeof(trie));
	head->cnt=0;
	head->las=0;
	for (int i=0;i<26;i++){
		head->next[i]=NULL;
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",rem);
		int l=strlen(rem);
		for (int j=0;j<l;j++){
			add(head,rem,j,i+1);
		}
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		scanf("%s",rem);
		printf ("%d\n",query(head,rem,0));
	}
}