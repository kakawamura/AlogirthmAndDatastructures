#include <iostream>
#include <stdio.h>

using namespace std;

int n, q;
int a[20];

bool solve(int m, int i) {
    if(m == 0) {
        return true;
    } else if(m < 0) {
        return false;
    } else if(i >=n) {
        return false;
    }

    bool res = solve(m, i+1) || solve(m - a[i], i+1);

    return res;
}

int main() {
    int m;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d", &m);

        if(solve(m, 0)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
