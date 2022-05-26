#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

node *dequeue(linkedList *ll){
    node *poppedNode = removeAtHead(ll);
    if((poppedNode -> person) -> type == robot){printf("You are a robot and will not be allowed service\n"); return NULL;}
    return poppedNode;
}

char *peek(linkedList *ll){
    node *first = getFirstNode(ll);
    return (first -> person) -> name;
}

void enqueue(linkedList *ll, Person *p){
    if(p -> type == robot){printf("You are a robot and will not be allowed service\n"); return;}
    insertAtTail(ll, p);
    return;
}
