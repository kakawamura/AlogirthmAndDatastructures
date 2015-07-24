#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int MAX = 26;

struct Node {
    int id, parent, left, right;
    Node() {
        this->id = -1;
        this->parent = -1;
        this->left = -1;
        this->right = -1;
    }
};

//根節点、左部分木、右部分木
void preorder(Node nodes[], int r) {
    if(r == -1) {
        return;
    }
    printf(" %d", r); 
    preorder(nodes, nodes[r].left);
    preorder(nodes, nodes[r].right);
}

void inorder(Node nodes[], int r) {
    if(r == -1) {
        return;
    }
    inorder(nodes, nodes[r].left);
    printf(" %d", r); 
    inorder(nodes, nodes[r].right);
}

void postorder(Node nodes[], int r) {
    if(r == -1) {
        return;
    }
    postorder(nodes, nodes[r].left);
    postorder(nodes, nodes[r].right);
    printf(" %d", r); 
}

int main() {
    int n;
    scanf("%d", &n);
    
    Node *nodes = new Node[n+1];

    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        nodes[id].id = id;
        scanf("%d", &nodes[id].left);
        if(nodes[id].left != -1) {
            nodes[nodes[id].left].parent = id;
        }

        scanf("%d", &nodes[id].right);
        if(nodes[id].right != -1) {
            nodes[nodes[id].right].parent = id;
        }

    }
    int r;
    for(int i = 0; i < n; i++) {
        if(nodes[i].parent == -1) {
            r = i;
            break;
        }
    }
    printf("Preorder\n");
    preorder(nodes, r);
    printf("\n");
    printf("Inorder\n");
    inorder(nodes, r);
    printf("\n");
    printf("Postorder\n");
    postorder(nodes, r);
    printf("\n");

    return 0;
}
