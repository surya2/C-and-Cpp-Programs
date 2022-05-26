#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

//typedef struct {char **schedule } Schedule;
enum person_type { student, instructor, person, robot };
typedef struct {
    enum person_type type;
    char *name;
    int age;
} Person;

typedef struct node_s {
    void *person;
    struct node_s *prev;
    struct node_s *next;
} node;

typedef struct ll_s {
    node *ll_node;
    int size;
    node *(*getFirstNode)(struct ll_s *);
    node *(*getLastNode)(struct ll_s *);

    //node *(*removeAt)(struct ll_s *, int);
    node *(*removeAtHead)(struct ll_s *);
    node *(*removeAtTail)(struct ll_s *);
    void (*removeAt)(struct ll_s *, int);

    //void (*insert)(struct ll_s *, Person *p, int, int);
    void (*insertAtHead)(struct ll_s *, Person *);
    void (*insertAtTail)(struct ll_s *, Person *);
    void (*insert)(struct ll_s *, Person *p, int, int);

    node *(*find)(struct ll_s *, char *);
    void (*show)(struct ll_s *);

} linkedList;

void removeAt(linkedList *ll, int index);
node *removeAtHead(linkedList *ll);
node *removeAtTail(linkedList *ll);

void insert(linkedList *ll, Person *p, int index, int before);
void insertAtHead(linkedList *ll, Person *p);
void insertAtTail(linkedList *ll, Person *p);

node *getFirstNode(linkedList *ll);
node *getLastNode(linkedList *ll);

node *find(linkedList *ll, char *nameToFind);
void show(linkedList *ll);
//Person *getPerson(linkedList *ll, char *name);

#endif


