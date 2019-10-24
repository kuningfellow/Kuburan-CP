#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char c;
    struct node* next;
    struct node* prev;
};
typedef struct node node;
void add(node** cursor, node** head, node**tail, char c){
    node *nnode = (node*)malloc(sizeof(node));
    nnode->c=c;
    nnode->next=NULL;
    nnode->prev=NULL;
    if (*head==NULL){
        *head=(node*)malloc(sizeof(node));
        (*head)->c='0';
        *tail=nnode;
        (*head)->next=*tail;
        (*head)->prev=NULL;
        (*tail)->prev=(*head);
        *cursor=*tail;
    }
    else{
        if ((*cursor)->next!=NULL){
            (*cursor)->next->prev=nnode;
        }
        else{
            *tail=nnode;
        }
        nnode->next=(*cursor)->next;
        nnode->prev=(*cursor);
        (*cursor)->next=nnode;
        (*cursor)=(*cursor)->next;
    }
}
char rem[100005];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    while (scanf("%s",rem)!=EOF){
        node* head=NULL;
        node* tail=NULL;
        node* cursor=NULL;
        int l=strlen(rem);
        for (int i=0;i<l;i++){
            if (rem[i]=='['){
                cursor=head;
                continue;
            }
            if (rem[i]==']'){
                cursor=tail;
                continue;
            }
            add(&cursor,&head,&tail,rem[i]);
        }
        int fir=1;
        while (head!=NULL){
            cursor=head;
            if (fir==0)
                printf ("%c",head->c);
            fir=0;
            head=head->next;
            free(cursor);
        }
        printf ("\n");
    }
}