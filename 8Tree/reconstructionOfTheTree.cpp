#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 41;
int n, pos;
vector<int> preorder, inorder;

void reconstruction(int left, int right) {
    if(left >= right) {
        return;
    }
    int c = preorder[pos++];
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), c);
    int m = distance(inorder.begin(), it);
    
    reconstruction(left, m);
    reconstruction(m + 1, right);

    printf(" %d", c);

}

int main() {
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        preorder.push_back(tmp);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        inorder.push_back(tmp);
    }

    pos = 0;
    reconstruction(0, preorder.size());
    printf("\n");

    return 0;
}
