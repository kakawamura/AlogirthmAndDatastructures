#include <iostream>
#include <stdio.h>

using namespace std;

bool linearSearch(int S[], int n, int search) {
    int i = 0;
    while(S[i] != search) {
        i++;
        if(i == n) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, S[10000];
    int q;
    int ans = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    int search;
    for(int i = 0; i < q; i++) {
        scanf("%d", &search);
        if(linearSearch(S, n, search)) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
