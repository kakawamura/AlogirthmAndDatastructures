#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int key;
    Node *prev, *next;
};

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    x->prev = nil;

    nil->next->prev = x;
    nil->next = x;
}

Node* listSearch(int key) {
    Node *cur = nil->next; //the first node
    while(cur != nil && cur->key != key) {
        cur = cur->next;
    }

    return cur;
}

void deleteNode(Node *t) {
    if(t == nil) {
        return;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;

    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
}
void printNodes() {
    Node *cur = nil->next; //the first node
    printf("%d", cur->key);
    cur = cur->next;
    while(cur != nil) { 
        printf(" %d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    init();

    char com[20];
    int key;
    for(int i = 0; i < n; i++) {
        scanf("%s", com);
        if(strcmp(com, "insert") == 0) {
            scanf("%d", &key);
            insert(key);
        } else if(strcmp(com, "delete") == 0) {
            scanf("%d", &key);
            deleteKey(key);
        }  else if(strcmp(com, "deleteFirst") == 0) {
            deleteFirst();
        }  else if(strcmp(com, "deleteLast") == 0) {
            deleteLast();
        } 
    }
    printNodes();

    return 0;
}
