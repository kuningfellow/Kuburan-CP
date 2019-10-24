#include <stdio.h>
#include <stdlib.h>
struct stak{
	char rank;
	char num;
	struct stak* next;
};
struct deck{
	struct deck* next;
	struct deck* prev;
	struct stak* top;
};
typedef struct stak stak;
typedef struct deck deck;
int popdeck(deck* dek){
	stak* kil=dek->top;
	dek->top=dek->top->next;
	free(kil);
	if (dek->top==NULL){
		if (dek->next!=NULL){
			dek->next->prev=dek->prev;
		}
		if (dek->prev!=NULL){
			dek->prev->next=dek->next;
		}
		free(dek);
		return 0;
	}
	return 1;
}
void pushtop(deck* dek, char rank, char num){
	stak* nstak=(stak*)malloc(sizeof(stak));
	nstak->rank=rank;
	nstak->num=num;
	nstak->next=NULL;
	if (dek->top==NULL){
		dek->top=nstak;
	}
	else{
		nstak->next=dek->top;
		dek->top=nstak;
	}
}
void pushdeck(deck** dek, char rank, char num){
	deck* ndeck=(deck*)malloc(sizeof(deck));
	ndeck->next=NULL;
	ndeck->prev=NULL;
	ndeck->top=NULL;
	pushtop(ndeck,rank,num);
	if (*dek==NULL){
		*dek=ndeck;
	}
	else{
		deck* ptr=*dek;
		while (ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=ndeck;
		ndeck->prev=ptr;
	}
}
void printdek(deck* dek){
	stak* ptr=dek->top;
	while (ptr!=NULL){
		printf ("%c %c\n",ptr->rank,ptr->num);
		ptr=ptr->next;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	while (1<2){
		char rem[50];
		scanf("%s",rem);
		if (rem[0]=='#'){
			break;
		}
		else{
			deck* head=NULL;
			pushdeck(&head,rem[0],rem[1]);
			for (int i=1;i<52;i++){
				scanf("%s",rem);
				pushdeck(&head,rem[0],rem[1]);
			}
			int can=1;
			while (can){
				can=0;
				deck* ptr=head;
				ptr=head;
				deck* cback;
				while (ptr!=NULL){
					cback=ptr;
					int cnt=0;
					while (cnt<3&&cback!=NULL){
						cback=cback->prev;
						cnt++;
					}
					if (cback!=NULL&&cnt==3&&(cback->top->rank==ptr->top->rank||
						cback->top->num==ptr->top->num)){
						pushtop(cback,ptr->top->rank,ptr->top->num);
						popdeck(ptr);
						can=1;
						break;
					}
					cback=ptr->prev;
					if (cback!=NULL&&(cback->top->rank==ptr->top->rank||
						cback->top->num==ptr->top->num)){
						pushtop(cback,ptr->top->rank,ptr->top->num);
						popdeck(ptr);
						can=1;
						break;
					}
					ptr=ptr->next;
				}
			}
			int coun=0;
			deck* ptr=head;
			while (ptr!=NULL){
				coun++;
				ptr=ptr->next;
			}
			if (coun==1){
				printf ("1 pile remaining:");
			}
			else printf ("%d piles remaining:",coun);
			ptr=head;
			while (ptr!=NULL){
				int cnt=0;
				deck* kil=ptr;
				ptr=ptr->next;
				while (kil->top!=NULL){
					popdeck(kil);
					cnt++;
				}
				printf (" %d",cnt);
			}
			printf ("\n");
		}
	}
}