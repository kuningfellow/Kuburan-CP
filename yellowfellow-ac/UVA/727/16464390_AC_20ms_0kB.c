#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order(char a){
    if ( a == '(' || a == ')' ){
        return 3;
    }
    else if ( a == '*' || a == '/' ){
        return 2;
    }
    else if ( a == '+' || a == '-' ){
        return 1;
    }
}

int digit(char a){
    if ( a >= '0' && a <= '9' ){
        return 1;
    }
    return 0;
}

struct node{
    char value;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

void push_top( node **head , char in ){

    node *new_node = (node*) malloc ( sizeof(node) );

    new_node->value = in;
    new_node->next = NULL;
    new_node->prev = NULL;

    if ( *head == NULL ){
        *head = new_node;
    }
    else{
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node;
    }
}

void push_back( node **head , char in ){

    node *new_node = (node*) malloc ( sizeof(node) );

    new_node->value = in;
    new_node->next = NULL;
    new_node->prev = NULL;

    if ( *head == NULL ){
        *head = new_node;
    }
    else{
        node *node_iterator = *head;
        while ( node_iterator->next != NULL ){
            node_iterator = node_iterator->next;
        }
        new_node->prev = node_iterator;
        node_iterator->next = new_node;
    }
}

int empty( node **head ){
    if ( *head == NULL ){
        return 1;
    }
    return 0;
}

char top( node **head ){
    return (*head)->value;
}

int pop( node **head ){
    node *del = *head;
    *head = (*head)->next;
    free(del);
}

int main(){

    int tc;
    scanf("%d", &tc );
    getchar();
    getchar();
    while ( tc-- ){

        node *out_queue = NULL;
        node *op_stack = NULL;

        char rem[2];
        rem[0] = '\n';

        int first = 1;

        while ( 1 < 2 ){

            int br=0;

            if ( first == 1 ){
                while ( rem[0] == '\n' ){
                    rem[0] = getchar();
                    if ( rem[0] == EOF ){
                        br=1;
                        break;
                    }
                }
                getchar();
                first=0;
            }
            else{
                rem[0] = getchar();
                if ( rem[0] == '\n' ){
                    break;
                }
                if ( rem[0] == EOF )
                    break;
                getchar();
            }
            if (br==1)break;

            if ( digit( rem[0] ) ){
                push_back( &out_queue , rem[0] );
            }
            else{
                if ( order( rem[0] ) != 3 ){
                    while ( !empty( &op_stack ) &&
                            order( rem[0] ) <= order( top( &op_stack ) ) &&
                            top(&op_stack) != '(' ){
                        push_back( &out_queue , top( &op_stack ) );
                        pop( &op_stack );
                    }
                    push_top( &op_stack , rem[0] );
                }
                if ( rem[0] == '(' ){
                    push_top( &op_stack , rem[0] );
                }
                if ( rem[0] == ')' ){
                    while ( top( &op_stack ) != '(' ){
                        push_back( &out_queue , top( &op_stack ) );
                        pop( &op_stack );
                    }
                    pop( &op_stack );
                }
            }
        }
        while ( !empty( &op_stack ) ){
            push_back( &out_queue , top( &op_stack ) );
            pop( &op_stack );
        }
        while ( !empty( &out_queue ) ){
            printf ("%c", top( &out_queue ) );
            pop( &out_queue );
        }
        printf ("\n");
        if (tc!=0)printf ("\n");

    }
return 0;
}