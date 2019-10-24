#include <iostream>
#include <stdlib.h>
#include <stdio.h>
struct mimi{
	int mimimi;
	struct mimi* mi[2];
};
typedef struct mimi mimi;
void sexy_mimi(mimi* now, const char* meme, int idx){
	if (meme[idx]=='\0'){
		now->mimimi++;
		return;
	}
	if (now->mi[meme[idx]-'0']==NULL){
		mimi* node=(mimi*)malloc(sizeof(mimi));
		node->mimimi=0;
		node->mi[0]=node->mi[1]=NULL;
		now->mi[meme[idx]-'0']=node;
	}
	sexy_mimi(now->mi[meme[idx]-'0'],meme,idx+1);
}
int val=1;
int check(mimi* now){
	int ret=now->mimimi;
	for (int i=0;i<2;i++){
		if (now->mi[i]!=NULL){
			ret+=check(now->mi[i]);
		}
	}
	if (ret>now->mimimi&&now->mimimi>0){
		val=0;
	}
	free(now);
	return ret;
}
int main(){
	int cnt=1;
	char rem[20];
	while (1<2){
		mimi* head=(mimi*)malloc(sizeof(mimi));
		head->mimimi=0;
		head->mi[0]=head->mi[1]=NULL;
		int done=0;
		while (1<2){
			if (scanf("%s",rem)==EOF){
				done=1;
				break;
			}
			if (rem[0]=='9'){
				break;
			}
			sexy_mimi(head,rem,0);
		}
		if (done==1)break;
		val=1;
		check(head);
		if (val==1){
			printf ("Set %d is immediately decodable\n",cnt++);
		}
		else{
			printf ("Set %d is not immediately decodable\n",cnt++);
		}
	}
}