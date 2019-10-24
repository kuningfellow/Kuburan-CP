#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node* next;
	struct node* prev;
};
typedef struct node node;
void adpq(node** head, node** tail, int v){
	node* nnode=(node*)malloc(sizeof(node));
	nnode->val=v;
	nnode->next=NULL;
	nnode->prev=NULL;
	if (*head==NULL){
		*head=nnode;
		*tail=nnode;
	}
	else{
		node* ptr=*head;
		int found=0;
		while (ptr!=NULL){
			if (ptr->val>v){
				if (ptr==*head){
					*head=nnode;
				}
				else{
					ptr->prev->next=nnode;
				}
				nnode->prev=ptr->prev;
				ptr->prev=nnode;
				nnode->next=ptr;
				found=1;
				break;
			}
			ptr=ptr->next;
		}
		if (found==0){
			(*tail)->next=nnode;
			nnode->prev=*tail;
			*tail = nnode;
		}
	}
}
int gethead(node** head, node** tail){
	int ret=(*head)->val;
	node* del=(*head);
	(*head)=(*head)->next;
	free(del);
	return ret;
}
int main(){
	while (1<2){
		int n,a;
		node* head=NULL;
		node* tail=NULL;
		scanf("%d",&n);
		if (n==0)break;
		int cost=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			adpq(&head,&tail,a);
		}
		for (int i=0;i<n-1;i++){
			int x=gethead(&head,&tail);
			int y=gethead(&head,&tail);
			cost+=x+y;
			adpq(&head,&tail,x+y);
		}
		gethead(&head,&tail);
		printf ("%d\n",cost);
	}
}