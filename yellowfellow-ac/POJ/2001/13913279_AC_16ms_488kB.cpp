#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trie{
	int coun;
	struct trie* next[26];
};
typedef struct trie trie;
void add(trie* now, const char* str, int idx){
	now->coun++;
	if (str[idx]=='\0'){
		return;
	}
	int t=str[idx]-'a';
	if (now->next[t]==NULL){
		trie* node=(trie*)malloc(sizeof(trie));
		node->coun=0;
		for (int i=0;i<26;i++){
			node->next[i]=NULL;
		}
		now->next[t]=node;
	}
	add(now->next[t],str,idx+1);
}
char bac[25];
void traverse(trie* now, const char* str,int idx){
	if (str[idx]=='\0'){
		for (int i=1;i<=idx;i++){
			printf ("%c",bac[i]);
		}
		return;
	}
	if (now->coun==1){
		for (int i=1;i<=idx;i++){
			printf ("%c",bac[i]);
		}
		return;
	}
	int t=str[idx]-'a';
	bac[idx+1]=str[idx];
	traverse(now->next[t],str,idx+1);
}
int main(){
	int ix=0;
	trie* head=(trie*)malloc(sizeof(trie));
	head->coun=0;
	for (int i=0;i<26;i++){
		head->next[i]=NULL;
	}
	char rem[1005][25];
	while (scanf("%s",rem[ix])!=EOF){
		add(head,rem[ix],0);
		ix++;
	}
	for (int i=0;i<ix;i++){
		printf ("%s ",rem[i]);
		traverse(head,rem[i],0);
		printf ("\n");
	}	
}