#include <bits/stdc++.h>
using namespace std;
struct trie{
	struct trie* next[26];
};
int serc(trie *cur, const char* rem, int idx, int mode){
	if (rem[idx]=='\0'){
		return 1;
	}
	if (cur->next[rem[idx]-'A']==NULL){
		if (mode==1){
			return 0;
		}
		trie *nnode = (trie*)malloc(sizeof(trie));
		for (int i=0;i<26;i++){
			nnode->next[i]=NULL;
		}
		cur->next[rem[idx]-'A']=nnode;
	}
	return serc(cur->next[rem[idx]-'A'],rem,idx+1,mode);
}
char rem[500005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int rprem[n];
	int cprem[n];
	scanf("%s",rem);
	for (int i=0;i<n;i++){
		rprem[rem[i]-'A']=i;
		cprem[i]=i;
	}
	trie *head = (trie*)malloc(sizeof(trie));
	for (int i=0;i<26;i++){
		head->next[i]=NULL;
	}
	for (int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		if (a==1){
			scanf("%s",rem);
			int l=strlen(rem);
			for (int i=0;i<l;i++){
				rem[i]=cprem[rem[i]-'A']+'A';
			}
			serc(head,rem,0,0);
		}
		else if (a==2){
			int temp[n];
			for (int i=0;i<n;i++){
				temp[i]=rprem[cprem[i]];
			}
			for (int i=0;i<n;i++){
				cprem[i]=temp[i];
			}
		}
		else if (a==3){
			scanf("%s",rem);
			int l=strlen(rem);
			for (int i=0;i<l;i++){
				rem[i]=cprem[rem[i]-'A']+'A';
			}
			if (serc(head,rem,0,1)==1){
				printf ("YES\n");
			}
			else printf ("NO\n");
		}
	}	
}