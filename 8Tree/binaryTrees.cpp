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

int getDepth(Node nodes[], int id) {
    int depth = 0;
    while(nodes[id].parent != -1) {
        id = nodes[id].parent;
        depth++;
    }
    return depth;
}

int getHeight(Node nodes[], int id, int height) {
    int left = height, right = height;
    if(nodes[id].left != -1) {
        left = getHeight(nodes, nodes[id].left, height + 1);
    }
    if(nodes[id].right != -1) {
        right = getHeight(nodes, nodes[id].right , height + 1);
    }
    return max(left, right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Node *nodes = new Node[n+1];
    int sibling[MAX];
    int degree[MAX];
    int depth[MAX];

    //initialize sibling
    for(int i = 0; i < n; i++) {
        sibling[i] = -1;
        degree[i] = 0;
        depth[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        nodes[id].id = id;
        scanf("%d", &nodes[id].left);
        if(nodes[id].left != -1) {
            nodes[nodes[id].left].parent = id;
            degree[id]++;
        }

        scanf("%d", &nodes[id].right);
        if(nodes[id].right != -1) {
            nodes[nodes[id].right].parent = id;
            degree[id]++;
        }

        if(nodes[id].left != -1 && nodes[id].right != -1) {
            sibling[nodes[id].left] = nodes[id].right;
            sibling[nodes[id].right] = nodes[id].left;
        }

    }

    for(int i = 0; i < n; i++) {
        printf("node %d: ", i);
        printf("parent = %d, sibling = %d, degree = %d, ", nodes[i].parent, sibling[i], degree[i]);
        printf("depth = %d, height = %d, ", getDepth(nodes, i), getHeight(nodes, i, 0));
        char *type;

        if(nodes[i].parent == -1) {
            type = "root";
        } else if(nodes[i].left == -1 && nodes[i].right == -1) {
            type = "leaf";
        } else {
            type = "internal node";
        }
        printf("%s\n", type);
    } 
    
    return 0;
}
