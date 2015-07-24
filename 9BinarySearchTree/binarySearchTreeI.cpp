#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;
void insert(int val) {
    Node *x = root;
    Node *y = NIL;
    Node *node;

    node = (Node *)malloc(sizeof(Node));
    node->key = val;
    node->left = NIL;
    node->right = NIL;
    while(x != NIL) {
        y = x;
        if(node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->parent = y;

    if(y == NIL) {//if y is NIL it means its the first inserted element
        root = node;
    } else {
        if(node->key < y->key) {
            y->left = node;
        } else {
            y->right = node;
        }
    }
}

void inorder(Node *u) {
    if(u == NIL) {
        return;
    }
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u) {
    if(u == NIL) {
        return;
    }
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int n;
    scanf("%d", &n);

    char com[10];
    int val;
    for(int i = 0; i < n; i++) {
        scanf("%s", com);
        if(strcmp(com, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if(strcmp(com, "print") == 0) {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return 0;
}

