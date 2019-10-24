#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* next;
    struct node* prev;
};
typedef struct node node;
void adpq(node** head, node** tail, int val){
    node* nnode=(node*)malloc(sizeof(node));
    nnode->val=val;
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
            if (ptr->val<val){
                if (ptr==*head){
                    *head=nnode;
                }
                else{
                    ptr->prev->next=nnode;
                }
                nnode->prev=ptr->prev;
                nnode->next=ptr;
                ptr->prev=nnode;
                found=1;
                break;
            }
            ptr=ptr->next;
        }
        if (found==0){
            (*tail)->next=nnode;
            nnode->prev=(*tail);
            (*tail)=nnode;
        }
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
void pushtail(node** head, node** tail, int val){
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
void pophead(node** head, node** tail){
    if (*head==NULL){
        return;
    }
    node* die= (*head);
    (*head)=(*head)->next;
    free(die);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    while (scanf("%d",&n)!=EOF){
        node* shead=NULL;
        node* stail=NULL;
        node* qhead=NULL;
        node* qtail=NULL; 
        node* pqhead=NULL;
        node* pqtail=NULL;
        int match[3]={1,1,1};
        for (int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if (a==1){
                pushhead(&shead,&stail,b);
                pushtail(&qhead,&qtail,b);
                adpq(&pqhead,&pqtail,b);
            }
            else{
                if (shead==NULL||b!=shead->val){
                    match[0]=0;
                }
                pophead(&shead,&stail);
                if (qhead==NULL||b!=qhead->val){
                    match[1]=0;
                }
                pophead(&qhead,&qtail);
                if (pqhead==NULL||b!=pqhead->val){
                    match[2]=0;
                }
                pophead(&pqhead,&pqtail);
            }
        }
        int sum=0;
        int ans=0;
        for (int i=0;i<3;i++){
            sum+=match[i];
            if (match[i]>0)ans=i;
        }
        if (sum==0){
            printf ("impossible\n");
        }
        else if (sum>1){
            printf ("not sure\n");
        }
        else{
            if (ans==0)printf ("stack\n");
            else if (ans==1)printf ("queue\n");
            else if (ans==2)printf ("priority queue\n");
        }
        while (shead!=NULL){
            stail=shead;
            shead=shead->next;
            free(stail);
        }
        while (qhead!=NULL){
            qtail=qhead;
            qhead=qhead->next;
            free(qtail);
        }
        while (pqhead!=NULL){
            pqtail=pqhead;
            pqhead=pqhead->next;
            free(pqtail);
        }
    }
}