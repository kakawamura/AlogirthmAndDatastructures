#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

const int MAX = 100000;
struct Node {
    int id, parent, leftChild, rightSibling;
    Node() {
        this->id = -1;
        this->parent = -1;
        this->leftChild = -1;
        this->rightSibling = -1;
    }
};

int getDepth(Node trees[], int key) {
    int depth = 0;
    while(trees[key].parent != -1) {
        key = trees[key].parent;
        depth++;
    }

    return depth;
}

void printNodes(Node trees[], Node node, int id) {
    printf("node %d: parent = %d, ", id, node.parent);;
    printf("depth = %d, ", getDepth(trees, id)); 

    if(node.parent == -1) {
        printf("root, ");
    } else if(node.leftChild == -1) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }

    int right = node.leftChild;
    printf("[");
    while(right != -1) {
        printf("%d", right);
        right = trees[right].rightSibling;
        if(right != -1) {
            printf(", ");
        } else {
            break;
        }
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Node *trees = new Node[1+n];

    for(int i = 0; i < n; i++) {
        int id, k;
        scanf("%d", &id);
        scanf("%d", &k);
        trees[id].id = id;
        for(int j = 0; j < k; j++) {
            int tmp;
            int leftChild;
            scanf("%d", &tmp);
            if(j == 0) {
                trees[id].leftChild = tmp;
                trees[tmp].parent = id;
                leftChild = tmp;
            } else { //right siblings
                trees[tmp].parent = id;
                trees[leftChild].rightSibling = tmp;
                leftChild = tmp;
            }
        }
    }

    //map<int, Node>:: iterator it;

    //setDepth(trees, root, 0);
    for(int i = 0; i < n; i++) {
        printNodes(trees, trees[i], i);
    }
    
    return 0;
}
