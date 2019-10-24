#include <stdio.h>
#include <stdlib.h>
struct node{
	int val;
	struct node* next;
	struct node* prev;
};
struct tree{
	int val;
	int count;
	struct tree* left;
	struct tree* right;
};
typedef struct node node;
typedef struct tree tree;
void pushback(node** head, node** tail, int v){
	node* nnode=(node*)malloc(sizeof(node));
	nnode->val=v;
	nnode->next=NULL;
	nnode->prev=NULL;
	if (*head==NULL){
		*head=nnode;
		*tail=nnode;
	}
	else{
		(*tail)->next=nnode;
		nnode->prev=(*tail);
		(*tail)=nnode;
	}
}
tree* addtree(tree* head, int v){
	if (head==NULL){
		head = (tree*)malloc(sizeof(tree));
		head->val=v;
		head->count=1;
		head->left=NULL;
		head->right=NULL;
		return head;
	}
	else{
		if (head->val==v){
			head->count=head->count+1;
			return head;
		}
		else if (head->val<v){
			head->left=addtree(head->left,v);
			return head;
		}
		else if (head->val>v){
			head->right=addtree(head->right,v);
			return head;
		}
	}
}
int serc(tree* node, int v){
	if (node==NULL){
		return 0;
	}
	if (node->val==v){
		int ret=node->count;
		node->count=0;
		return ret;
	}
	else if (node->val<v){
		return serc(node->left,v);
	}
	else if (node->val>v){
		return serc(node->right,v);
	}
}
int main(){

	int n;
	node* head=NULL;
	node* tail=NULL;
	tree* root=NULL;
	while (scanf("%d",&n)!=EOF){
		pushback(&head,&tail,n);
		root=addtree(root,n);
	}
	while (head!=NULL){
		tail=head;
		int co=serc(root,head->val);
		if (co>0){
			printf ("%d %d\n",head->val,co);
		}
		head=head->next;
		free(tail);
	}
}