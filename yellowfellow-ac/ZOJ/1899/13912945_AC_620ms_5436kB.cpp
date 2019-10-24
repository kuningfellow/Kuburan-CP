#include <bits/stdc++.h>
using namespace std;
struct trie{
	int coun;
	struct trie* next[256];
};
typedef struct trie trie;
int tot;
void add(trie* now, const char* str, int idx){
	if (str[idx]=='\0'){
		now->coun++;
		return;
	}
	int t=(int)str[idx];
	if (now->next[t]==NULL){
		trie* node=(trie*)malloc(sizeof(trie));
		node->coun=0;
		for (int i=0;i<256;i++){
			node->next[i]=NULL;
		}
		now->next[t]=node;
	}
	add(now->next[t],str,idx+1);
}
char rem[500];
void traverser(trie* now, int idx){
	if (now->coun!=0){
		for (int i=1;i<=idx;i++){
			printf ("%c",rem[i]);
		}
		printf (" %.4f\n",(double)now->coun*100/tot);
	}
	for (int i=0;i<256;i++){
		if (now->next[i]!=NULL){
			rem[idx+1]=i;
			traverser(now->next[i],idx+1);
		}
	}
	free(now);
}
int main(){
	int mimi=1;
	rem[0]='0';
	char ram[500];
	while (1<2){
		ram[0]='\0';
		tot=0;
		int fir=1;
		int done=0;
		trie* head=(trie*)malloc(sizeof(trie));
		head->coun=0;
		for (int i=0;i<256;i++){
			head->next[i]=NULL;
		}
		while (fir==1||strlen(ram)!=0){
			ram[0]='\0';
			if (scanf("%[^\n]",ram)==EOF){
				done=1;
			}
			getchar();
			fir=0;
			if (done==1)break;
			if (strlen(ram)!=0){
				add(head,ram,0);
				tot++;
			}
			else{
				break;
			}
		}
		if (mimi==0)printf ("\n");
		traverser(head,0);
		mimi=0;
		if (done)break;
	}
}