#include <stdio.h>
#include <stdlib.h>
struct sta{
	int val;
	struct sta* up;
	struct sta* down;
};
typedef struct sta sta;
void push(sta** head, int val, sta** bot){
	sta* nnode=(sta*)malloc(sizeof(sta));
	nnode->up=NULL;
	nnode->val=val;
	nnode->down=*head;
	if (*head==NULL){;
		*bot=nnode;
	}
	else{
		(*head)->up=nnode;
	}
	*head=nnode;
}
void transf(sta** head1, sta** bot1, sta** head2, sta** bot2){
	if (*head2==NULL)return;
	if (*head1!=NULL)
		(*head1)->up=*bot2;
	if (*head1==NULL){
		(*bot1)=*bot2;
	}
	(*bot2)->down=*head1;
	*head1=*head2;
	*head2=NULL;
	*bot2=NULL;
}
void pop(sta** head){
	if (*head==NULL){
		printf ("EMPTY\n");
	}
	else{
		printf ("%d\n",(*head)->val);
		sta* del=*head;
		*head=(*head)->down;
		free(del);
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n,q;
		scanf("%d%d",&n,&q);
		sta* tops[n];
		sta* bots[n];
		for (int i=0;i<n;i++){
			tops[i]=NULL;
			bots[i]=NULL;
		}
		for (int i=0;i<q;i++){
			int a;
			scanf("%d",&a);
			if (a==1){
				int b,c;
				scanf("%d%d",&b,&c);
				push(&tops[b-1],c,&bots[b-1]);
			}
			else if (a==2){
				int b;
				scanf("%d",&b);
				pop(&tops[b-1]);
			}
			else if (a==3){
				int b,c;
				scanf("%d%d",&b,&c);
				transf(&tops[b-1],&bots[b-1],&tops[c-1],&bots[c-1]);
			}
		}
	}
}