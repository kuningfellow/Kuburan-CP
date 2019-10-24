#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* next;
    struct node* prev;
};
typedef struct node node;
void pushback(node** head, node** tail, int val){
    node* nnode=(node*)malloc(sizeof(node));
    nnode->val=val;
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
void pushhead(node** head, node** tail, int val){
    node* nnode=(node*)malloc(sizeof(node));
    nnode->val=val;
    nnode->next=NULL;
    nnode->prev=NULL;
    if (*head==NULL){
        *head=nnode;
        *tail=nnode;
    }
    else{
        (*head)->prev=nnode;
        nnode->next=(*head);
        (*head)=nnode;
    }
}
int notempty(node** head, node** tail){
    if (*head==NULL){
        return 0;
    }
    return 1;
}
int gethead(node** head, node** tail){
    if (*head==NULL){
        return -1;
    }
    return (*head)->val;
}
void pophead(node** head, node** tail){
    node* del=*head;
    (*head)=(*head)->next;
    if (*head!=NULL){
        (*head)->prev=NULL;
    }
    free(del);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    while (1<2){
        int n;
        scanf("%d",&n);
        if (n==0)break;
        node* head[2]={NULL,NULL};
        node* tail[2]={NULL,NULL};
        node* hhead=NULL;
        node* ttail=NULL;
        int cur=0;
        int one=1;
        while (1<2){
            int a;
            scanf("%d",&a);
            if (a==0)break;
            else{
                int mat[n];
                mat[0]=a;
                for (int i=1;i<n;i++){
                    scanf("%d",&mat[i]);
                }
                int fil=0;
                cur=0;
                while (head[cur]!=NULL){
                    tail[cur]=head[cur];
                    head[cur]=head[cur]->next;
                    free(tail[cur]);
                }
                cur=1;
                while (head[cur]!=NULL){
                    tail[cur]=head[cur];
                    head[cur]=head[cur]->next;
                    free(tail[cur]);
                }
                for (int i=1;i<=n;i++){
                    pushback(&head[0],&head[1],i);
                }
                head[cur]=NULL;
                tail[cur]=NULL;
                while (fil<n&&notempty(&head[cur^1],&tail[cur^1])){
                    while (notempty(&head[cur^1],&tail[cur^1])&&
                        gethead(&hhead,&ttail)!=mat[fil]){
                        pushhead(&hhead,&ttail,gethead(&head[cur^1],&tail[cur^1]));
                        pophead(&head[cur^1],&tail[cur^1]);
                    }
                    if (gethead(&hhead,&ttail)==mat[fil]){
                        pushback(&head[cur],&tail[cur],gethead(&hhead,&ttail));
                        pophead(&hhead,&ttail);
                        fil++;
                    }
                }
                if (fil!=n){
                    while (notempty(&hhead,&ttail)){
                        pushback(&head[cur],&tail[cur],gethead(&hhead,&ttail));
                        pophead(&hhead,&ttail);
                    }
                }
                int yes=1;
                fil=0;
                node* ptr=head[cur];
                while (ptr!=NULL){
                    if (ptr->val!=mat[fil]){
                        yes=0;
                        break;
                    }
                    fil++;
                    ptr=ptr->next;
                }
                if (yes==1){
                    printf ("Yes\n");
                }
                else printf ("No\n");
            }
        }
        printf ("\n");
        while (head[0]!=NULL){
            tail[0]=head[0];
            head[0]=head[0]->next;
            free(tail[0]);
        }
        while (head[1]!=NULL){
            tail[1]=head[1];
            head[1]=head[1]->next;
            free(tail[1]);
        }
    }
}