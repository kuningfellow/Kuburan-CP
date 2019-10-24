#include <bits/stdc++.h>
using namespace std;
struct trie{
	int flag;
	int cnt;
	struct trie* next[10];
};
typedef struct trie trie;
int val;
void add(trie* now, const char* str, int idx){
	if (now->cnt>0&&now->flag==1){
		val=0;
	}
	now->cnt++;
	if (str[idx]=='\0'){
		if (now->cnt>1){
			val=0;
		}
		now->flag=1;
		now->cnt++;
		return;
	}
	int t=str[idx]-'a';
	if (now->next[t]==NULL){
		trie* node=(trie*)malloc(sizeof(trie));
		node->cnt=0;
		node->flag=0;
		for (int i=0;i<10;i++){
			node->next[i]=NULL;
		}
		now->next[t]=node;
	}
	add(now->next[t],str,idx+1);
}
int main(){
	trie* head=(trie*)malloc(sizeof(trie));
	head->cnt=0;
	head->flag=0;
	for (int i=0;i<10;i++){
		head->next[i]=NULL;
	}
	int n;
	scanf("%d",&n);
	val=1;
	char rem[100];
	for (int i=0;i<n;i++){
		scanf("%s",rem);
		if (val==1){
			add(head,rem,0);
			if (val==0){
				printf ("BAD SET\n%s\n",rem);
				break;
			}
		}
	}
	if (val==1){
		printf ("GOOD SET\n");
	}
}