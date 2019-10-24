#include<stdio.h>
#include<string.h>
int coun[1000005];
int ass[1000005];
int av[1000005];
struct llis {
	llis* next;
	llis* prev;
	int val;
};
class queue{
public:
	llis* head;
	llis* tail;
	queue() {
		head = NULL;
		tail = NULL;
	}
	void push(int x) {
		llis* nnode = new llis;
		nnode->next = NULL;
		if (head != NULL) {
			tail->next = nnode;
		}
		else {
			head = nnode;
		}
		nnode->prev = tail;
		nnode->val = x;
		tail = nnode;
	}
	void pop() {
		llis* dnode = head;
		head = head->next;
		if (head != NULL) head->prev = NULL;
		delete(dnode);
	}
	int front() {
		return head->val;
	}
};
int main(){
	int kas=1;
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		queue sta[n];
		for (int i = 0; i < 1000005; i++) {
			coun[i] = ass[i] = av[i] = 0;
		}
		queue qoq;
		for (int i=0;i<n;i++){
			int a,b;
			scanf("%d",&a);
			for (int j=0;j<a;j++){
				scanf("%d",&b);
				ass[b]=i;
			}
		}
		char rem[500];
		int x;
		printf ("Scenario #%d\n",kas++);
		while (1<2){
			scanf("%s",rem);
			if (!strcmp(rem,"STOP"))break;
			else if (!strcmp(rem,"ENQUEUE")){
				scanf("%d",&x);
				if (coun[x]==0){
					sta[ass[x]].push(x);
				}
				if (av[ass[x]]==0){
					qoq.push(ass[x]);
				}
				av[ass[x]]++;
				coun[x]++;
			}
			else if (!strcmp(rem,"DEQUEUE")){
				int x=qoq.front();
				av[x]--;
				if (av[x]==0){
					qoq.pop();
				}
				int prin=sta[x].front();
				coun[prin]--;
				if (coun[prin]==0){
					sta[x].pop();
				}
				printf ("%d\n",prin);
			}
		}
		printf ("\n");
	}
}