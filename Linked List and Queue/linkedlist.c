#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "queue.c"

typedef struct { enum person_type type; char *name; int age; char *major; char **courses; } Student;
typedef struct { enum person_type type; char *name; int age; char *title; char **courses; } Instructor;
typedef struct { enum person_type type; char *name; int years; char *make; } Robot;

node *getFirstNode(linkedList *ll){
    node *cur_node = ll -> ll_node;
    if(!cur_node) return NULL;
    while(cur_node -> prev){
        cur_node = cur_node -> prev;
    }
    return cur_node;
}

node *getLastNode(linkedList *ll){
    node *cur_node = ll -> ll_node;
    if(!cur_node) return NULL;
    while(cur_node -> next){
        cur_node = cur_node -> next;
    }
    return cur_node;
}

node *removeAtHead(linkedList *ll){
    node *first = getFirstNode(ll);
    ll -> ll_node = first -> next;
    (first -> next) -> prev = NULL;
    //free(first);  //Free in caller function because a queue pop method may want the data in the first node
    ll -> size -= 1;  //Just added
    return first;
}

node *removeAtTail(linkedList *ll){
    node *last = getLastNode(ll);
    ll -> ll_node = last -> prev;
    (last -> prev) -> next = NULL;
    //free(last);
    ll -> size -= 1;  //-= size just added
    return last;
}

void removeAt(linkedList *ll, int index){
    node *cur_node = getFirstNode(ll);
    int i = 0;
    if(!cur_node) return;
    while(cur_node && i<index){
        cur_node = cur_node -> next;
        if(cur_node -> next) i+=1;
        else break;
    }
    if(ll -> size == 1){free(cur_node); return;}
    (cur_node -> next) -> prev = cur_node -> prev;
    (cur_node -> prev) -> next = cur_node -> next;
    free(cur_node);
    return;
}

void insertAtHead(linkedList *ll, Person *p){
    node *first = getFirstNode(ll);
    node *new_node = (node *)malloc(sizeof(node));
    new_node -> person = p; new_node -> prev = NULL; new_node -> next = NULL;  //Need NULL asignments because malloc does not initialize memory
    if(!first){ ll -> ll_node = new_node; return;}
    first -> prev = new_node;
    new_node -> next = first;
    ll -> ll_node = new_node;
    ll -> size += 1;
    return;
}
void insertAtTail(linkedList *ll, Person *p){
    node *last = getLastNode(ll);
    node *new_node = (node *)malloc(sizeof(node));
    new_node -> person = p; new_node -> prev = NULL; new_node -> next = NULL;
    if(!last){ ll -> ll_node = new_node; return;}
    last -> next = new_node;
    new_node -> prev = last;
    ll -> ll_node = new_node;
    ll -> size += 1;
    return;
}
void insert(linkedList *ll, Person *p, int index, int before){
    node *cur_node = getFirstNode(ll);
    node *new_node = (node *)malloc(sizeof(node));
    new_node -> person = p; new_node -> prev = NULL; new_node -> next = NULL;

    if(!cur_node){ ll -> ll_node = new_node; return;}
    int i = 0;
    while(i < index && cur_node -> next) cur_node = cur_node -> next;
    if(i < index-1) return;
    else if(before){
        new_node -> prev = cur_node -> prev;
        (cur_node -> prev) -> next = new_node;
        cur_node -> prev = new_node;
        new_node -> next = cur_node;
    }
    else if(!before){
        new_node -> next = cur_node -> next;
        (cur_node -> next) -> prev = new_node;
        cur_node -> next = new_node;
        new_node -> prev = cur_node;
    }
    return;
}

node *find(linkedList *ll, char *nameToFind){
    node *cur_node = getFirstNode(ll);
    while(cur_node){
        if(!strcmp((cur_node -> person) -> name, nameToFind)) return cur_node;
        if(cur_node -> next) cur_node = cur_node -> next;
    }
    return NULL;
}

void show(linkedList *ll){
    node *cur_node = getFirstNode(ll);
    while(cur_node){
        if((cur_node -> person) -> type == student) printf("Name: %s Age: %d Major: %s\n", (cur_node -> person) -> name, (cur_node -> person) -> age, ((Student *)cur_node -> person) -> major);
        else if((cur_node -> person) -> type == instructor) printf("Name: %s %s\n", ((Instructor *)cur_node -> person) -> title, (cur_node -> person) -> name);
        else printf("Name: %s Age: %d\n", (cur_node -> person) -> name, (cur_node -> person) -> age);

        if(cur_node -> next) cur_node = cur_node -> next;
        else break;
    }
    return;
}

int main(){
    const char *clist1[] = { "CS 3100 Data Structures and Algo", "APMA Probability", "CS Software Dev Essentials", NULL };
    const char *clist2[] = { "CS Applied ML", "CSE Computer Systems and Architecture", NULL};
    Student student1 = {student, "Surya", 19, "Computer Science", clist1};
    Instructor instructor1 = {instructor, "Muga", 0, "Dr.", clist2};
    Person person1 = {person, "Markcuhs", 49};
    Robot robot1 = {robot, "dd3", 2, "t23"};

    linkedList list = { NULL, 0, getFirstNode, getLastNode, removeAtHead, removeAtTail, removeAt, insertAtHead, insertAtTail, insert, find, show };
    list.insertAtHead(&list, (Person *)&student1);
    list.insertAtTail(&list, (Person *)&instructor1);
    list.insert(&list, (Person *)&person1, 1, 1);
    list.insertAtHead(&list, (Person *)&robot1);
    list.show(&list);
    dequeue(&list);
}